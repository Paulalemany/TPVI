#include "PauseState.h"
#include "Button.h"

const string PauseState::_pauseID = "PAUSE";

void PauseState::Save()
{
	cout << "Guardamos juego";
}

void PauseState::Home()
{
	game->GetMachine()->PopState();
	game->ChangeState(0);
	game->GetMachine()->ReplaceState(new MenuState(game));
}

void PauseState::Return()
{
	game->GetMachine()->PopState();
}

PauseState::PauseState(SDLApplication* game)
	: GameState(game)
{
	_saveButton = new Button(game, this, game->GetRenderer(), Point2D<double>(200, 240));
	_homeButton = new Button(game, this, game->GetRenderer(), Point2D<double>(420, 240));
	_returnButton = new Button(game, this, game->GetRenderer(), Point2D<double>(310, 150));

	AddObject(_saveButton);
	AddObject(_homeButton);
	AddObject(_returnButton);

	AddEventListener(_saveButton);
	AddEventListener(_homeButton);
	AddEventListener(_returnButton);

	_saveButton->Connect([this]() {Save(); });
	_homeButton->Connect([this]() {Home(); });
	_returnButton->Connect([this]() {Return(); });
}

void PauseState::Render()
{
	//Hacemos el render de todos los botones en escena
	for (GameObject& g : gameList) {
		g.Render();
	}
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


