#include "checkML.h"

#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include <iostream>


using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[])
{
	//Creamos el juego
	Game game;
	//Bucle principal
	game.Run();
	SDL_Delay(500);

	return 0;
}
