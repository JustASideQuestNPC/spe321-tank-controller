#ifndef SPE321_ROBOT_RAYLIBSRC_IMAGECONTAINER_HPP
#define SPE321_ROBOT_RAYLIBSRC_IMAGECONTAINER_HPP

#include <string>
#include "raylib.h"

class ImageContainer {
    Image image_{};
    Texture2D texture_{};
    Rectangle rect_{};
public:
    ImageContainer() = default;
    ImageContainer(const Image &img, const Texture2D &txt);
    explicit ImageContainer(const std::string &path);
    ImageContainer(const ImageContainer &other);
    ImageContainer &operator=(const ImageContainer &other);

    [[nodiscard]] Image image() const { return image_; }
    [[nodiscard]] Texture2D texture() const { return texture_; }
    [[nodiscard]] Rectangle rect() const { return rect_; }
    [[nodiscard]] float width() const { return static_cast<float>(image_.width); }
    [[nodiscard]] float height() const { return static_cast<float>(image_.height); }

    ~ImageContainer();
};

#endif //SPE321_ROBOT_RAYLIBSRC_IMAGECONTAINER_HPP
