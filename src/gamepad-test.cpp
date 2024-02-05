#include <sstream>
#include <iomanip>
#include "Window.hpp"
#include "Gamepad.hpp"
#include "Vec2D.hpp"

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;
constexpr int GAMEPAD_ID = 0;

int main() {
    Window::init(SCREEN_WIDTH, SCREEN_HEIGHT, "Gamepad Test");
    Window::fontSize = 20;
    Window::fontColor = dracula::white;

    Gamepad controller{GAMEPAD_ID};

    while (Window::isRunning()) {
        Window::background(dracula::black);

        std::ostringstream stream;
        if (controller.isConnected()) {
            Vec2D leftStick = controller.leftStick();
            Vec2D rightStick = controller.rightStick();
            Vec2D leftStickRaw = controller.leftStick(true);
            Vec2D rightStickRaw = controller.rightStick(true);

            stream << "Controller connected!\nButton States:\n" << std::setprecision(6) << std::fixed
                << "- DPAD_UP: " << controller.buttonPressed(DPAD_UP) << "\n"
                << "- DPAD_DOWN: " << controller.buttonPressed(DPAD_DOWN) << "\n"
                << "- DPAD_LEFT: " << controller.buttonPressed(DPAD_LEFT) << "\n"
                << "- DPAD_RIGHT: " << controller.buttonPressed(DPAD_RIGHT) << "\n"
                << "- FACE_A: " << controller.buttonPressed(FACE_A) << "\n"
                << "- FACE_B: " << controller.buttonPressed(FACE_B) << "\n"
                << "- FACE_X: " << controller.buttonPressed(FACE_X) << "\n"
                << "- FACE_Y: " << controller.buttonPressed(FACE_Y) << "\n"
                << "- LEFT_BUMPER: " << controller.buttonPressed(LEFT_BUMPER) << "\n"
                << "- LEFT_TRIGGER_BUTTON: " << controller.buttonPressed(LEFT_TRIGGER_BUTTON) << "\n"
                << "- LEFT_STICK_CLICK: " << controller.buttonPressed(LEFT_STICK_CLICK) << "\n"
                << "- RIGHT_BUMPER: " << controller.buttonPressed(RIGHT_BUMPER) << "\n"
                << "- RIGHT_TRIGGER_BUTTON: " << controller.buttonPressed(RIGHT_TRIGGER_BUTTON) << "\n"
                << "- RIGHT_STICK_CLICK: " << controller.buttonPressed(RIGHT_STICK_CLICK) << "\n"
                << "- OPTIONS: " << controller.buttonPressed(OPTIONS) << "\n"
                << "- SHARE: " << controller.buttonPressed(SHARE) << "\n"
                << "Axis Values:\n"
                << "- LEFT_TRIGGER_AXIS: " << controller.axisValue(LEFT_TRIGGER_AXIS) << "\n"
                << "- RIGHT_TRIGGER_AXIS: " << controller.axisValue(RIGHT_TRIGGER_AXIS) << "\n"
                << "- LEFT_STICK_X: " << leftStick.x << " (raw: " << leftStickRaw.x << ")\n"
                << "- LEFT_STICK_Y: " << leftStick.y << " (raw: " << leftStickRaw.y << ")\n"
                << "- RIGHT_STICK_X: " << rightStick.x << " (raw: " << rightStickRaw.x << ")\n"
                << "- RIGHT_STICK_Y: " << rightStick.y << " (raw: " << rightStickRaw.y << ")\n";
        }
        else {
            stream << "Controller not connected :(\n";
        }

        Window::text(stream.str(), 5, 5);

        Window::update();
    }

    Window::close();
    return 0;
}