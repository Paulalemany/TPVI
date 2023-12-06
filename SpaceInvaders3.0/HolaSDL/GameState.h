#pragma once
#include <list>
#include <ostream>

#include "EventHandler.h"
#include "Game.h"
#include "gameList.h"
#include "GameObject.h"

using namespace std;
//Oyentes del evento del estado
class addEventListener {		

};

//Para añadir objetos al estado concreto
class addObject {

};

//Maneja los estados y los lanza a quien los quiera escuchar
class GameState
{
private:

	enum _gameStates {
		_mainMenu,
		_pauseMenu,
		_playState
	};
	GameList<GameObject, true> _gameObjectsList;		// Lista de objetos de juego 
	list<EventHandler*> _lista;							// Manejador de eventos
	Game* game;											// Puntero al juego

public:
	virtual void update() = 0;
	virtual void render() const = 0;
	virtual void handleEvent(const SDL_Event&) = 0;

	void save(ostream&) const;
	void hasDied(GameList<GameObject, true>::anchor);
	void getGame() const;

};

