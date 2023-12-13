#include "MainMenuState.h"


const string MenuState::_menuID = "MENU";

void MenuState::Update()
{
	// nothing for now
}

void MenuState::Render()
{
	Button* boton = new Button(renderer, Point2D<double>(310, 200));
	boton->Render();
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

