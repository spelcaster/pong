#include "include/Game.hpp"

Game::Game():
    mWindow(sf::VideoMode(1600,900), "Pong"),
    mBall(),
    mPlayerOne()
{
}

void Game::run()
{
    // clock de pro
    sf::Clock clock;

    // removendo o lag
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // janela do jogo
    while (mWindow.isOpen())
    {
        // processa eventos na tela
        proccessEvents();

        // evitar lag
        timeSinceLastUpdate += clock.restart();

        // loop de atualização dos frames
        while (timeSinceLastUpdate > TIME_PER_FRAME) {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            update(TIME_PER_FRAME);
            render();
        }
    }
}


void Game::proccessEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event)) {

        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }

}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W) {
        mBall.setMovingUp(isPressed);
    } else if (key == sf::Keyboard::S) {
        mBall.setMovingDown(isPressed);
    } else if (key == sf::Keyboard::A) {
        mBall.setMovingLeft(isPressed);
    } else if (key == sf::Keyboard::D) {
        mBall.setMovingRight(isPressed);
    }
}

void Game::update(sf::Time timePerFrame)
{
    sf::Vector2f movement(0.f, 0.f);

    if ( mBall.isMovingUp() ) {
        movement.y -= 100.f;
    }
    if ( mBall.isMovingDown() ) {
        movement.y += 100.f;
    }
    if ( mBall.isMovingLeft() ) {
        movement.x -= 100.f;
    }
    if ( mBall.isMovingRight() ) {
        movement.x += 100.f;
    }

    mBall.move(movement * timePerFrame.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mBall);
    mWindow.draw(mPlayerOne);
    mWindow.display();
}
