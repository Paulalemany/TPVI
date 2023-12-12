#pragma once
#include <string>
#include <iostream>
#include <list>

#include "gameList.h"
using namespace std;

class GameState
{
private:
	Game* game;
	GameList<GameObject, true> gameList;
	list<EventHandler*> lista;

public:
	//Hacemos una clase abstracta base para todos los estados del juego
	//Funciones necesarias para todas las clases hijas de GameState
	virtual void update() = 0;
	virtual void render() = 0;

	//Funciones de transición entre estados
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	//Getter del ID del estado en el que esté
	virtual std::string getStateID() const = 0;
};

