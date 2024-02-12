//
// Created by hey-t on 2/12/2024.
//

#include "ImageContainer.hpp"
ImageContainer::ImageContainer(const Image &img, const Texture2D &txt) : image_(img), texture_(txt) {
    rect_ = {0, 0, static_cast<float>(img.width), static_cast<float>(img.height)};
}
ImageContainer::ImageContainer(const std::string &path) {
    image_ = LoadImage(path.c_str());
    texture_ = LoadTextureFromImage(image_);
    rect_ = {0, 0, static_cast<float>(image_.width), static_cast<float>(image_.height)};
}
ImageContainer::~ImageContainer() {
    UnloadImage(image_);
    UnloadTexture(texture_);
}
ImageContainer::ImageContainer(const ImageContainer &other) {
    this->image_ = ImageCopy(other.image_);
    this->texture_ = LoadTextureFromImage(this->image_);
    rect_ = {other.rect_};
}
ImageContainer &ImageContainer::operator=(const ImageContainer &other) {
    UnloadImage(this->image_);
    UnloadTexture(this->texture_);
    this->image_ = ImageCopy(other.image_);
    this->texture_ = LoadTextureFromImage(this->image_);
    rect_ = {other.rect_};
    return *this;
}
