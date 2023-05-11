#pragma once
#include "gameObj.h"
class Laser : public gameObj {
private: 
	float speedx, speedy;
	 bool m_hit;
	 int damage = 10;

public: Laser(sf::Vector2f playerPos, int playerAngle) {
	texture.loadFromFile(LASER_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setRotation((float)playerAngle);
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	sprite.setPosition(playerPos);
	speedx = LASER_SPEED * (float)sin(playerAngle * PI / 180);
	speedy = -LASER_SPEED * (float)cos(playerAngle * PI / 180);
	m_hit = false;
}
	  void update() { sprite.move(speedx, speedy); }
	  void draw(sf::RenderWindow& window) { window.draw(sprite); }
	  void hit() { m_hit = true; }
	  bool getHit() { return m_hit; }
	  bool offScreen() {
		  auto laserPos = getPosition();  auto laserBounds = getHitBox();
		  if (laserPos.x < -laserBounds.width  ||  laserPos.x > WINDOW_WIDTH + laserBounds.width||
			  laserPos.y > WINDOW_HEIGHT + laserBounds.height || laserPos.y < -laserBounds.height)
		  {
			  return true;
		  }  
		  return false;
	  }
	  int getDamage() { return damage; }
};
