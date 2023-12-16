#pragma once
#include "GameState.h"
#include <stack>

class GameStateMachine
{
private:

	//Usamos una pila para almacenar los estados
	stack <GameState*> _pilaGameStates;

public:
	//M�todos para intercambiar estados
	void PushState(GameState* pState);				//Inserta un estado

	void ReplaceState(GameState* pState);			//cambia el estado actual

	void PopState();								//Elimina un estado

	void Update();

	void Render();

	void HandleEvent(const SDL_Event& event);


};



