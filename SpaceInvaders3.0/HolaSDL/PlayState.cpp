#include "PlayState.h"

const string PlayState::_playID = "PLAY";

void PlayState::Update()
{
	//recorremos la lista de elementos del juego
	mothership->ShouldMove();
	for (SceneObject& a : sceneObjectsList) {
		a.Update();
	}
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
				o = new ShooterAlien(game, this, pos, game->GetTexture(4), mothership, 1, indice, frame, elem);
			}
			else {
				o = new Alien(game, this, pos, game->GetTexture(4), mothership, 1, indice, frame);
			}
			frame++;
		}
		else if (elem == ufo) {
			//Usamos indice para guardar el estado
			Mapa >> indice;
			//Usamos aux para guardar la espera
			Mapa >> aux;
			o = new Ufo(game, this, pos, game->GetTexture(5), 1, indice, aux);
		}
		else if (elem == cannon) {
			//Lo usamos para guardar las vidas de la nave
			Mapa >> indice;
			//Lo usamos para guardar el cooldown
			Mapa >> elem;
			nave = new Cannon(game, this, pos, game->GetTexture(2), indice, elem);
			o = nave;
		}
		sceneObjectsList.push_back(o);

		//Elementos que no se añaden a la lista
		if (elem == mother) {
			//Sirve para indicar la dirección del mov
			Mapa >> elem;
			//Sirve para indicar el nivel
			Mapa >> aux;
			mothership->SetMove(elem);
			mothership->SetLevel(aux);
		}
		//También contamos la puntuación
		if (elem == puntos) {
			//Guardamos los puntos actuales
			Mapa >> ScorePlayer;
		}
	}

	Mapa.close();
}

void PlayState::Save(const string& saveFileName) const
{
}

int PlayState::getRandomRange(int min, int max)
{
	return uniform_int_distribution<int>(min, max)(randomGenerator);
}

void PlayState::HandleEvent(const SDL_Event& event)
{
	//Input de la nave
	nave->HandleEvent(event);

	if (SDL_SCANCODE_ESCAPE == event.key.keysym.scancode) {
		//Si el estado es igual a play permitimos entrar al menú de pausa
		game->GetMachine()->PushState(new PauseState(game));
	}
}

void PlayState::SetScore(int s)
{
}

void PlayState::FireLaser(Point2D<double> p, bool origen)
{
	SceneObject* l = new Laser(game, this, p, nullptr, 1, game->GetRenderer(), origen);

	sceneObjectsList.push_back(l);
}

bool PlayState::Colisiones(Laser* laser)
{
	return false;
}

void PlayState::hasDied()
{
	
}

void PlayState::isGameOver()
{
	gameOver = true;
	cout << "Has perdido :(";
	game->ChangeState(2);
	game->GetMachine()->ReplaceState(new EndState(game));
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

