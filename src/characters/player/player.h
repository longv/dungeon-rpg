#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/character_body3d.hpp>

namespace godot {

class Player : public CharacterBody3D {
	GDCLASS(Player, CharacterBody3D)

private:
	double time_passed;

protected:
	static void _bind_methods();

public:
	Player();
	~Player();

	void _physics_process(double delta) override;
};

} //namespace godot

#endif
