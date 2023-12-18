#pragma once

#include "GameState.h"
#include "SDLApplication.h"
#include "gameList.h"

#include "SceneObject.h"
#include "MotherShip.h"
#include "Bunker.h"
#include "Laser.h"
#include "ShooterAlien.h"
#include "Ufo.h"
#include "Cannon.h"

//#include <iostream>
//#include <filesystem>
//#include <array>
#include <fstream>
#include <random>
//#include <list>
//#include <string>



//Todos los estados heredan de la clase base "GameState"
class PlayState : public GameState
{
private:
	static const std::string _playID;					//ID del PlayState

	//Lectura de archivos
	const string mapa = "..\\mapas\\original.txt",		//Ruta del mapa a utilizar
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

	//Lista de elementos del juego
	GameList<SceneObject, true> sceneObjectsList;		//Lista de objetos del juego

	//Creamos el motherShip
	MotherShip* mothership;
	//Creamos el canon
	Cannon* nave;

	mt19937_64 randomGenerator;							//Semilla del random

public:

	//Constructora
	PlayState(SDLApplication* g): GameState(g) 
	{
		mothership = new MotherShip(game, this);
	};

	void Update() override;
	void Render() override;
	
#pragma region Inicialización

	void Mapas(string file);

	void Save(const string& saveFileName) const;

	// genera un int aleatorio con un minimo y un maximo
	int getRandomRange(int min, int max);
#pragma endregion

#pragma region Input

	void HandleEvent(const SDL_Event& event) override;

	void SetScore(int s);

	void FireLaser(Point2D<double> p, bool origen);

	bool Colisiones(Laser* laser);

	void hasDied(GameList<SceneObject, true>::anchor i);

	void isGameOver();

#pragma endregion

#pragma region Máquina de estados

	bool OnEnter() override;
	bool OnExit() override;

	virtual std::string GetStateID() const { return _playID; }

#pragma endregion

};

