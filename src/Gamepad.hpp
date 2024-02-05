#ifndef SPE321_ROBOT_RAYLIBSRC_GAMEPAD_HPP
#define SPE321_ROBOT_RAYLIBSRC_GAMEPAD_HPP

#include "raylib.h"
#include "Vec2D.hpp"

// more sane names for controller buttons and axes
enum ControllerButton {
    DPAD_UP [[maybe_unused]] = GAMEPAD_BUTTON_LEFT_FACE_UP,
    DPAD_DOWN [[maybe_unused]] = GAMEPAD_BUTTON_LEFT_FACE_DOWN,
    DPAD_LEFT [[maybe_unused]] = GAMEPAD_BUTTON_LEFT_FACE_LEFT,
    DPAD_RIGHT [[maybe_unused]] = GAMEPAD_BUTTON_LEFT_FACE_RIGHT,
    FACE_A [[maybe_unused]] = GAMEPAD_BUTTON_RIGHT_FACE_DOWN, // X on playstation
    FACE_B [[maybe_unused]] = GAMEPAD_BUTTON_RIGHT_FACE_RIGHT, // Circle on playstation
    FACE_X [[maybe_unused]] = GAMEPAD_BUTTON_RIGHT_FACE_LEFT, // Square on playstation
    FACE_Y [[maybe_unused]] = GAMEPAD_BUTTON_RIGHT_FACE_UP, // Triangle on playstation
    LEFT_BUMPER [[maybe_unused]] = GAMEPAD_BUTTON_LEFT_TRIGGER_1, // L1 on playstation
    LEFT_TRIGGER_BUTTON [[maybe_unused]] = GAMEPAD_BUTTON_LEFT_TRIGGER_2, // L2 on playstation
    LEFT_STICK_CLICK [[maybe_unused]] = GAMEPAD_BUTTON_LEFT_THUMB, // L3 on playstation
    RIGHT_BUMPER [[maybe_unused]] = GAMEPAD_BUTTON_RIGHT_TRIGGER_1, // R1 on playstation
    RIGHT_TRIGGER_BUTTON [[maybe_unused]] = GAMEPAD_BUTTON_RIGHT_TRIGGER_2, // R2 on playstation
    RIGHT_STICK_CLICK [[maybe_unused]] = GAMEPAD_BUTTON_RIGHT_THUMB, // R3 on playstation
    HOME [[maybe_unused]] = GAMEPAD_BUTTON_MIDDLE, // Xbox button on xbox, PS button on playstation
    OPTIONS [[maybe_unused]] = GAMEPAD_BUTTON_MIDDLE_RIGHT,
    SHARE [[maybe_unused]] = GAMEPAD_BUTTON_MIDDLE_LEFT
};

enum ControllerAxis {
    LEFT_TRIGGER_AXIS [[maybe_unused]] = GAMEPAD_AXIS_LEFT_TRIGGER,
    RIGHT_TRIGGER_AXIS [[maybe_unused]] = GAMEPAD_AXIS_RIGHT_TRIGGER,
    LEFT_STICK_X [[maybe_unused]] = GAMEPAD_AXIS_LEFT_X,
    LEFT_STICK_Y [[maybe_unused]] = GAMEPAD_AXIS_LEFT_Y,
    RIGHT_STICK_X [[maybe_unused]] = GAMEPAD_AXIS_RIGHT_X,
    RIGHT_STICK_Y [[maybe_unused]] = GAMEPAD_AXIS_RIGHT_Y
};

class Gamepad {
    const int id;
public:
    // if true, trigger axes range from 0-1 (instead of -1-1)
    bool NORMALIZE_ANALOG_TRIGGERS = true;
    // stick inputs smaller than this are ignored, and everything else is mapped between 0 and 1
    float STICK_DEADZONE = 0.25;

    explicit Gamepad(int gamepadId) : id(gamepadId) {}

    [[nodiscard]] bool isConnected() const { return IsGamepadAvailable(id); }
    [[nodiscard]] bool buttonPressed(ControllerButton button) const {
        return IsGamepadButtonDown(id, button);
    }
    [[nodiscard]] float axisValue(ControllerAxis axis) const;

    [[nodiscard]] Vec2D leftStick(bool ignoreDeadzone=false) const;
    [[nodiscard]] Vec2D rightStick(bool ignoreDeadzone=false) const;
};

#endif // SPE321_ROBOT_RAYLIBSRC_GAMEPAD_HPP
