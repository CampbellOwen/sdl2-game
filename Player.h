#ifndef PLAYER
#define PLAYER
#include "mTexture.h"
extern const int RENDER_WIDTH;
extern const int RENDER_HEIGHT;
class Player
{
	public:
		Player(mTexture* t, int x, int y);
		Player(mTexture* t);
		Player(int x, int y);
		Player();

		void setX(int x);
		void setY(int y);
		
		void setAccelX(double ax);
		void setAccelY(double ay);

		void setVelX(int vx);
		void setVelY(int vy);

		int getX();
		int getY();

		double getAccelX();
		double getAccelY();

		int getVelX();
		int getVelY();

		void setTexture(mTexture* t);

		void render();

		void update();

	private:
		int x;
		int y;
		double accelx;
		double accely;
		int velx;
		int vely;
		mTexture* tex;

};
#endif
