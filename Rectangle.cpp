#include "include/Rectangle.hpp"

Rectangle::Rectangle() : RectangleShape()
{
    this->setSize(sf::Vector2<float>(5.f, 15.f));
    this->setFillColor(sf::Color::Green);
    this->setPosition(500.f, 500.f);
}
