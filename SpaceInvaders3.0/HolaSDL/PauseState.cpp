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

void PauseState::HandleEvent()
{
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

void PauseState::AddEventListener()
{
}

void PauseState::AddObject()
{
}
