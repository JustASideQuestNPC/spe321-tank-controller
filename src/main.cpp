#include "Window.hpp"

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;

int main() {
    Window::init(SCREEN_WIDTH, SCREEN_HEIGHT, "[TANK NAME HERE]");

    while (Window::isRunning()) {
        Window::background(dracula::black);

        Window::fontColor = dracula::white;
        Window::fontSize = 40;
        Window::text("It's a work in progress, ok?", 5, 5);

        Window::update();
    }

    Window::close();
    return 0;
}
