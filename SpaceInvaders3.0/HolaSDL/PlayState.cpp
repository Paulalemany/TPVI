#include "PlayState.h"

const string PlayState::_playID = "PLAY";

void PlayState::Update()
{
	// nothing for now
}

void PlayState::Render()
{
	//recorremos la lista de elementos del juego
	for (SceneObject& a : sceneObjectsList) {
		a.Render();
	}
}

void PlayState::Mapas(string file)
{
#pragma region Incio

	//Inicializamos todos los elementos para los objetos a crear
	int elem,							//Indica que vamos a crear
		posX, posY,						//Indica la posicion en la que se encuentra
		indice,							//Tipo de alien a crear
		aux,
		frame = 0;						//Para la animación de los aliens

	//No se si ahora también se hace con iteradores

	SceneObject* o = nullptr;			//objeto a crear
#pragma endregion

	//Abrimos el archivo a leer
	ifstream Mapa(mapa);
	/*ifstream Mapa;
	Mapa.open(mapa);*/

	//Si no encuentra el archivo lanzamos una excepción
	if (Mapa.fail()) {
		//throw FileNotFoundError("No se ha podido encontrar el archivo llamado "s + file);
	}

	//Mientras no haya terminado el archivo
	while (!Mapa.eof()) {

		//Leemos que tenemos que crear y su pos
		Mapa >> elem;
		Mapa >> posX;
		Mapa >> posY;
		Point2D<double> pos(posX, posY);		//Creamos la pos del objeto

		if (elem == bunker) {
			//para leer las vidas
			Mapa >> aux;
			o = new Bunker(game, this, pos, game->GetTexture(3), aux);
			sceneObjectsList.push_back(o);
		}
		else if (elem == laser) {
			Mapa >> aux;
			o = new Laser();
		}
		else if (elem == alien || elem == shooterAlien) {
			Mapa >> indice;
			if (elem == shooterAlien) {
				//Lo utilizamos para el coolDown
				Mapa >> elem;
				//o = new ShooterAlien(this, pos, texturas[Aliens], mothership, 1, indice, frame, elem);
			}
			else {
				o = new Alien(game, this, pos, game->GetTexture(4), mothership, 1, indice, frame);
			}
			frame++;
		}

		

	}
}

void PlayState::Save(const string& saveFileName) const
{
}

void PlayState::HandleEvent(const SDL_Event& event)
{

}

void PlayState::SetScore(int s)
{
}

void PlayState::FireLaser(Point2D<double> p, bool origen)
{
}

bool PlayState::Colisiones(Laser* laser)
{
	return false;
}

void PlayState::hasDied()
{
	cout << "Has muerto :(";
}

bool PlayState::OnEnter()
{
	cout << "Entrando en PlayState" << endl;
	//Cargamos el mapa (Por ahora que no tenemos menú de pausa lo hacemos aquí pero a lo mejor hay que cambiarlo
	Mapas(mapa);
	return true;
}

bool PlayState::OnExit()
{
	cout << "Saliendo de PlayState" << endl;
	return true;
}

