#include "PlayState.h"

const string PlayState::_playID = "PLAY";

void PlayState::update()
{
	// nothing for now
}

void PlayState::render()
{
	// nothing for now
}

bool PlayState::onEnter()
{
	cout << "Entrando en PlayState" << endl;
	return true;
}

bool PlayState::onExit()
{
	cout << "Saliendo de PlayState" << endl;
	return true;
}
