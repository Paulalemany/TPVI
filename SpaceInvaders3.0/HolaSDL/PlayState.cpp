#include "PlayState.h"

const string PlayState::_playID = "PLAY";

void PlayState::Update()
{
	// nothing for now
}

void PlayState::Render()
{
	// nothing for now
}

void PlayState::HandleEvent()
{
}

bool PlayState::OnEnter()
{
	cout << "Entrando en PlayState" << endl;
	return true;
}

bool PlayState::OnExit()
{
	cout << "Saliendo de PlayState" << endl;
	return true;
}

void PlayState::AddEventListener()
{
}

void PlayState::AddObject()
{
}
