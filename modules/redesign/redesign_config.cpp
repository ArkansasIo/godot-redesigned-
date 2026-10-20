/**************************************************************************/
/*  redesign_config.cpp                                                   */
/**************************************************************************/
/*                         GODOT REDESIGNED                               */
/**************************************************************************/

#include "redesign_config.h"

#include "core/object/class_db.h"

void RedesignConfig::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_high_contrast", "enabled"), &RedesignConfig::set_high_contrast);
	ClassDB::bind_method(D_METHOD("is_high_contrast"), &RedesignConfig::is_high_contrast);
	ClassDB::bind_method(D_METHOD("set_compact_mode", "enabled"), &RedesignConfig::set_compact_mode);
	ClassDB::bind_method(D_METHOD("is_compact_mode"), &RedesignConfig::is_compact_mode);
	ClassDB::bind_method(D_METHOD("set_reduced_motion", "enabled"), &RedesignConfig::set_reduced_motion);
	ClassDB::bind_method(D_METHOD("is_reduced_motion"), &RedesignConfig::is_reduced_motion);
	ClassDB::bind_method(D_METHOD("set_accent_color", "color"), &RedesignConfig::set_accent_color);
	ClassDB::bind_method(D_METHOD("get_accent_color"), &RedesignConfig::get_accent_color);
	ClassDB::bind_method(D_METHOD("set_density", "density"), &RedesignConfig::set_density);
	ClassDB::bind_method(D_METHOD("get_density"), &RedesignConfig::get_density);
	ClassDB::bind_method(D_METHOD("to_dictionary"), &RedesignConfig::to_dictionary);
	ClassDB::bind_method(D_METHOD("from_dictionary", "data"), &RedesignConfig::from_dictionary);

	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "high_contrast"), "set_high_contrast", "is_high_contrast");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "compact_mode"), "set_compact_mode", "is_compact_mode");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "reduced_motion"), "set_reduced_motion", "is_reduced_motion");
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "accent_color"), "set_accent_color", "get_accent_color");
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "density"), "set_density", "get_density");
}

void RedesignConfig::set_high_contrast(bool p_enabled) { high_contrast = p_enabled; }
bool RedesignConfig::is_high_contrast() const { return high_contrast; }
void RedesignConfig::set_compact_mode(bool p_enabled) { compact_mode = p_enabled; }
bool RedesignConfig::is_compact_mode() const { return compact_mode; }
void RedesignConfig::set_reduced_motion(bool p_enabled) { reduced_motion = p_enabled; }
bool RedesignConfig::is_reduced_motion() const { return reduced_motion; }
void RedesignConfig::set_accent_color(const Color &p_color) { accent_color = p_color; }
Color RedesignConfig::get_accent_color() const { return accent_color; }
void RedesignConfig::set_density(const String &p_density) { density = p_density; }
String RedesignConfig::get_density() const { return density; }

Dictionary RedesignConfig::to_dictionary() const {
	Dictionary result;
	result["high_contrast"] = high_contrast;
	result["compact_mode"] = compact_mode;
	result["reduced_motion"] = reduced_motion;
	result["accent_color"] = accent_color;
	result["density"] = density;
	return result;
}

Error RedesignConfig::from_dictionary(const Dictionary &p_data) {
	if (p_data.has("high_contrast")) {
		high_contrast = bool(p_data["high_contrast"]);
	}
	if (p_data.has("compact_mode")) {
		compact_mode = bool(p_data["compact_mode"]);
	}
	if (p_data.has("reduced_motion")) {
		reduced_motion = bool(p_data["reduced_motion"]);
	}
	if (p_data.has("accent_color") && p_data["accent_color"].get_type() == Variant::COLOR) {
		accent_color = Color(p_data["accent_color"]);
	}
	if (p_data.has("density")) {
		density = String(p_data["density"]);
	}
	return OK;
}
