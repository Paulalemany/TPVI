#include "MainMenuState.h"


const string MenuState::_menuID = "MENU";

void MenuState::Update()
{
	// nothing for now
}

void MenuState::Render()
{
	// nothing for now
}

void MenuState::HandleEvent()
{
}

bool MenuState::OnEnter()
{
	cout << "Entrando al MenuState" << endl;
	return true;
}

bool MenuState::OnExit()
{
	cout << "Saliendo del MenuState" << endl;
	return true;
}

void MenuState::AddEventListener()
{
}

void MenuState::AddObject()
{
}

