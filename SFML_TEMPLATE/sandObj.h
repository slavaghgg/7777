#pragma once 
#include <SFML/Graphics.hpp> 
#include "settings.h" 
#include "gameObj.h" 
class SandObj : public gameObj {
public:
	SandObj() {
		texture.loadFromFile(SAND_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(SAND_START_POS);
	}
	void update() {}

	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};
