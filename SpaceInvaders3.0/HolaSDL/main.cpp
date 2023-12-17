#include "checkML.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDLApplication.h"
#include <iostream>


using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[])
{
	//Creamos el juego
	SDLApplication game;
	//Bucle principal
	game.Run();
	SDL_Delay(500);

	return 0;
}
