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
	

	//Dependiendo del estado en el que estemos se hace una cosa u otra
	switch (_state) {
	case MENU: {
		//Ponemos el fondo del menú
		texturas[FondoMenu]->render();
		/*Button* boton = new Button(renderer, Point2D<double>(310, 200));
		boton->Render();*/
		break;
	}
	case PLAY: {
		//Ponemos el fondo del juego
		texturas[FondoJuego]->render();
		break;
		//Renderizamos todo lo referente al juego
	}
	case END: {
		//Ponemos el fondo del gameOver
		//Renderizamos todo lo referente al GameOver
	}
	case PAUSE: {
		//Ponemos el fondo del menu de pausa
		//Renderizamos todo lo referente al menu de pausa
	}
	}

	_gameStateMachine->Render();
	SDL_RenderPresent(renderer);

	//Limpiamos la pantalla
	SDL_RenderClear(renderer);
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
			throw "Error cargando SDL"s;

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

			//Creamos la máquina de estados
			_gameStateMachine = new GameStateMachine();

			//Le ponemos de estado inicial el menú de inciio
			_gameStateMachine->PushState(new MenuState(game));

			Render();
		}
	}

	
}

void SDLApplication::Texturas()
{
	//Raiz común de todas las texturas
	string textureRoot = "..\\images\\";
	string textura;

	//Struct con los datos de cada imagen a texturizar
	struct Imagen {
		string nombre;
		int filas;
		int columnas;
	};

	//Imagenes a texturizar
	Imagen FondoMenu{ "..\\fondos\\mainMenu.png", 1, 1 };

	Imagen FondoJuego{ textureRoot + "stars.png", 1, 1 };

	Imagen Nave{ textureRoot + "spaceship.png", 1, 1 };

	Imagen Bunker{ textureRoot + "bunker.png", 1, 4 };

	Imagen Alien{ textureRoot + "aliens.png", 3, 2 };

	Imagen Ufo{ textureRoot + "ufo.png", 1, 2 };

	//Creamos un array que contenga todas las imagenes (Para poder automatizarlo)
	array <Imagen, NUM_TEXTURES> Imagenes;
	Imagenes[0] = FondoMenu;
	Imagenes[1] = FondoJuego;
	Imagenes[2] = Nave;
	Imagenes[3] = Bunker;
	Imagenes[4] = Alien;
	Imagenes[5] = Ufo;

	//Hacemos un array con las texturas
	for (int i = 0; i < NUM_TEXTURES; i++) {
		//Guardamos el nombre de la textura
		textura = Imagenes[i].nombre;
		texturas[i] = new Texture(renderer, textura.c_str(), Imagenes[i].filas, Imagenes[i].columnas);

		//Si no se puede crear la textura, lanzamos una excepción
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
//				////Si se escribe algo distinto a un int, lanzar una excepción
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
//				cout << "Escriba el número de partida que desea cargar: " << endl;
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
//					cout << "El caracter no es válido, se reaunuda la partida" << endl;
//				}*/
//
//			}
//		}
//		else { //canon->HandleEvent(evento); 
//		}
//	}

}

void SDLApplication::ChangeState(int s)
{
	_state = s;
}
