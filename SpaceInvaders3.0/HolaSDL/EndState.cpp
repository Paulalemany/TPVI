#include "EndState.h"

const string EndState::_endID = "END";

void EndState::update()
{
	// nothing for now
}

void EndState::render()
{
	// nothing for now
}

bool EndState::onEnter()
{
	cout << "Entrando al EndState" << endl;
	return true;
}

bool EndState::onExit()
{
	cout << "Saliendo del EndState" << endl;
	return true;
}
