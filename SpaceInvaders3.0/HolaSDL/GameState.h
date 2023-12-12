#pragma once
#include <string>
#include <iostream>
#include <list>

#include "gameList.h"
using namespace std;

class GameState
{
private:
	Game* game;									//Puntero al juego
	GameList<GameObject, true> gameList;		//Lista de objetos del juego
	list<EventHandler*> lista;					//Manejadores de eventos

public:

	//Funciones necesarias para todas las clases hijas de GameState
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void HandleEvent() = 0;


	//Funciones de transici�n entre estados
	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	//Metodos para a�adir 
	virtual void AddEventListener() = 0;
	virtual void AddObject() = 0;

	//Getter del ID del estado en el que est�
	virtual std::string GetStateID() const = 0;
};

