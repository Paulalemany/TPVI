#pragma once
#include <iostream>
#include <stack>

#include "GameState.h"
#include "Game.h"

using namespace std;

class GameStateMachine
{
	//Creamos la pila de estados de juego
	stack<GameState*> _pila;

	//Entiendo yo que los métodos tienen que ser públicos tendrán que llamarlos los estdos o algo
public:
	void pushState(GameState*) const;
	void popState();
	void replaceState(GameState*);
	void update();
	void render() const;
	void handleEvent(const SDL_Event&);
};

