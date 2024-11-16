#include "player.h"
#include "constants.h"
#include "godot_cpp/classes/animation_player.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/sprite3d.hpp"
#include "godot_cpp/variant/string.hpp"
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
			String(constants::input::MOVE_LEFT),
			String(constants::input::MOVE_RIGHT),
			String(constants::input::MOVE_FORWARD),
			String(constants::input::MOVE_BACKWARD));

	if (direction == Vector2(0, 0)) {
		animation_player->play(String(constants::animation::IDLE));
	} else {
		animation_player->play(String(constants::animation::MOVE));
	}
}

void Player::_physics_process(double p_delta) {
	// UtilityFunctions::print("Player process");
	Vector3 velocity = Vector3(direction.x, 0, direction.y);
	velocity *= 5;

	set_velocity(velocity);

	move_and_slide();
	flip();
}

void Player::flip() {
	if (get_velocity().x != 0) {
		sprite->set_flip_h(get_velocity().x < 0);
	}
}
