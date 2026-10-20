/**************************************************************************/
/*  redesign_config.h                                                     */
/**************************************************************************/
/*                         GODOT REDESIGNED                               */
/**************************************************************************/

#pragma once

#include "core/io/resource.h"
#include "core/math/color.h"
#include "core/variant/dictionary.h"
#include "core/variant/string.h"

class RedesignConfig : public Resource {
	GDCLASS(RedesignConfig, Resource);

	bool high_contrast = false;
	bool compact_mode = false;
	bool reduced_motion = false;
	Color accent_color = Color(0.396f, 0.843f, 0.816f, 1.0f);
	String density = "comfortable";

protected:
	static void _bind_methods();

public:
	void set_high_contrast(bool p_enabled);
	bool is_high_contrast() const;

	void set_compact_mode(bool p_enabled);
	bool is_compact_mode() const;

	void set_reduced_motion(bool p_enabled);
	bool is_reduced_motion() const;

	void set_accent_color(const Color &p_color);
	Color get_accent_color() const;

	void set_density(const String &p_density);
	String get_density() const;

	Dictionary to_dictionary() const;
	Error from_dictionary(const Dictionary &p_data);
};
