#include "include/Rectangle.hpp"

Rectangle::Rectangle(float x, float y, Keyboard::Key keyUp, Keyboard::Key keyDown)
    : RectangleShape()
{
    this->setSize(sf::Vector2<float>(50.f, 150.f));
    this->setFillColor(sf::Color::Green);
    this->setPosition(x, y);

    movingUp = false;
    movingDown = false;
    this->keyUp = keyUp;
    this->keyDown = keyDown;
}

bool Rectangle::isMovingUp() const
{
    return this->movingUp;
}

bool Rectangle::isMovingDown() const
{
    return this->movingDown;
}

void Rectangle::setMovingUp(bool isMoving)
{
    this->movingUp = isMoving;
}

void Rectangle::setMovingDown(bool isMoving)
{
    this->movingDown = isMoving;
}

void Rectangle::handleInput(const sf::Keyboard::Key &key, bool isPressed)
{
    if (key == keyUp)
        setMovingUp(isPressed);
    else if (key == keyDown)
        setMovingDown(isPressed);
}

void Rectangle::update(const sf::Time &timePerFrame)
{
    sf::Vector2f movement(0.f, 0.f);

    if ( isMovingUp() )
        movement.y -= 200.f;
    if ( isMovingDown() )
        movement.y += 200.f;

    move(movement * timePerFrame.asSeconds());
}
