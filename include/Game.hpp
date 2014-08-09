#ifndef GAME_PONG
#define GAME_PONG

#include <SFML/Graphics.hpp>
#include "Ball.hpp"

const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f); //0,016666667

class Game
{
    public:
        Game();
        void run();

    private:
        void proccessEvents();
        void update(sf::Time timePerFrame);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    private:
        // janela do jogo
        sf::RenderWindow mWindow;
        // bolinha
        Ball mBall;


};

#endif
