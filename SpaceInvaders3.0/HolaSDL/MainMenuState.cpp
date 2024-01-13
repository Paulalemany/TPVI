#include "MainMenuState.h"
#include "Button.h"

const string MenuState::_menuID = "MENU";

void MenuState::Play()
{
	//Cargamos el siguiente estado de juego (PlayState)
	game->ChangeState(1);
	game->GetMachine()->ReplaceState(new PlayState(game, "..\\mapas\\original.txt"));
}

void MenuState::Load()
{
	//Llama al método de change State para cambiar a playState pero tiene que cargar una partida nueva
	cout << "Escriba el numero de partida que desea cargar: " << endl;

	int k;
	cin >> k;
	if (k >= 0) {
		string fileName = "..\\mapas\\saved" + to_string(k) + ".txt";
		game->ChangeState(1);
		game->GetMachine()->ReplaceState(new PlayState(game, fileName));
	}
	else {
		cout << "El caracter no es válido, se reaunuda la partida" << endl;
	}
	
}

void MenuState::Exit()
{
	//Hacemos que salir sea igual a true
	game->SetExit(true);
}

MenuState::MenuState(SDLApplication* g) : GameState(g)
{
	//Creamos los diferentes botones
	//Podría crear constantes pero no lo uso tanto como para volverlo una constante creo
	_playButton = new Button(game, this, game->GetRenderer(), Point2D<double>(310, 150));
	_loadButton = new Button(game, this, game->GetRenderer(), Point2D<double>(200, 240));
	_exitButton = new Button(game, this, game->GetRenderer(), Point2D<double>(420, 240));

	//Añadimos los botones a la lista de objetos
	//(por ahora solo usaremos el playButton por lo aue voy a comentar el resto)
	AddObject(_playButton);
	AddObject(_loadButton);
	AddObject(_exitButton);

	//Los añadimos a la lista de oyentes para que reaccionen a los eventos
	AddEventListener(_playButton);
	AddEventListener(_loadButton);
	AddEventListener(_exitButton);

	//Añadimos los callbacks a los botones
	_playButton->Connect([this]() {Play(); });
	_loadButton->Connect([this]() {Load(); });
	_exitButton->Connect([this]() {Exit(); });
}

void MenuState::Render()
{
	//Hacemos el render de todos los botones en escena
	for (GameObject& g : gameList) {
		g.Render();
	}
	
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


