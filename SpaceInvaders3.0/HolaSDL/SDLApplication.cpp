#include "SDLApplication.h"


void SDLApplication::Run()
{
	while (!exit) {

		//Controlamos el frame rate del juego
		int startLoop = SDL_GetTicks();

		//Bucle del propio juego
		HandleEvents();
		Update();
		Render();

		int delta = SDL_GetTicks() - startLoop;
		if (delta < desiredDelta) {
			SDL_Delay(desiredDelta - delta);
		}
	}
}

void SDLApplication::Render()
{
	

	//Dependiendo del estado en el que estemos ponemos un fondo u otro
	switch (_state) {
	case MENU: {
		//Ponemos el fondo del men�
		texturas[FONDOMENU]->render();
		break;
	}
	case PLAY: {
		//Ponemos el fondo del juego
		texturas[FONDOJUEGO]->render();
		break;
	}
	}

	_gameStateMachine->Render();
	SDL_RenderPresent(renderer);

	//Limpiamos la pantalla
	SDL_RenderClear(renderer);
}

SDLApplication::~SDLApplication()
{
	delete _gameStateMachine;
	for (const auto i : texturas) delete i;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//Constructora
SDLApplication::SDLApplication()
{
	//Iniciamos todo
	SDL_Init(SDL_INIT_EVERYTHING);

	//Inicializa la ventana SDL
		window = SDL_CreateWindow("SpaceInvaders", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (window == nullptr || renderer == nullptr)
			//throw "Error cargando SDL"s;

	//Quitar este catch y capturarlo en el main
	/*catch (...) {
		cerr << "No se ha podido crear la ventana SDL" << endl;
		exit = true;
	}*/
	if (!exit) {

		//Cargamos todo el estado inicial del juego
		Texturas();
		//Cambiamos a gameOver si no se han encontrado las texturas

		if (!exit) {
			//Inicializamos el estado actual al primer estado
			_state = MENU;

			//Creamos la m�quina de estados
			_gameStateMachine = new GameStateMachine();

			//Le ponemos de estado inicial el men� de inciio
			_gameStateMachine->PushState(new MenuState(game));

			Render();
		}
	}
}

void SDLApplication::Texturas()
{
	//Raiz com�n de todas las texturas
	std::string textureRoot = "..\\images\\";
	std::string objectRoot = "..\\objetos\\";
	std::string textura;

	//Struct con los datos de cada imagen a texturizar
	struct Imagen {
		std::string nombre;
		int filas;
		int columnas;
	};

	//Imagenes a texturizar
	Imagen _FondoMenu{ "..\\fondos\\mainMenu.png", 1, 1 };

	Imagen _FondoJuego{ textureRoot + "stars.png", 1, 1 };

	Imagen _Nave{ textureRoot + "spaceship.png", 1, 1 };

	Imagen _Bunker{ textureRoot + "bunker.png", 1, 4 };

	Imagen _Alien{ textureRoot + "aliens.png", 3, 2 };

	Imagen _Ufo{ textureRoot + "ufo.png", 1, 2 };

	Imagen _Bomb{ objectRoot + "bomb.png", 1, 1 };

	Imagen _Shield{ objectRoot + "shield.png", 1, 1 };

	Imagen _S_Reward{ objectRoot + "shield_reward.png", 1, 1 };

	//Creamos un array que contenga todas las imagenes (Para poder automatizarlo)
	std::array <Imagen, NUM_TEXTURES> Imagenes;
	Imagenes[FONDOMENU] = _FondoMenu;
	Imagenes[FONDOJUEGO] = _FondoJuego;
	Imagenes[NAVE] = _Nave;
	Imagenes[BUNKERS] = _Bunker;
	Imagenes[ALIENS] = _Alien;
	Imagenes[UFO] = _Ufo;
	Imagenes[BOMB] = _Bomb;
	Imagenes[SHIELD] = _Shield;
	Imagenes[S_REWARD] = _S_Reward;

	//Hacemos un array con las texturas
	for (int i = 0; i < NUM_TEXTURES; i++) {
		//Guardamos el nombre de la textura
		textura = Imagenes[i].nombre;
		texturas[i] = new Texture(renderer, textura.c_str(), Imagenes[i].filas, Imagenes[i].columnas);

		//Si no se puede crear la textura, lanzamos una excepci�n
		if (texturas[i] == nullptr) {
			throw "La textura " + textura + " no se ha encontrado";
		}
	}
}

void SDLApplication::Update() {

	_gameStateMachine->Update();
}

void SDLApplication::HandleEvents()
{
	SDL_Event evento;

	while (SDL_PollEvent(&evento) && !exit) {
		if (evento.type == SDL_QUIT) {

			exit = true;
		}
		else {
			_gameStateMachine->HandleEvent(evento);
		}
	}
	
//	//Mientras exista el evento y estemos jugando
//	while (SDL_PollEvent(&evento) && !exit) {
//
//		//Para no escribir todo el tiempo lo mismo
//		SDL_Keycode key = evento.key.keysym.sym;
//
//		//Para poder cerrar la propia ventana SDL
//		if (evento.type == SDL_QUIT) exit = true;
//
//		//Probamos para cambiar de estado
//		else if (evento.type == SDL_KEYDOWN && key == SDLK_t) {
//			//Se cambia de estado :)
//			_gameStateMachine->ReplaceState(new PlayState());
//			_state = PLAY;
//		}
//		//Para cargar y guardar partida
//		else if (evento.type == SDL_KEYDOWN && (key == SDLK_s || key == SDLK_l)) {
//			//Diferenciamos el guardar y cargar
//			if (SDLK_s == key) {
//
//				//Guarda la partida actual
//				cout << "Ingrese el numero de la partida: " << endl;
//
//				////Si se escribe algo distinto a un int, lanzar una excepci�n
//				//int k;
//				//cin >> k;
//
//				////Ahora mismo si le pone un character distinto a un int lo guarda como 0
//				//string fileName = "saved" + to_string(k) + ".txt";
//				////Save(fileName);
//
//				cout << "Su partida se ha guardado con el nombre " 
//					//<< fileName 
//					<< endl;
//
//			}
//			else if (key == SDLK_l) {
//				//Carga una partida nueva
//
//				cout << "Escriba el n�mero de partida que desea cargar: " << endl;
//
//				int k;
//				cin >> k;
//				if (k >= 0) {
//					string fileName = guardadoRoot + "saved" + to_string(k) + ".txt";
//					objects.clear();
//					objectToErase.clear();
//					Mapas(fileName);
//				}
//				else {
//					cout << "El caracter no es v�lido, se reaunuda la partida" << endl;
//				}*/
//
//			}
//		}
//		else { //canon->HandleEvent(evento); 
//		}
//	}

}

void SDLApplication::ChangeState(int s) { _state = s; }
