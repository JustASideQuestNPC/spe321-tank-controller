//
// Created by hey-t on 2/5/2024.
//

#include "Gamepad.hpp"
float Gamepad::axisValue(ControllerAxis axis) const {
    if (NORMALIZE_ANALOG_TRIGGERS &&
        (axis == LEFT_TRIGGER_AXIS || axis == RIGHT_TRIGGER_AXIS)) {
        return (GetGamepadAxisMovement(id, axis) + 1) / 2;
    }
    return GetGamepadAxisMovement(id, axis);
}
Vec2D Gamepad::leftStick(bool ignoreDeadzone) const {
    float x, y;
    if (ignoreDeadzone || STICK_DEADZONE <= 0) {
        x = GetGamepadAxisMovement(id, LEFT_STICK_X);
        y = GetGamepadAxisMovement(id, LEFT_STICK_Y);
    }
    else {
        float xRaw = GetGamepadAxisMovement(id, LEFT_STICK_X);
        if (xRaw > STICK_DEADZONE) {
            x = (1 / (1 - STICK_DEADZONE)) * (xRaw - STICK_DEADZONE);
        }
        else if (xRaw < -STICK_DEADZONE) {
            x = -((1 / (1 - STICK_DEADZONE)) * (-xRaw - STICK_DEADZONE));
        }
        else {
            x = 0;
        }

        float yRaw = GetGamepadAxisMovement(id, LEFT_STICK_Y);
        if (yRaw > STICK_DEADZONE) {
            y = (1 / (1 - STICK_DEADZONE)) * (yRaw - STICK_DEADZONE);
        }
        else if (xRaw < -STICK_DEADZONE) {
            y = -((1 / (1 - STICK_DEADZONE)) * (-yRaw - STICK_DEADZONE));
        }
        else {
            y = 0;
        }
    }

    return {
        x,
        y
    };
}
Vec2D Gamepad::rightStick(bool ignoreDeadzone) const {
    float x, y;
    if (ignoreDeadzone || STICK_DEADZONE <= 0) {
        x = GetGamepadAxisMovement(id, RIGHT_STICK_X);
        y = GetGamepadAxisMovement(id, RIGHT_STICK_Y);
    }
    else {
        float xRaw = GetGamepadAxisMovement(id, RIGHT_STICK_X);
        if (xRaw > STICK_DEADZONE) {
            x = (1 / (1 - STICK_DEADZONE)) * (xRaw - STICK_DEADZONE);
        }
        else if (xRaw < -STICK_DEADZONE) {
            x = -((1 / (1 - STICK_DEADZONE)) * (-xRaw - STICK_DEADZONE));
        }
        else {
            x = 0;
        }

        float yRaw = GetGamepadAxisMovement(id, RIGHT_STICK_Y);
        if (yRaw > STICK_DEADZONE) {
            y = (1 / (1 - STICK_DEADZONE)) * (yRaw - STICK_DEADZONE);
        }
        else if (xRaw < -STICK_DEADZONE) {
            y = -((1 / (1 - STICK_DEADZONE)) * (-yRaw - STICK_DEADZONE));
        }
        else {
            y = 0;
        }
    }

    return {
        x,
        y
    };
}
