#include "GameStateMachine.h"

//No estamos comprobando si la pila está llena o vacía en ningún momento, podría dar problemas
void GameStateMachine::pushState(GameState* _state)
{
	//Introduce un nuevo elemento en lo alto de la pila
	_pilaGameStates.push(_state);

	//Hacemos el onEnter del estado que entre
	_pilaGameStates.top()->onEnter();
}

void GameStateMachine::changeState(GameState* _state)
{
	//Hacemos una fusión

	//Eliminamos el elemento que está actualmente en la cima
	popState();

	//Añadimos el nuevo estado
	pushState(_state);

}

void GameStateMachine::popState()
{
	//Hacemos el onExit del elemento que esté en la cima
	_pilaGameStates.top()->onExit();

	//Lo sacamos de la pila
	_pilaGameStates.pop();

}
