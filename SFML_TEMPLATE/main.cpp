#include "settings.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;


int main()
{
    srand(time(nullptr));
    Game game;
    game.play();
  
    
    return 0;
}