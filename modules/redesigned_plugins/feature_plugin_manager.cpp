/**************************************************************************/
/*  feature_plugin_manager.cpp                                            */
/**************************************************************************/

#include "feature_plugin_manager.h"

#include "core/object/class_db.h"
#include "core/variant/utility_functions.h"

FeaturePluginManager *FeaturePluginManager::singleton = nullptr;

FeaturePluginManager *FeaturePluginManager::get_singleton() {
	return singleton;
}

FeaturePluginManager::FeaturePluginManager() {
	ERR_FAIL_COND_MSG(singleton != nullptr, "Only one FeaturePluginManager may exist.");
	singleton = this;
}

FeaturePluginManager::~FeaturePluginManager() {
	if (singleton == this) {
		singleton = nullptr;
	}
}

void FeaturePluginManager::_bind_methods() {
	ClassDB::bind_method(D_METHOD("register_plugin", "plugin"), &FeaturePluginManager::register_plugin);
	ClassDB::bind_method(D_METHOD("unregister_plugin", "plugin_id"), &FeaturePluginManager::unregister_plugin);
	ClassDB::bind_method(D_METHOD("has_plugin", "plugin_id"), &FeaturePluginManager::has_plugin);
	ClassDB::bind_method(D_METHOD("get_plugin", "plugin_id"), &FeaturePluginManager::get_plugin);
	ClassDB::bind_method(D_METHOD("get_plugin_ids"), &FeaturePluginManager::get_plugin_ids);
	ClassDB::bind_method(D_METHOD("get_plugins"), &FeaturePluginManager::get_plugins);
	ClassDB::bind_method(D_METHOD("enable_plugin", "plugin_id"), &FeaturePluginManager::enable_plugin);
	ClassDB::bind_method(D_METHOD("disable_plugin", "plugin_id"), &FeaturePluginManager::disable_plugin);
	ClassDB::bind_method(D_METHOD("is_plugin_enabled", "plugin_id"), &FeaturePluginManager::is_plugin_enabled);
	ClassDB::bind_method(D_METHOD("initialize_plugins"), &FeaturePluginManager::initialize_plugins);
	ClassDB::bind_method(D_METHOD("shutdown_plugins"), &FeaturePluginManager::shutdown_plugins);
	ClassDB::bind_method(D_METHOD("process_plugins", "delta"), &FeaturePluginManager::process_plugins);
	ClassDB::bind_method(D_METHOD("dispatch_event", "event", "payload"), &FeaturePluginManager::dispatch_event);

	ADD_SIGNAL(MethodInfo("plugin_registered", PropertyInfo(Variant::STRING_NAME, "plugin_id")));
	ADD_SIGNAL(MethodInfo("plugin_unregistered", PropertyInfo(Variant::STRING_NAME, "plugin_id")));
	ADD_SIGNAL(MethodInfo("plugin_enabled", PropertyInfo(Variant::STRING_NAME, "plugin_id")));
	ADD_SIGNAL(MethodInfo("plugin_disabled", PropertyInfo(Variant::STRING_NAME, "plugin_id")));
	ADD_SIGNAL(MethodInfo("plugin_error", PropertyInfo(Variant::STRING_NAME, "plugin_id"), PropertyInfo(Variant::STRING, "method")));
}

void FeaturePluginManager::sort_plugins() {
	for (int i = 1; i < plugins.size(); i++) {
		Ref<FeaturePlugin> value = plugins[i];
		int j = i - 1;
		while (j >= 0 && plugins[j]->get_priority() < value->get_priority()) {
			plugins.write[j + 1] = plugins[j];
			j--;
		}
		plugins.write[j + 1] = value;
	}
}

void FeaturePluginManager::invoke_lifecycle(const Ref<FeaturePlugin> &p_plugin, const StringName &p_method) {
	if (p_plugin.is_null()) {
		return;
	}
	if (!p_plugin->is_enabled() && p_method != "shutdown") {
		return;
	}
	p_plugin->call(p_method);
}

bool FeaturePluginManager::register_plugin(const Ref<FeaturePlugin> &p_plugin) {
	ERR_FAIL_COND_V_MSG(p_plugin.is_null(), false, "Cannot register a null feature plugin.");

	const StringName id = p_plugin->get_plugin_id();
	ERR_FAIL_COND_V_MSG(id.is_empty(), false, "Feature plugins require a non-empty plugin_id.");
	ERR_FAIL_COND_V_MSG(plugin_map.has(id), false, vformat("A feature plugin with id '%s' is already registered.", String(id)));

	plugins.push_back(p_plugin);
	plugin_map.insert(id, p_plugin);
	sort_plugins();
	emit_signal(SNAME("plugin_registered"), id);
	return true;
}

bool FeaturePluginManager::unregister_plugin(const StringName &p_plugin_id) {
	Ref<FeaturePlugin> plugin = plugin_map.get(p_plugin_id);
	if (plugin.is_null()) {
		return false;
	}

	invoke_lifecycle(plugin, SNAME("shutdown"));
	plugin_map.erase(p_plugin_id);
	for (int i = 0; i < plugins.size(); i++) {
		if (plugins[i].is_valid() && plugins[i]->get_plugin_id() == p_plugin_id) {
			plugins.remove_at(i);
			break;
		}
	}
	emit_signal(SNAME("plugin_unregistered"), p_plugin_id);
	return true;
}

bool FeaturePluginManager::has_plugin(const StringName &p_plugin_id) const {
	return plugin_map.has(p_plugin_id);
}

Ref<FeaturePlugin> FeaturePluginManager::get_plugin(const StringName &p_plugin_id) const {
	return plugin_map.get(p_plugin_id);
}

Array FeaturePluginManager::get_plugin_ids() const {
	Array result;
	for (const Ref<FeaturePlugin> &plugin : plugins) {
		if (plugin.is_valid()) {
			result.push_back(plugin->get_plugin_id());
		}
	}
	return result;
}

Array FeaturePluginManager::get_plugins() const {
	Array result;
	for (const Ref<FeaturePlugin> &plugin : plugins) {
		if (plugin.is_valid()) {
			result.push_back(plugin);
		}
	}
	return result;
}

bool FeaturePluginManager::enable_plugin(const StringName &p_plugin_id) {
	Ref<FeaturePlugin> plugin = plugin_map.get(p_plugin_id);
	if (plugin.is_null()) {
		return false;
	}
	if (plugin->is_enabled()) {
		return true;
	}
	plugin->set_enabled(true);
	invoke_lifecycle(plugin, SNAME("initialize"));
	emit_signal(SNAME("plugin_enabled"), p_plugin_id);
	return true;
}

bool FeaturePluginManager::disable_plugin(const StringName &p_plugin_id) {
	Ref<FeaturePlugin> plugin = plugin_map.get(p_plugin_id);
	if (plugin.is_null()) {
		return false;
	}
	if (!plugin->is_enabled()) {
		return true;
	}
	invoke_lifecycle(plugin, SNAME("shutdown"));
	plugin->set_enabled(false);
	emit_signal(SNAME("plugin_disabled"), p_plugin_id);
	return true;
}

bool FeaturePluginManager::is_plugin_enabled(const StringName &p_plugin_id) const {
	Ref<FeaturePlugin> plugin = plugin_map.get(p_plugin_id);
	return plugin.is_valid() && plugin->is_enabled();
}

void FeaturePluginManager::initialize_plugins() {
	for (const Ref<FeaturePlugin> &plugin : plugins) {
		invoke_lifecycle(plugin, SNAME("initialize"));
	}
}

void FeaturePluginManager::shutdown_plugins() {
	for (int i = plugins.size() - 1; i >= 0; i--) {
		invoke_lifecycle(plugins[i], SNAME("shutdown"));
	}
}

void FeaturePluginManager::process_plugins(double p_delta) {
	if (processing) {
		return;
	}
	processing = true;
	for (const Ref<FeaturePlugin> &plugin : plugins) {
		if (plugin.is_valid() && plugin->is_enabled()) {
			plugin->call(SNAME("process"), p_delta);
		}
	}
	processing = false;
}

void FeaturePluginManager::dispatch_event(const StringName &p_event, const Dictionary &p_payload) {
	for (const Ref<FeaturePlugin> &plugin : plugins) {
		if (plugin.is_valid() && plugin->is_enabled()) {
			plugin->call(SNAME("on_feature_event"), p_event, p_payload);
		}
	}
}
