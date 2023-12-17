#pragma once

#include "GameState.h"
#include "SDLApplication.h"
#include "gameList.h"

#include "SceneObject.h"
#include "Bunker.h"

#include <iostream>
#include <filesystem>
#include <array>
#include <fstream>
#include <list>
#include <string>



//Todos los estados heredan de la clase base "GameState"
class PlayState : public GameState
{
private:
	static const std::string _playID;					//ID del PlayState

	//Lectura de archivos
	const string mapa = "..\\SpaceInvaders3.0\\mapas\\original.txt",		//Ruta del mapa a utilizar
				 guardadoRoot = "..\\mapas\\";			//Ruta de partida guardada

	string savedCode = " ";								//Código de la partida guardada

	//Booleanos del juego
	bool gameOver = false;
	bool youWin = false;

	//Puntuación del jugador
	int ScorePlayer = 0;

	//Enum de los elementos
	enum elem {
		cannon, alien, shooterAlien, mother,				
		bunker, ufo, laser, puntos
	};

public:

	//Constructora
	PlayState(SDLApplication* g): GameState(g) {};

	void Update() override;
	void Render() override;
	
#pragma region Inicialización

	void Mapas(string file);

	void Save(const string& saveFileName) const;
#pragma endregion

#pragma region Input

	void HandleEvent(const SDL_Event& event) override;

	void SetScore(int s);

	void FireLaser(Point2D<double> p, bool origen);

	//bool Colisiones(Laser* laser);

	//void hasDied(list<SceneObject*>::iterator& ite);
	void hasDied();
#pragma endregion

#pragma region Máquina de estados

	bool OnEnter() override;
	bool OnExit() override;

	virtual std::string GetStateID() const { return _playID; }
#pragma endregion

	

};

