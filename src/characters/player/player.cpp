#include "player.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Player::_bind_methods() {
}

Player::Player() {
	// Initialize any variables here.
	time_passed = 0.0;
}

Player::~Player() {
	// Add your cleanup here.
}

void Player::_physics_process(double delta) {
	// UtilityFunctions::print("Player process");
}
