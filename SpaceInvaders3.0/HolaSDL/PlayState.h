#pragma once

#include "GameState.h"

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

public:

	//Constructora
	PlayState() {};

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
#pragma endregion

#pragma region Máquina de estados

	virtual bool OnEnter() override;
	virtual bool OnExit() override;

	virtual void AddEventListener() override;
	virtual void AddObject() override;

	virtual std::string GetStateID() const { return _playID; }
#pragma endregion

	

};

