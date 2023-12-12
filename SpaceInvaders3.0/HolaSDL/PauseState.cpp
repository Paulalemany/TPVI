#include "PauseState.h"

const string PauseState::_pauseID = "PAUSE";

void PauseState::Update()
{
	// nothing for now
}

void PauseState::Render()
{
	// nothing for now
}

bool PauseState::OnEnter()
{
	cout << "Entrando al PauseState" << endl;
	return true;
}

bool PauseState::OnExit()
{
	cout << "Saliendo del PauseState" << endl;
	return true;
}
