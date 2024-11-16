#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

using namespace std;

namespace constants {

namespace animation {

inline const auto IDLE = "Idle";
inline const auto MOVE = "Move";

} //namespace animation

namespace input {

inline const auto MOVE_LEFT = "MoveLeft";
inline const auto MOVE_RIGHT = "MoveRight";
inline const auto MOVE_FORWARD = "MoveForward";
inline const auto MOVE_BACKWARD = "MoveBackward";

} //namespace input

} //namespace constants

#endif // CONSTANTS_H
