#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"

#include "texture.h"

#include <iostream>
#include <filesystem>
#include <array>
#include <fstream>
#include <list>
#include <string>

class Game
{
private:

#pragma region parámetros del juego

	static const int fps = 60,
	desiredDelta = 1000 / fps,
	//tamaño de la pantalla
				winWidth = 800,
				winHeight = 600;

	SDL_Window* window = nullptr;				//Puntero a la ventana
	SDL_Renderer* renderer = nullptr;			//Puntero al renderer

	
#pragma endregion

#pragma region Máquina de estados

	enum game_states
	{
		MENU = 0,
		PLAY = 1,
		END = 2,
		PAUSE = 3
	};

	//Estado actual del juego
	int _state;

	//Creamos un puntero a la máquina de estados dentro del game
	GameStateMachine* _gameStateMachine;
#pragma endregion

	//Texturas
	static const int NUM_TEXTURES = 6;											//Numero de texturas usadas en el juego
	enum textures {FondoMenu, FondoJuego, Nave, Bunkers, Aliens, UFO};			//Enum de texturas
	array <Texture*, NUM_TEXTURES> texturas;									//Array de texturas

	//Booleano de salida
	bool exit = false;

public:

	//Bucle principal del juego
	void Run();

	void Render();
	
#pragma region Inicio

	//Constructora de game
	Game();

	void Texturas();
#pragma endregion


	//Update del juego
	void Update();

	//Método para navegar entre los estados
	void HandleEvents();

#pragma region Getters

#pragma endregion



};

