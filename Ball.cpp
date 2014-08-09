#include "include/Ball.hpp"

Ball::Ball() : CircleShape()
{
    this->setMovingUp(false);
    this->setMovingDown(false);
    this->setMovingRight(false);
    this->setMovingLeft(false);
}

bool Ball::isMovingUp() const
{
    return this->movingUp;
}

bool Ball::isMovingDown() const
{
    return this->movingDown;
}

bool Ball::isMovingRight() const
{
    return this->movingRight;
}

bool Ball::isMovingLeft() const
{
    return this->movingLeft;
}

void Ball::setMovingUp(bool isMoving)
{
    this->movingUp = isMoving;
}

void Ball::setMovingDown(bool isMoving)
{
    this->movingDown = isMoving;
}

void Ball::setMovingRight(bool isMoving)
{
    this->movingRight = isMoving;
}

void Ball::setMovingLeft(bool isMoving)
{
    this->movingLeft = isMoving;
}
