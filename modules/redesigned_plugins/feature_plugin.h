/**************************************************************************/
/*  feature_plugin.h                                                      */
/**************************************************************************/
/* A lightweight extension contract for the redesigned Godot feature API. */
/**************************************************************************/

#pragma once

#include "core/io/resource.h"
#include "core/object/ref_counted.h"

class FeaturePlugin : public RefCounted {
	GDCLASS(FeaturePlugin, RefCounted);

	String plugin_id;
	String plugin_name;
	String plugin_version = "1.0.0";
	String plugin_author;
	String plugin_description;
	int priority = 0;
	bool enabled = true;

protected:
	static void _bind_methods();

public:
	void set_plugin_id(const String &p_id);
	String get_plugin_id() const;

	void set_plugin_name(const String &p_name);
	String get_plugin_name() const;

	void set_plugin_version(const String &p_version);
	String get_plugin_version() const;

	void set_plugin_author(const String &p_author);
	String get_plugin_author() const;

	void set_plugin_description(const String &p_description);
	String get_plugin_description() const;

	void set_priority(int p_priority);
	int get_priority() const;

	void set_enabled(bool p_enabled);
	bool is_enabled() const;

	// These methods intentionally dispatch through Object::call(), allowing
	// GDScript/C# plugins to override the lifecycle methods without requiring
	// another native class for every feature.
	virtual void initialize();
	virtual void shutdown();
	virtual void process(double p_delta);
	virtual void on_feature_event(const StringName &p_event, const Dictionary &p_payload);
};
