#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Game 
{
	private:
	       bool Running;
	       bool Paused;

	public:
	       Game();

	       int OnExecute();
	       bool OnInit();
	       void OnEvent(SDL_Event* Event);
	       void OnLoop();
	       void OnRender();
	       void OnCleanup();

};
