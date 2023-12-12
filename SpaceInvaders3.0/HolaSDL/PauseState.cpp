#include "PauseState.h"

const string PauseState::_pauseID = "PAUSE";

void PauseState::update()
{
	// nothing for now
}

void PauseState::render()
{
	// nothing for now
}

bool PauseState::onEnter()
{
	cout << "Entrando al PauseState" << endl;
	return true;
}

bool PauseState::onExit()
{
	cout << "Saliendo del PauseState" << endl;
	return true;
}
