#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "Bunker.h"
#include "ShooterAlien.h"
#include "Cannon.h"
#include "Laser.h"
#include "Ufo.h"
//#include "Mothership.h"

//No se si habrá que quitar alguno de estos 
//#include <iterator>
#include <iostream>
#include <array>
#include <fstream>
#include <list>

using namespace std;
class SceneObject;
class Game
{
private:

	static const int fps = 60;
	int desiredDelta = 1000 / fps;

	static const int NUM_TEXTURES = 5,			//Numero de texturas usadas en el juego
		ALIENS_UPDATE = fps * 1;				//60 es el fps que está declarado en el main

	SDL_Window* window = nullptr;				//Puntero a la ventana
	SDL_Renderer* renderer = nullptr;			//Puntero al renderer

	//tamaño de la pantalla
	int winWidth = 800;
	int winHeight = 600;

	string mapa = "..\\mapas\\original.txt";			//Ruta del mapa a utilizar
	bool gameOver = false;								//booleano fin del juego
	int ScorePlayer = 0;

	enum textures {Fondo, Nave, Bunkers, Aliens, UFO};	//Enum de texturas
	enum elem {cannon, alien, shooterAlien, mother,		//Enum de los elementos
		bunker, ufo, laser, puntos};				
	
	array <Texture*, NUM_TEXTURES> texturas;			//Array de texturas
	Mothership* mothership = new Mothership(this);		//Puntero al mothership
	list<SceneObject*> objects;							//Lista de objetos del juego
	list<list<SceneObject*>::iterator> objectToErase;	//Lista de objetos a eliminar
	
	//Input
	SDL_Event evento;

public:

		//Bucle principal del juego
		bool Run();
	
		void Render();
	
		void Update();
	
		bool GameOver() { return gameOver; }

		void SetScore(int s);

#pragma region Constructora
		//Constructora
		Game();

		//Destructora
		~Game();
#pragma endregion
	
#pragma region metodos de inicializacion
	void Mapas();

	void Texturas();

	void Ejemplo();

	int GetWinWidth() { return winWidth; }

	int GetWinHeight() { return winHeight; }

#pragma endregion

#pragma region input
	void HandleEvents();	

	void FireLaser(Point2D<double> p, bool origen);	

	bool Colisiones(Laser* laser);

	void IsGameOver() { gameOver = true; }

	void hasDied(list<SceneObject*>::iterator& ite);
#pragma endregion
};

