/**************************************************************************/
/*  register_types.cpp                                                    */
/**************************************************************************/
/*                         GODOT REDESIGNED                               */
/**************************************************************************/

#include "register_types.h"

#include "redesign_config.h"
#include "core/object/class_db.h"

void initialize_redesign_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		GDREGISTER_CLASS(RedesignConfig);
	}
}

void uninitialize_redesign_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
