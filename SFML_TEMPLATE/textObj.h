#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class TextObj {
private:
	sf::Font font;
	sf::Text text;
public:
	TextObj(std::string str, sf::Vector2f pos) {
		font.loadFromFile(FONT_FILE_NAME);
		text.setFont(font);
		text.setCharacterSize(CHAR_SIZE);
		text.setPosition(pos);
		text.setString(str);
	}

	void update(std::string str) {
		text.setString(str);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(text);
	}
};