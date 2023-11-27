#include "checkML.h"
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Creamos el juego
	Game game;

	//Bucle principal del juego
	game.Run();

	SDL_Delay(500);
	return 0;
}
