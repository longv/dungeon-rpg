#include "player.h"
#include "godot_cpp/classes/animation_player.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/sprite3d.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/variant/vector2.hpp"
#include "godot_cpp/variant/vector3.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Player::_bind_methods() {
}

Player::Player() {
	direction = Vector2(0, 0);
}

Player::~Player() {
	// Add your cleanup here.
}

void Player::_ready() {
	sprite = get_node<Sprite3D>("Sprite3D");
	animation_player = get_node<AnimationPlayer>("AnimationPlayer");

	animation_player->play("Idle");
}

void Player::_input(const Ref<InputEvent> &p_event) {
	direction = Input::get_singleton()->get_vector(
			"MoveLeft",
			"MoveRight",
			"MoveForward",
			"MoveBackward");

	if (direction == Vector2(0, 0)) {
		animation_player->play("Idle");
	} else {
		animation_player->play("Move");
	}
}

void Player::_physics_process(double p_delta) {
	// UtilityFunctions::print("Player process");
	Vector3 velocity = Vector3(direction.x, 0, direction.y);
	velocity *= 5;

	set_velocity(velocity);

	move_and_slide();
}
