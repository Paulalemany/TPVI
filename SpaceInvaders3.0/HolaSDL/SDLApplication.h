#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"

#include "texture.h"
#include <array>

class SDLApplication
{
private:

#pragma region parámetros del juego

	static const int fps = 60,
	desiredDelta = 1000 / fps,
	//Tamaño de la pantalla
				winWidth = 800,
				winHeight = 600;

	SDL_Window* window = nullptr;				//Puntero a la ventana
	SDL_Renderer* renderer = nullptr;			//Puntero al renderer

	
#pragma endregion

#pragma region Máquina de estados
	SDLApplication* game = this;

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
	SDLApplication();

	void Texturas();
#pragma endregion

	//Update del juego
	void Update();

	//Método para Input de los estados
	void HandleEvents();

	void ChangeState(int s);


#pragma region getters y Setters

	void SetExit(bool y) { exit = y; }

	Texture* GetTexture(int i) { return texturas[i]; }

	int GetWinWidth() { return winWidth; }

	int GetWinHeight() { return winHeight; }

	SDL_Renderer* GetRenderer() { return renderer; }

	GameStateMachine* GetMachine() { return _gameStateMachine; }

#pragma endregion


};

