/**************************************************************************/
/*  register_types.cpp                                                    */
/**************************************************************************/

#include "register_types.h"

#include "core/config/engine.h"
#include "core/object/class_db.h"

#include "feature_plugin.h"
#include "feature_plugin_manager.h"

void initialize_redesigned_plugins_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}

	GDREGISTER_CLASS(FeaturePlugin);
	GDREGISTER_CLASS(FeaturePluginManager);

	Engine::Singleton singleton("FeaturePluginManager", memnew(FeaturePluginManager));
	singleton.editor_only = false;
	Engine::get_singleton()->add_singleton(singleton);
}

void uninitialize_redesigned_plugins_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}

	FeaturePluginManager *manager = FeaturePluginManager::get_singleton();
	if (manager) {
		manager->shutdown_plugins();
		Engine::get_singleton()->remove_singleton("FeaturePluginManager");
		memdelete(manager);
	}
}
