#pragma once
#include <list>
#include <ostream>

#include "EventHandler.h"
#include "Game.h"
#include "gameList.h"
#include "GameObject.h"

using namespace std;
class GameState
{
	//Atributos
	GameList<GameObject, true> _gameObjectsList;
	list<EventHandler*> _lista;				// Manejador de eventos
	Game* game;								// Puntero al juego

public:
	void update();
	void render() const;
	void handleEvent(const SDL_Event&);

	void save(ostream&) const;
	//void hasDied(GameList<GameObject, true>::anchor);
	void getGame() const;

	void addEventListener();
	void addObject();
};

