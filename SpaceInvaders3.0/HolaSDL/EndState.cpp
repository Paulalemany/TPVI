#include "EndState.h"

const string EndState::_endID = "END";

EndState::EndState(SDLApplication* game)
	: GameState(game)
{

}

void EndState::Render()
{
	// nothing for now
}

bool EndState::OnEnter()
{
	cout << "Entrando al EndState" << endl;
	return true;
}

bool EndState::OnExit()
{
	cout << "Saliendo del EndState" << endl;
	return true;
}
