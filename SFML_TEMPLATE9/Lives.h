#pragma once
#include "settings.h"
#include "gameObj.h"

class Lives :public gameObj {
public:
	Lives(sf::Vector2f pos);
	void update();
	void draw(sf::RenderWindow& window);

};


Lives::Lives(sf::Vector2f pos) {
	texture.loadFromFile(LIFE_ICON_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setPosition(pos);
}

void Lives::update() {}

void Lives::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
