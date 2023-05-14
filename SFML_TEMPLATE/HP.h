#pragma once
#include "settings.h"
class HpBar {
private:
	sf::RectangleShape frame;
	sf::RectangleShape hpBar;
	float hpBar_WIDTH;
public:
	HpBar() {
		hpBar.setSize(sf::Vector2f{ FRAME_WIDTH,FRAME_HEIGHT });
		hpBar.setFillColor(sf::Color{ sf::Color::Green });
		hpBar.setPosition(sf::Vector2f{ 7.f, 7.f });

		frame.setSize(sf::Vector2f{ FRAME_WIDTH+4,FRAME_HEIGHT+4 });
		frame.setOutlineColor(sf::Color::White);
		frame.setOutlineThickness(2);
		frame.setFillColor(sf::Color::Black);		
		frame.setPosition(sf::Vector2f{ 5.f, 5.f });
			
	}
	void update(int player_HP) {
		if (player_HP < 0) {
			hpBar_WIDTH = 0;
		}
		else {
			hpBar_WIDTH = player_HP / 100.f * FRAME_WIDTH;
		}
		
		hpBar.setSize(sf::Vector2f{ hpBar_WIDTH,FRAME_HEIGHT });

	}
	void draw(sf::RenderWindow& window) {
		
		window.draw(frame);
		window.draw(hpBar);
	}


};
