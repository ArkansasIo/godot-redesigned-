/**************************************************************************/
/*  feature_plugin_manager.h                                              */
/**************************************************************************/

#pragma once

#include "core/object/object.h"
#include "core/templates/vector.h"

#include "feature_plugin.h"

class FeaturePluginManager : public Object {
	GDCLASS(FeaturePluginManager, Object);

	static FeaturePluginManager *singleton;
	Vector<Ref<FeaturePlugin>> plugins;
	HashMap<StringName, Ref<FeaturePlugin>> plugin_map;
	bool processing = false;

	void sort_plugins();
	void invoke_lifecycle(const Ref<FeaturePlugin> &p_plugin, const StringName &p_method);

protected:
	static void _bind_methods();

public:
	static FeaturePluginManager *get_singleton();

	bool register_plugin(const Ref<FeaturePlugin> &p_plugin);
	bool unregister_plugin(const StringName &p_plugin_id);
	bool has_plugin(const StringName &p_plugin_id) const;
	Ref<FeaturePlugin> get_plugin(const StringName &p_plugin_id) const;
	Array get_plugin_ids() const;
	Array get_plugins() const;

	bool enable_plugin(const StringName &p_plugin_id);
	bool disable_plugin(const StringName &p_plugin_id);
	bool is_plugin_enabled(const StringName &p_plugin_id) const;

	void initialize_plugins();
	void shutdown_plugins();
	void process_plugins(double p_delta);
	void dispatch_event(const StringName &p_event, const Dictionary &p_payload = Dictionary());

	FeaturePluginManager();
	~FeaturePluginManager();
};
