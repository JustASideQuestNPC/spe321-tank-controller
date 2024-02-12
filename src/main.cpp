#include "Window.hpp"
#include "Gamepad.hpp"
#include "ImageContainer.hpp"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

int main() {
    Gamepad controller{0};
    bool fullscreenTogglePressed, connectionTogglePressed, modeSwitchPressed;
    bool connected = false;
    bool pilotMode = true;

    Window::init(WINDOW_WIDTH, WINDOW_HEIGHT, "[TANK NAME HERE]");
    ImageContainer backgroundImage{"assets/background.png"};
    ImageContainer movementControlsImage{"assets/movement-controls.png"};
    ImageContainer otherControlsImage{"assets/other-controls.png"};

    ImageContainer connectedImage{"assets/connection-status-connected.png"};
    ImageContainer disconnectedImage{"assets/connection-status-disconnected.png"};

    ImageContainer sentryModeImage{"assets/mode-indicator-sentry.png"};
    ImageContainer pilotModeImage{"assets/mode-indicator-manual.png"};

    float windowedScale = static_cast<float>(WINDOW_WIDTH) /
        static_cast<float>(GetMonitorWidth(GetCurrentMonitor()));
    float currentScale;

    while (Window::isRunning()) {
        if (controller.buttonPressed(FACE_Y)) {
            if (!fullscreenTogglePressed) {
                fullscreenTogglePressed = true;
                Window::toggleFullscreen();
            }
        }
        else {
            fullscreenTogglePressed = false;
        }

        if (controller.buttonPressed(FACE_B)) {
            if (!connectionTogglePressed) {
                connectionTogglePressed = true;
                // presumably we'd do some stuff to connect to the robot here
                connected = !connected;
            }
        }
        else {
            connectionTogglePressed = false;
        }

        if (controller.buttonPressed(FACE_X)) {
            if (!modeSwitchPressed) {
                modeSwitchPressed = true;
                pilotMode = !pilotMode;
            }
        }
        else {
            modeSwitchPressed = false;
        }

        if (Window::isFullscreen()) {
            currentScale = 1;
        }
        else {
            currentScale = windowedScale;
        }

        Window::background(backgroundImage);


        // draw control layer
        Window::draw::image(
            movementControlsImage,
            0,
            Window::height() - movementControlsImage.height() * currentScale,
            movementControlsImage.width() * currentScale,
            movementControlsImage.height() * currentScale
        );

        Window::draw::image(
            otherControlsImage,
            Window::width() - otherControlsImage.width() * currentScale,
            Window::height() - otherControlsImage.height() * currentScale,
            otherControlsImage.width() * currentScale,
            otherControlsImage.height() * currentScale
        );

        if (connected) {
            Window::draw::image(
                connectedImage,
                Window::width() - connectedImage.width() * currentScale,
                0,
                connectedImage.width() * currentScale,
                connectedImage.height() * currentScale
            );
        }
        else {
            Window::draw::image(
                disconnectedImage,
                Window::width() - disconnectedImage.width() * currentScale,
                0,
                disconnectedImage.width() * currentScale,
                disconnectedImage.height() * currentScale
            );
        }

        if (pilotMode) {
            Window::draw::image(
                pilotModeImage,
                Window::width() - pilotModeImage.width() * currentScale,
                connectedImage.height() * currentScale, // both images have the same height
                pilotModeImage.width() * currentScale,
                pilotModeImage.height() * currentScale
            );
        }
        else {
            Window::draw::image(
                sentryModeImage,
                Window::width() - sentryModeImage.width() * currentScale,
                connectedImage.height() * currentScale, // both images have the same height
                sentryModeImage.width() * currentScale,
                sentryModeImage.height() * currentScale
            );
        }

        Window::update();
    }

    Window::close();
    return 0;
}
