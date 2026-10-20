extends Control

var compact_mode := false

func _ready() -> void:
    var toggle := $Toggle as Button
    toggle.pressed.connect(_toggle_compact_mode)
    _refresh_status()

func _toggle_compact_mode() -> void:
    compact_mode = not compact_mode
    _refresh_status()

func _refresh_status() -> void:
    $Status.text = "Redesign configuration demo — compact mode: %s" % ("ON" if compact_mode else "OFF")
