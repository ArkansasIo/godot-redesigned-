extends FeaturePlugin

func _init() -> void:
	plugin_id = "example.basic_feature"
	plugin_name = "Basic Feature"
	plugin_version = "1.0.0"
	plugin_author = "ArkansasIo"
	plugin_description = "Example feature implemented entirely in GDScript."
	priority = 100
	enabled = true

func initialize() -> void:
	print("Basic Feature initialized")

func shutdown() -> void:
	print("Basic Feature shut down")

func process(delta: float) -> void:
	# Add feature-specific per-frame work here.
	pass

func on_feature_event(event: StringName, payload: Dictionary) -> void:
	if event == &"game_started":
		print("Game started: ", payload)
