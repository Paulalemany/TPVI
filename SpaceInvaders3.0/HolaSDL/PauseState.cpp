#include "PauseState.h"
#include "Button.h"

const string PauseState::_pauseID = "PAUSE";

void PauseState::Save()
{
	//Guarda la partida actual
	cout << "Ingrese el numero de la partida: " << endl;

	//Si se escribe algo distinto a un int, lanzar una excepción
	int k;
	cin >> k;

	//Ahora mismo si le pone un character distinto a un int lo guarda como 0
	string fileName = "saved" + to_string(k) + ".txt";

	_playState->Save(fileName);

	cout << "Su partida se ha guardado con el nombre " << fileName << endl;
	
}

void PauseState::Load()
{
	cout << "Cargando partida guardada" << endl;
	//Necesitamos pasarle el archivo de la partida guardada
	//También hay que eliminar el anterior
	game->GetMachine()->ReplaceState(new PlayState(game));
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

PauseState::PauseState(SDLApplication* game, PlayState* p)
	: GameState(game)
{
	_playState = p;

	_saveButton = new Button(game, this, game->GetRenderer(), Point2D<double>(500, 150));
	_loadButton = new Button(game, this, game->GetRenderer(), Point2D<double>(125, 150));
	_homeButton = new Button(game, this, game->GetRenderer(), Point2D<double>(500, 240));
	_returnButton = new Button(game, this, game->GetRenderer(), Point2D<double>(125, 240));

	AddObject(_saveButton);
	AddObject(_loadButton);
	AddObject(_homeButton);
	AddObject(_returnButton);

	AddEventListener(_saveButton);
	AddEventListener(_loadButton);
	AddEventListener(_homeButton);
	AddEventListener(_returnButton);

	_saveButton->Connect([this]() {Save(); });
	_loadButton->Connect([this]() {Load(); });
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


