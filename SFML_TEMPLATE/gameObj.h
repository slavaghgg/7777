#pragma once
#include "settings.h"
class gameObj {
public: gameObj() {
}
	  sf::Vector2f getPosition() { return sprite.getPosition(); }
	  sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	  virtual void update() = 0; virtual void draw(sf::RenderWindow& window) = 0;

protected:
	sf::Texture texture; sf::Sprite sprite;
};
