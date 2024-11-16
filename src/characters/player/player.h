#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include "godot_cpp/classes/animation_player.hpp"
#include "godot_cpp/classes/character_body3d.hpp"
#include "godot_cpp/classes/input_event.hpp"
#include "godot_cpp/classes/sprite3d.hpp"
#include "godot_cpp/variant/vector2.hpp"

namespace godot {

class Player : public CharacterBody3D {
	GDCLASS(Player, CharacterBody3D)

private:
	Sprite3D *sprite = nullptr;
	AnimationPlayer *animation_player = nullptr;

	Vector2 direction;

protected:
	static void
	_bind_methods();

public:
	Player();
	~Player();

	void _ready() override;
	void _input(const Ref<InputEvent> &p_event) override;
	void _physics_process(double p_delta) override;
};

} //namespace godot

#endif
