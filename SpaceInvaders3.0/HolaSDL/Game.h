#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "Bunker.h"
#include "ShooterAlien.h"
#include "Cannon.h"
#include "Laser.h"
#include "Ufo.h"

#include <iostream>
#include <filesystem>
#include <array>
#include <fstream>
#include <list>
#include <string>

#include "FileNotFoundError.h"
#include "SDLError.h"
#include "FileFormatError.h" 

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

	enum textures { Fondo, Nave, Bunkers, Aliens, UFO };			//Enum de texturas

	array <Texture*, NUM_TEXTURES> texturas;					//Array de texturas
	//Añadir la máquina de estados
	bool exit;

public:

	//Bucle principal del juego
	bool Run();

	void Render();

	void Update();

	void SetScore(int s);

	void EraseLista();

#pragma region Constructora
	//Constructora
	Game();

	//Destructora
	~Game();
#pragma endregion

#pragma region metodos de inicializacion
	void Mapas(string file);

	void Texturas();

	void IncorporarLista(SceneObject* o, list<SceneObject*>::iterator ite);

	void StartMenu();

	void Save(const string& saveFileName) const;

#pragma endregion

	int GetWinWidth() { return winWidth; }

	int GetWinHeight() { return winHeight; }

};

