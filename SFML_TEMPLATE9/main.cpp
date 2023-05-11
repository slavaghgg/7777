#include <ctime>
#include "game.h"

using namespace sf;

int main()
{
	srand((unsigned int)time(nullptr));
	Game game;
	game.play();
	return 0;
}