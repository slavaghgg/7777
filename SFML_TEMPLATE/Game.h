#pragma once
#include "gameObj.h" 
#include <vector> 
#include <list> 
#include "Player.h" 
#include "Player1.h" 
#include "sandObj.h" 
#include "HpBar.h"
#include "HP_BAR.h"
#include "Lives.h"
#include "textObj.h"


enum GameStatus { PLAY, GAME_OVER };
class Game {
private:
	sf::RenderWindow window;
	Player player;
	Player1 player1;
	SandObj sand;
	Hp_Bar hpbar;
	HpBar hpbar1;
	std::list<Lives*>lives;
	std::list<Lives*>lives1;
	TextObj gameovertext;
	GameStatus game = PLAY;

public:

	Game() :gameovertext("GAME_OVER",TEXT_START_POS) {
		window.create(sf::VideoMode{ (size_t)WINDOW_WIDTH, (size_t)WINDOW_HEIGHT }, WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		for (size_t i = 0; i < MAX_PLAYER_LIVES; i++) {
			float xPos = 5.f;
			float yPos = 50.f;
			Lives* life = new Lives(sf::Vector2f{ xPos + i * 48.f, yPos });
			lives.push_back(life);
		}
		for (size_t i = 0; i < MAX_PLAYER_LIVES; i++) {
			float xPos = 1000.f;
			float yPos = 50.f;
			Lives* life1 = new Lives(sf::Vector2f{ xPos + i * 48.f, yPos });
			lives1.push_back(life1);
		}

	}

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		switch (game) {
		case PLAY: {
			player.update();
			player1.update();
			hpbar.update(player.getHp());
			hpbar1.update(player1.getHp());
		}
		}

	}

	void checkCollisions() {
		switch (game) {
		case PLAY: {
			auto laser1Sprites = player1.getLasers();
			for (auto laser1 : (*laser1Sprites)) {
				sf::FloatRect playerBounds = player.getHitBox();
				sf::FloatRect laser1Bounds = laser1->getHitBox();
				if (playerBounds.intersects(laser1Bounds)) {
					player.decreaseHp(laser1->getDamage());
					laser1->hit();
					if (player.getHp() < 0) {
						player.playerMinusLife();
						if (player.getlives() == 0) {
							game = GAME_OVER;
						}
						player.restoreHp();
						lives1.pop_back();
					}

				}
			}
			(*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
			(*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
		
		

			sf::FloatRect player1Bounds = player1.getHitBox();
			auto laserSprites = player.getLasers();
			for (auto laser : (*laserSprites)) {
				sf::FloatRect laserBounds = laser->getHitBox();
				if (laserBounds.intersects(player1Bounds)) {
					player1.decreaseHp(laser->getDamage());
					laser->hit();
					if (player1.getHp() < 0) {
						player1.playerMinusLife();
						if (player1.getlives() == 0) {
							game = GAME_OVER;

						}						
						player1.restoreHp();
						lives.pop_back();
					}
				}
			}

			(*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
			(*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
		}
		}
		

	}

	void draw() {
		switch (game) {
		case PLAY: {
			window.clear();



			sand.draw(window);
			player.draw(window);
			player1.draw(window);
			hpbar.draw(window);
			hpbar1.draw(window);
			for (auto& life : lives) {
				life->draw(window);
			}
			for (auto& life1 : lives1) {
				life1->draw(window);
			}


			window.display();
			break;
		case GAME_OVER:
			window.clear();
			gameovertext.draw(window);
			window.display();
			break;
		}
		}
	}



	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}

};