#include "GameStateMachine.h"
using namespace std;

void GameStateMachine::pushState(GameState*) const
{
	//Introduce en la pila el estado que le den
	// No deja hacerlo porque el método es constante
	//_pila.push(GameState*);
}

void GameStateMachine::popState()
{
	//Elimina el estado que esté en la cima de la pila
	_pila.pop();
}

void GameStateMachine::replaceState(GameState*)
{
}

void GameStateMachine::update()
{
}

void GameStateMachine::render() const
{
}

void GameStateMachine::handleEvent(const SDL_Event&)
{
}
