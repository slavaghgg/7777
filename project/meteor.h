#pragma once
#include "settings.h"


class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f speed;
public:
	enum meteorsize {
		small,
		average,
		big
	};

	Meteor(std::string filename, meteorsize size, sf::Vector2f pos, sf::Vector2f fspeed) {
		texture.loadFromFile(filename);
		sprite.setTexture(texture);
		if (size == big) {
			sprite.setScale(0.5, 0.5);

		}
		if (size == average) {
			sprite.setScale(0.25, 0.25);

		}
		if (size == small) {
			sprite.setScale(0.125, 0.125);

		}
		sprite.setPosition(pos);
		speed = fspeed;

	}
	void update() {
		sprite.move(speed);


	}
	sf::Sprite getSprite() { return sprite; }
};
