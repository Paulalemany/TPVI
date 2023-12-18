#include "checkML.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDLApplication.h"
#include <iostream>


using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[])
{
	try {
		//Creamos el juego
		SDLApplication game;
		//Bucle principal
		game.Run();
		SDL_Delay(500);
	}
	catch (FileNotFoundError& fileError)
	{
		std::cout << fileError.what() << std::endl;
	}
	catch (SDLError& SDLError)
	{
		std::cout << SDLError.what() << std::endl;
	}
	catch (FileFormatError& fileError)
	{
		std::cout << fileError.what() << std::endl;
	}

	return 0;
}
