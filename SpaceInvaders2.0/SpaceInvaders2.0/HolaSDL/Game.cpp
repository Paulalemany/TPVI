#include "checkML.h"
#include "Game.h"


//Bucle principal del juego
bool Game::Run()
{
	if (gameOver) return false;
	else {
		while (!gameOver) {
			//Controlamos el frameRate
			int startLoop = SDL_GetTicks();
			HandleEvents();
			Update();
			Render();
			int delta = SDL_GetTicks() - startLoop;
			if (delta < desiredDelta) {
				SDL_Delay(desiredDelta - delta);
			}
		}
		//Si sale por el gameover pierdes
		cout << "Has perdido :(";
		
	}
	SDL_Delay(2500);
	return true;
}

//Llama al resto de Renders
void Game::Render()
{
	auto i = objects.begin();
	//Limpiamos la pantalla
	SDL_RenderClear(renderer);

	//Ahora mismo no tenemos el array de texturas
	//Ponemos el fondo...
	texturas[Fondo]->render();

	for (auto i : objects) {
		i -> Render();
	}
	//renderiza
	SDL_RenderPresent(renderer);	
}

//Llama al resto de Updates
void Game::Update()
{
	mothership->ShouldMove();

	for (list<SceneObject*>::iterator ite = objects.begin(); ite != objects.end(); ite++) {
		(*ite)->Update();
	}
	EraseLista();

	//Comprobamos si algún alien ha llegado abajo
	if (gameOver == false) {
		gameOver = mothership->HaveLanded();
	}

}

void Game::SetScore(int s)
{
	//Sumamos a la puntuación actual los puntos que se consigan
	ScorePlayer += s;

	//Hacemos que escriban los puntos en consola
	cout << "Score: " << ScorePlayer << endl;
}

void Game::EraseLista()
{
	for (auto e : objectToErase) {

		delete (*e);
		e = objects.erase(e);
	}
	objectToErase.clear();
}

#pragma region Constructora

//Constructora de Game
Game::Game() {

	//Iniciamos todo
	SDL_Init(SDL_INIT_EVERYTHING);

	//Inicializa la ventana SDL
	try {
		window = SDL_CreateWindow("SpaceInvaders", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (window == nullptr || renderer == nullptr)
			throw "Error cargando SDL"s;
	}
	catch (...) {
		cerr << "No se ha podido crear la ventana SDL" << endl;
		gameOver = true;
	}
	if (!gameOver) {

		//Hay que cambiar esto para adaptar el menú
		//Cargamos todo el estado inicial del juego
		Texturas();
		//Cambiamos a gameOver si no se han encontrado las texturas
		if (!gameOver) {
			StartMenu();
			Render();
		}
	}
		

}

Game::~Game()
{
	
	//Borramos las texturas
	for (int i = 0; i < texturas.size(); i++) {
		delete texturas[i];
	}
	
	//Eliminamos los elementos de la lista de objetos
	objects.clear();

	delete mothership;

	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}
#pragma endregion

#pragma region Metodos de inicializacion

void Game::Mapas(string file)
{
	gameOver = false;
	int elem,				//Indica que vamos a crear
		posX, posY,			//Indica la posicion en la que se encuentra
		indice,				//Tipo de alien a crear
		aux;
	bool origen;
	int frame = 0;			//Podemos usarlo para pasarle el número de aliens al mothership
	list<SceneObject*>::iterator ite = objects.begin();	//Iterador de la lista
	SceneObject* o = nullptr;			//Objeto de juego que vamos a crear


	//Leemos el archivo del mapa
	ifstream Mapa;
	Mapa.open(file);

	//Si no encuentra el archivo lanzamos una excepción
	if (!Mapa.is_open()) {
		throw "No se ha podido encontrar el archivo"s;
	}
	//Mientras no haya terminado el archivo
	while (!Mapa.eof()) {
		//Leemos lo que tenemos que crear
		Mapa >> elem;
		Mapa >> posX;
		Mapa >> posY;
		Point2D<double> pos(posX, posY);

		if (elem == bunker) {
			//para leer las vidas
			Mapa >> aux;
			o = new Bunker(this, pos, texturas[Bunkers], aux);
		}
		else if (elem == laser) {
			Mapa >> origen;
			o = new Laser(this, pos, nullptr, 1, renderer, origen);
		}
		else if (elem == alien || elem == shooterAlien) {
			Mapa >> indice;
			if (elem == shooterAlien) {
				//Lo utilizamos para el coolDown
				Mapa >> elem;
				o = new ShooterAlien(this, pos, texturas[Aliens], mothership, 1, indice, frame, elem);
			}
			else {
				o = new Alien(this, pos, texturas[Aliens], mothership, 1, indice, frame);
			}
			frame++;
		}
		else if (elem == ufo) {
			//Usamos indice para guardar el estado
			Mapa >> indice;
			//Usamos aux para guardar la espera
			Mapa >> aux;
			o = new Ufo(this, pos, texturas[UFO], 1, indice, aux);
		}
		else if (elem == cannon) {
			//Lo usamos para guardar las vidas de la nave
			Mapa >> indice;
			//Lo usamos para guardar el cooldown
			Mapa >> elem;
			canon = new Cannon(this, pos, texturas[Nave], indice, elem);
			o = canon;
		}
		//ponemos los elementos que no se añaden a la lista
		else {
			if (elem == mother) {
				Mapa >> elem;
				Mapa >> indice;
				Mapa >> aux;
				//mothership = new Mothership(this);
			}
			//También contamos la puntuación
			if (elem == puntos) {
				//Guardamos los puntos actuales
				Mapa >> ScorePlayer;
			}
			objects.pop_back();
		}

		IncorporarLista(o, ite);

	}
		Mapa.close();

		//Ponemos el número de aliens en el mothership
		mothership->SetAlienCount(frame);


	//catch (...)
	//{
	//	//Si no encuentra el archivo carga un mapa predeterminado
	//	cerr << "Cargamos escena de ejemplo" << endl;
	//	Ejemplo();
	//}
	
}

void Game::Texturas()
{
	//Comun de todas las texturas
	string textureRoot = "..\\images\\";
	string textura;

#pragma region Structs

	//Creamos un struct con los datos de las imagenes
	struct Imagen {
		string nombre;
		int filas;
		int columnas;
	};

	Imagen Fondo{ textureRoot + "stars.png", 1, 1 };

	Imagen Nave{ textureRoot + "spaceship.png", 1, 1 };

	Imagen Bunker{ textureRoot + "bunker.png", 1, 4 };

	Imagen Alien{ textureRoot + "aliens.png", 3, 2 };

	Imagen Ufo{ textureRoot + "ufo.png", 1, 2 };

#pragma endregion

	//Creamos un array que contenga las imagenes
	array <Imagen, NUM_TEXTURES> Imagenes;
	Imagenes[0] = Fondo;
	Imagenes[1] = Nave;
	Imagenes[2] = Bunker;
	Imagenes[3] = Alien;
	Imagenes[4] = Ufo;

		//Rellenamos el array con las texturas
		for (int i = 0; i < NUM_TEXTURES; i++) {
			textura = Imagenes[i].nombre;
			//try {
				texturas[i] = new Texture(renderer, Imagenes[i].nombre.c_str(), Imagenes[i].filas, Imagenes[i].columnas);
				if (texturas[i] == nullptr) {
					string error = "La textura " + textura + " no se ha encontrado";
					throw error;
				}
			//}
			/*catch (...) {
				cerr << "No se ha encontrado la textura: " << textura  << " Por lo cual no se puede jugar" << endl;
				gameOver = true;
			}*/
		} 
	
}

void Game::Ejemplo()
{
	//Creamos el mapa de ejemplo
	int posX;				//Indica la columna en la que se encuentra
	int posY;				//Indica la fila en la que se encuentra
	int indice = 0;			//Tipo de alien a crear

	////Creamos dos bunkers
	//for (int i = 1; i <= 2; i++) {
	//	posX = texturas[2]->getFrameWidth() * 2.5 * i + 20;
	//	posY = 400;
	//	Point2D<int> pos(posX, posY);
	//	Bunker* b = new Bunker(pos, texturas[2]);
	//	bunkers.push_back(b);
	//}
	////Creamos 3 aliens
	//for (int i = 1; i <= 3; i++) {
	//	posX = texturas[3]->getFrameWidth() * 2 * i;
	//	posY = 50;
	//	
	//	Point2D<double> pos(posX, posY);
	//	Alien* a;
	//	if (indice == 0) {	//Es un disparador
	//		a = new ShooterAlien(pos, indice, texturas[3], this, i, getRandomRange(250, 750));
	//	}
	//	else {
	//		a = new Alien(pos, indice, texturas[3], this, i);
	//	}
	//	aliens.push_back(a);
	//	indice++;
	//}
	////Creamos una nave
	//for (int i = 1; i <= 1; i++) {
	//	posX = 400;
	//	posY = 500;
	//	Point2D<double> pos(posX, posY);
	//	Cannon* nave = new Cannon(pos, texturas[1], this);
	//	cannons.push_back(nave);
	//}

}

void Game::IncorporarLista(SceneObject* o, list<SceneObject*>::iterator ite)
{
	//Añadimos el objeto a la lista de objetos
	objects.push_back(o);

	//Le pasamos al objeto el iterador
	ite = objects.end();
	ite--;
	o->setListIterator(ite);
}

void Game::StartMenu()
{
	string _mapa;	//Nombre del archivo a abrir
	string num;		//Código del archivo
	//Frase cuando inicias el juego
	cout << "Desea cargar una partida guardada?: [y] Si, [n] No:" << endl;
	
	//elección del jugador
	char c;
	cin >> c;

	//Cargamos partida
	if (c == 'y') {
		cout << "Ingrese el codigo de la partida" << endl;
		cin >> num;
		_mapa = guardadoRoot + "saved" + num + ".txt";
		EraseLista();
	}
	else if (c == 'n') { _mapa = mapa; }

	//Si no se encuentra el archivo lanzar una excepción
	Mapas(_mapa);

}

void Game::Save(const string& saveFileName) const
{
	//Creamos un archivo donde vayamos a guardar los datos
	ofstream save(guardadoRoot + saveFileName);

	//Guardamos los diferentes datos en el archivo
	for (const auto i : objects) {
		i->save(save);
	}

	//Guardamos los puntos
	save << "7 " << ScorePlayer << endl;

	save.close();

		/*if (out.fail())
			throw "Could not find the specified save file"s;*/
}

#pragma endregion

#pragma region Input

void Game::HandleEvents()
{
	SDL_Event evento;
	list<SceneObject*>::iterator ite = objects.begin();

	//Mientras exista el evento y estemos jugando
	while (SDL_PollEvent(&evento) && !gameOver) {

		//Para no escribir todo el tiempo lo mismo
		SDL_Keycode key = evento.key.keysym.sym;

		//Para poder cerrar la propia ventana SDL
		if (evento.type == SDL_QUIT) gameOver = true;

		//Para cargar y guardar partida
		else if (evento.type == SDL_KEYDOWN && (key == SDLK_s || key == SDLK_l)) {
			//Diferenciamos el guardar y cargar
			if (SDLK_s == key) {

				//Guarda la partida actual
				cout << "Ingrese el numero de la partida: " << endl;

				int k;
				cin >> k;

				//Ahora mismo si le pone un character distinto a un int lo guarda como 0
				string fileName = "saved" + to_string(k) + ".txt";
				Save(fileName);

				cout << "Su partida se ha guardado con el nombre " << fileName << endl;

			}
			else if (key == SDLK_l) {
				//Carga una partida nueva
				
				cout << "Escriba el número de partida que desea cargar: " << endl;

				int k;
				cin >> k;

				string fileName = guardadoRoot + "saved" + to_string(k) + ".txt";
				objects.clear();
				objectToErase.clear();
				Mapas(fileName);
			}
		}
		else {
			//Colocamos el iterador en el primer elemento ya que este siempre va a ser el cañón
			//Comprobamos que efectivamente el objeto del iterador sea un cannon y si es así hacemos el método
			canon->HandleEvent(evento);
		}
	}


}

//Le pasamos quien lo lanza y donde instanciarse
void Game::FireLaser(Point2D<double> p, bool origen)
{
	list<SceneObject*>::iterator ite = objects.end();
	//Creamos un nuevo láser
	SceneObject* l = new Laser(this, p, nullptr, 1, renderer, origen);

	IncorporarLista(l, ite);
	
}

//Método damage del enunciado
bool Game::Colisiones(Laser* laser)
{
 	for (list<SceneObject*>::iterator it = objects.begin(); it != objects.end(); it++) {
		if ((*it)->Hit(laser->GetRect(), laser->Origen())) {
			return true;
		}
	}
	//Si no le da a nada devolvemos falso
	return false;
}

void Game::hasDied(list<SceneObject*>::iterator& ite)
{
	//Añadimos el objeto a eliminar a la lista de iteradores a eliminar
	objectToErase.push_back(ite);
}

#pragma endregion
