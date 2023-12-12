#include "GameStateMachine.h"

//No estamos comprobando si la pila est� llena o vac�a en ning�n momento, podr�a dar problemas
void GameStateMachine::pushState(GameState* _state)
{
	//Introduce un nuevo elemento en lo alto de la pila
	_pilaGameStates.push(_state);

	//Hacemos el onEnter del estado que entre
	_pilaGameStates.top()->onEnter();
}

void GameStateMachine::changeState(GameState* _state)
{
	//Hacemos una fusi�n

	//Eliminamos el elemento que est� actualmente en la cima
	popState();

	//A�adimos el nuevo estado
	pushState(_state);

}

void GameStateMachine::popState()
{
	//Hacemos el onExit del elemento que est� en la cima
	_pilaGameStates.top()->onExit();

	//Lo sacamos de la pila
	_pilaGameStates.pop();

}
