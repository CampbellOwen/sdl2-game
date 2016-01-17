#ifndef TEXTURE
#define TEXTURE
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

extern SDL_Renderer* renderer;
extern TTF_Font* gFont;
class mTexture
{
	public:
		mTexture();

		~mTexture();

		bool loadFromFile( std::string path );

		bool loadFromText(std::string textureText, SDL_Color textColor);

		void free();

		void render(int x, int y);

		int getWidth();
		
		int getHeight();
	
	private:
		SDL_Texture* tex;
		int mWidth;
		int mHeight;
};
#endif
