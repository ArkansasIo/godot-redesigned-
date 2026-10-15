/**************************************************************************/
/*  feature_plugin.cpp                                                    */
/**************************************************************************/

#include "feature_plugin.h"

void FeaturePlugin::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_plugin_id", "id"), &FeaturePlugin::set_plugin_id);
	ClassDB::bind_method(D_METHOD("get_plugin_id"), &FeaturePlugin::get_plugin_id);
	ClassDB::bind_method(D_METHOD("set_plugin_name", "name"), &FeaturePlugin::set_plugin_name);
	ClassDB::bind_method(D_METHOD("get_plugin_name"), &FeaturePlugin::get_plugin_name);
	ClassDB::bind_method(D_METHOD("set_plugin_version", "version"), &FeaturePlugin::set_plugin_version);
	ClassDB::bind_method(D_METHOD("get_plugin_version"), &FeaturePlugin::get_plugin_version);
	ClassDB::bind_method(D_METHOD("set_plugin_author", "author"), &FeaturePlugin::set_plugin_author);
	ClassDB::bind_method(D_METHOD("get_plugin_author"), &FeaturePlugin::get_plugin_author);
	ClassDB::bind_method(D_METHOD("set_plugin_description", "description"), &FeaturePlugin::set_plugin_description);
	ClassDB::bind_method(D_METHOD("get_plugin_description"), &FeaturePlugin::get_plugin_description);
	ClassDB::bind_method(D_METHOD("set_priority", "priority"), &FeaturePlugin::set_priority);
	ClassDB::bind_method(D_METHOD("get_priority"), &FeaturePlugin::get_priority);
	ClassDB::bind_method(D_METHOD("set_enabled", "enabled"), &FeaturePlugin::set_enabled);
	ClassDB::bind_method(D_METHOD("is_enabled"), &FeaturePlugin::is_enabled);

	ClassDB::bind_method(D_METHOD("initialize"), &FeaturePlugin::initialize);
	ClassDB::bind_method(D_METHOD("shutdown"), &FeaturePlugin::shutdown);
	ClassDB::bind_method(D_METHOD("process", "delta"), &FeaturePlugin::process);
	ClassDB::bind_method(D_METHOD("on_feature_event", "event", "payload"), &FeaturePlugin::on_feature_event);

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "plugin_id"), "set_plugin_id", "get_plugin_id");
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "plugin_name"), "set_plugin_name", "get_plugin_name");
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "plugin_version"), "set_plugin_version", "get_plugin_version");
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "plugin_author"), "set_plugin_author", "get_plugin_author");
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "plugin_description", PROPERTY_HINT_MULTILINE_TEXT), "set_plugin_description", "get_plugin_description");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "priority"), "set_priority", "get_priority");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "enabled"), "set_enabled", "is_enabled");
}

void FeaturePlugin::set_plugin_id(const String &p_id) { plugin_id = p_id; }
String FeaturePlugin::get_plugin_id() const { return plugin_id; }
void FeaturePlugin::set_plugin_name(const String &p_name) { plugin_name = p_name; }
String FeaturePlugin::get_plugin_name() const { return plugin_name; }
void FeaturePlugin::set_plugin_version(const String &p_version) { plugin_version = p_version; }
String FeaturePlugin::get_plugin_version() const { return plugin_version; }
void FeaturePlugin::set_plugin_author(const String &p_author) { plugin_author = p_author; }
String FeaturePlugin::get_plugin_author() const { return plugin_author; }
void FeaturePlugin::set_plugin_description(const String &p_description) { plugin_description = p_description; }
String FeaturePlugin::get_plugin_description() const { return plugin_description; }
void FeaturePlugin::set_priority(int p_priority) { priority = p_priority; }
int FeaturePlugin::get_priority() const { return priority; }
void FeaturePlugin::set_enabled(bool p_enabled) { enabled = p_enabled; }
bool FeaturePlugin::is_enabled() const { return enabled; }

void FeaturePlugin::initialize() {}
void FeaturePlugin::shutdown() {}
void FeaturePlugin::process(double p_delta) {}
void FeaturePlugin::on_feature_event(const StringName &p_event, const Dictionary &p_payload) {}
