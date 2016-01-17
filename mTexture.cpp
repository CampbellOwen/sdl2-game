#include "mTexture.h"
#include <SDL2/SDL.h>
#include <iostream>

mTexture::mTexture()
{
	mWidth = 0;
	mHeight = 0;
	tex = NULL;
}

mTexture::~mTexture()
{
	free();
}

bool mTexture::loadFromFile(std::string path)
{
	free();

	SDL_Texture* newTex = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "UNABLE TO LOAD IMAGE OH GOD PATH: " << path << IMG_GetError() << std::endl;
	}
	else {
		//Colour key?
		newTex = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTex == NULL) {
			std::cout << "UNABLE TO LOAD TEXTURE OH GOD PATH: " << path << IMG_GetError() << std::endl;
		}
		else {
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	tex = newTex;
	return tex!= NULL;
}

bool mTexture::loadFromText(std::string textureText, SDL_Color textColor)
{
	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL) {
		std::cout << "UNABLE TO RENDER TEXT OH GOD: " << TTF_GetError() << std::endl;
	}
	else {
		tex = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (tex == NULL) {
			std::cout << "UNABLE TO LOAD TEXTURE OH GOD PATH: " << TTF_GetError() << std::endl;
		}
		else {
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	return tex != NULL;

}

void mTexture::free()
{
	if (tex != NULL) {
		SDL_DestroyTexture(tex);
		tex = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void mTexture::render(int x, int y)
{
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};
	SDL_RenderCopy(renderer, tex, NULL, &renderQuad);
}

int mTexture::getWidth()
{
	return mWidth;
}

int mTexture::getHeight()
{
	return mHeight;
}
