#pragma once
#include "GameState.h"
#include <stack>

class GameStateMachine
{
private:

	//Usamos una pila para almacenar los estados
	stack <GameState*> _pilaGameStates;

public:
	//Métodos para intercambiar estados
	void pushState(GameState* pState);				//Inserta un estado

	void changeState(GameState* pState);			//cambia el estado actual

	void popState();								//Elimina un estado
};



