#include "MainMenuState.h"

const string MenuState::_menuID = "MENU";

MenuState::MenuState(SDL_Renderer* r)
{
	renderer = r;
	bb = new Button(renderer, Point2D<double>(310, 200));
}

void MenuState::Update()
{
	bb->Update();
}

void MenuState::Render()
{
	bb->Render();
}

void MenuState::HandleEvent(const SDL_Event& event)
{
	bb->HandleEvent(event);
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

