#include "EndState.h"

const string EndState::_endID = "END";

void EndState::Update()
{
	// nothing for now
}

void EndState::Render()
{
	// nothing for now
}

void EndState::HandleEvent(const SDL_Event& event)
{
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

void EndState::AddEventListener()
{
}

void EndState::AddObject()
{
}
