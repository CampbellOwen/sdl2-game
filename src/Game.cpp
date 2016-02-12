#include "Game.h"
#include <iostream>
#include "mTexture.h"
#include "Player.h"

const int RENDER_WIDTH = 1920;
const int RENDER_HEIGHT = 1080;

const int WINDOW_WIDTH = 1366;
const int WINDOW_HEIGHT = 768;

SDL_Renderer* renderer;
SDL_Window* window;

mTexture playerTexture;
Player player;

TTF_Font* gFont = NULL;
mTexture textTexture;

Game::Game()
{
	Running = false;
	renderer = NULL;
	window = NULL;
}

int Game::OnExecute()
{
	if (!OnInit()) {
		return -1;
	}
	Running = true;
	Paused = false;

	SDL_Event Event;
	
	while(Running) {
		while(SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}
		if (!Paused) {
			OnLoop();
			OnRender();
		}
	}

	return 0;
}

bool Game::OnInit() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << SDL_GetError();
		SDL_Quit();
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG != IMG_INIT_PNG) {
		std::cout << SDL_GetError();
		SDL_Quit();
		return false;
	}

	if (TTF_Init() == -1) {
		std::cout << TTF_GetError();
		SDL_Quit();
		return false;
	}

	SDL_Rect r;
	SDL_GetDisplayBounds(0, &r);
	
	window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
	if (window == nullptr) {
		std::cout << SDL_GetError();
		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << SDL_GetError();
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}
	SDL_RenderSetLogicalSize(renderer, RENDER_WIDTH, RENDER_HEIGHT);

	
	//                              LOAD TEXTURES                              //
	//
	
	playerTexture.loadFromFile("res/circle.png");
	player.setTexture(&playerTexture);
	player.setVelX(1);
	player.setVelY(1);

	gFont = TTF_OpenFont("res/font/Roboto-Regular.ttf", 28);
	if (gFont == NULL) {
		std::cout << "NO FONT OH NO" << std::endl;
	}
	else {
		SDL_Color textColor = {255,255,255};
		if (!textTexture.loadFromText("FPS: ", textColor)) {
			std::cout << "FAILED TO RENDER TEXT OH NO" << std::endl;
		}
	}
	
	return true;
}

void Game::OnEvent(SDL_Event* Event)
{
	if (Event->type == SDL_QUIT) {
		Running = false;
	}

}

void Game::OnLoop()
{
	player.update();
}

void Game::OnRender()
{
	SDL_RenderClear(renderer);

	//tex.render(400, 1000);
	player.render();
	textTexture.render(0, 0);
	
	SDL_RenderPresent(renderer);

}

void Game::OnCleanup()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	std::cout << "Exiting" << std::endl;
	SDL_Quit();
}
