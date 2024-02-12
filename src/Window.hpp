#ifndef SPE321_ROBOT_RAYLIBSRC_WINDOW_HPP
#define SPE321_ROBOT_RAYLIBSRC_WINDOW_HPP

#include <sstream>
#include "raylib.h"
#include "ImageContainer.hpp"

// Dracula Theme - i really, *really* want to define everything in all caps for this, but raylib
// defines everything in the global namespace for some reason and half the names are reserved
namespace dracula {
    [[maybe_unused]] constexpr Color black = Color{40, 42, 54, 255};
    [[maybe_unused]] constexpr Color darkGray = Color{68, 71, 90, 255};
    [[maybe_unused]] constexpr Color lightGray = Color{98, 114, 164, 255};
    [[maybe_unused]] constexpr Color white = Color{248, 248, 242, 255};
    [[maybe_unused]] constexpr Color cyan = Color{139, 233, 253, 255};
    [[maybe_unused]] constexpr Color green = Color{80, 250, 123, 255};
    [[maybe_unused]] constexpr Color orange = Color{255, 184, 108, 255};
    [[maybe_unused]] constexpr Color pink = Color{255, 121, 198, 255};
    [[maybe_unused]] constexpr Color purple = Color{190, 147, 250, 255};
    [[maybe_unused]] constexpr Color red = Color{255, 85, 85, 255};
    [[maybe_unused]] constexpr Color yellow = Color{241, 250, 140, 255};
}

namespace Window {
    // anonymous namespace to make things private
    namespace {
        int screenWidth, screenHeight, monitorWidth, monitorHeight, currentMonitor, currentWidth,
            currentHeight;
        bool fullscreen = false;
        ImageContainer bgImg;
    }

    void init(const int width, const int height, const std::string &title) {
        screenWidth = width;
        screenHeight = height;
        currentWidth = width;
        currentHeight = height;
        InitWindow(width, height, title.c_str());
        SetTargetFPS(60);
        currentMonitor = GetCurrentMonitor();
        monitorWidth = GetMonitorWidth(currentMonitor);
        monitorHeight = GetMonitorHeight(currentMonitor);
    }
    void close() {
        CloseWindow();
    }

    void toggleFullscreen() {
        ToggleBorderlessWindowed();
        fullscreen = !fullscreen;
        if (fullscreen) {
            SetWindowSize(monitorWidth, monitorHeight);
            currentWidth = monitorWidth;
            currentHeight = monitorHeight;
        }
        else {
            SetWindowSize(screenWidth, screenHeight);
            currentWidth = screenWidth;
            currentHeight = screenHeight;
        }
    }

    // makes more sense than WindowShouldClose()
    [[nodiscard]] bool isRunning() { return !WindowShouldClose(); }
    [[nodiscard]] bool isFullscreen() { return fullscreen; }
    [[nodiscard]] float width() { return static_cast<float>(currentWidth); }
    [[nodiscard]] float height() { return static_cast<float>(currentHeight); }

    void background(Color color) {
        BeginDrawing(); // only does something if we're not already drawing
        ClearBackground(color);
    }

    void background(const ImageContainer &image) {
        BeginDrawing();
        Rectangle dest{0, 0, static_cast<float>(currentWidth), static_cast<float>(currentHeight)};
        DrawTexturePro(image.texture(), image.rect(), dest, {0, 0}, 0, WHITE);
    }

    // swaps framebuffers and updates the screen
    void update() { EndDrawing(); }

    namespace draw {
        float fontSize = 20;
        Color fontColor = WHITE;
        Font font = GetFontDefault();
        float fontTracking = 2; // space between characters
        float fontLeading = 20; // line height

        void text(const std::string &str, float x, float y) {
            std::istringstream stream(str);
            std::string line;
            float yPos = y;
            while (std::getline(stream, line)) {
                DrawTextEx(font, line.c_str(), Vector2(x, yPos), fontSize, fontTracking, fontColor);
                yPos += fontLeading;
            }
        }

        void image(const ImageContainer &image, float x, float y, Color tint = WHITE) {
            DrawTexture(image.texture(), static_cast<int>(x), static_cast<int>(y), tint);
        }
        void image(const ImageContainer &image, float x, float y, float w, float h,
                   float rotation = 0, Color tint = WHITE) {
            Rectangle dest{x, y, w, h};
            DrawTexturePro(image.texture(), image.rect(), dest, {0, 0}, rotation, tint);
        }
    }
}

#endif //SPE321_ROBOT_RAYLIBSRC_WINDOW_HPP