#include "MainMenuState.h"


const string MenuState::_menuID = "MENU";

void MenuState::update()
{
	// nothing for now
}

void MenuState::render()
{
	// nothing for now
}

bool MenuState::onEnter()
{
	cout << "Entrando al MenuState" << endl;
	return true;
}

bool MenuState::onExit()
{
	cout << "Saliendo del MenuState" << endl;
	return true;
}

