#include "Player.h"

extern const int RENDER_WIDTH;
extern const int RENDER_HEIGHT;

Player::Player(mTexture* t, int x, int y)
{
	tex = t;
	this->x = x;
	this->y = y;
	accelx = 0;
	accely = 0;
	velx = 0;
	vely = 0;
}

Player::Player(mTexture* t)
{
	Player(t, RENDER_WIDTH/2, RENDER_HEIGHT/2);
}

Player::Player(int x, int u)
{
	Player(nullptr, x, y);
}

Player::Player()
{
	Player(nullptr, RENDER_WIDTH/2, RENDER_HEIGHT/2);
}

void Player::setX(int x)
{
	this->x = x;
}

void Player::setY(int y)
{
	this->y = y;
}

void Player::setAccelX(double ax)
{
	accelx = ax;
}

void Player::setAccelY(double ay)
{
	accely = ay;
}

void Player::setVelX(int vx)
{
	velx = vx;
}

void Player::setVelY(int vy)
{
	vely = vy;
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}

double Player::getAccelX()
{
	return accelx;
}

double Player::getAccelY()
{
	return accely;
}

int Player::getVelX()
{
	return velx;
}

int Player::getVelY()
{
	return vely;
}

void Player::setTexture(mTexture* t)
{
	tex = t;
}

void Player::render()
{
	tex->render(x, y);
}

void Player::update()
{
	velx += accelx;
	vely += accely;

	x += velx;
	y += vely;
}
