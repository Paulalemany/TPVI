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
	for (auto e : objectToErase) {
		e = objects.erase(e);
	}
	objectToErase.clear();

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
		//Cargamos todo el estado inicial del juego
		Texturas();
		//Cambiamos a gameOver si no se han encontrado las texturas
		if (!gameOver) {
			Mapas();
			Render();
		}
	}
		

}

Game::~Game()
{

	//Eliminamos los elementos de la lista de objetos
	
	//Borramos las texturas
	for (int i = 0; i < texturas.size(); i++) {
		delete texturas[i];
	}
	
	objects.clear();

	delete mothership;

	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}
#pragma endregion

#pragma region Metodos de inicializacion

void Game::Mapas()
{
	int elem,				//Indica que vamos a crear
	 posX, posY,			//Indica la posicion en la que se encuentra
		indice,				//Tipo de alien a crear
		aux;
	int frame = 0;			//Podemos usarlo para pasarle el número de aliens al mothership
	list<SceneObject*>::iterator ite = objects.begin();	//Iterador de la lista
	SceneObject* o;			//Objeto de juego que vamos a crear

	//Leemos el archivo del mapa
	ifstream Mapa;
	Mapa.open(mapa); 

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

		//Cuando podamos rellenar con los parámetros
		if (elem == bunker) {
			//para leer las vidas
			Mapa >> aux;
			o = new Bunker(this, pos, texturas[Bunkers], aux);
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
			o = new Cannon(this, pos, texturas[Nave], indice, elem);
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

			}
			objects.pop_back();
		}

		objects.push_back(o);
		ite = objects.end();
		ite--;
		o->setListIterator(ite);
			
			/*for (int i = 0; objects.size(); i++) {
				std::cout << objects
			}*/
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
#pragma endregion

#pragma region Input
void Game::HandleEvents()
{
	list<SceneObject*>::iterator ite = objects.begin();
	//Si se pulsa alguna tecla se llama al input del cañón
	if (SDL_PollEvent(&evento)) {
		//Colocamos el iterador en el primer elemento ya que este siempre va a ser el cañón
		//Comprobamos que efectivamente el objeto del iterador sea un cannon y si es así hacemos el método
		dynamic_cast<Cannon*>(*ite)->HandleEvent(evento);
	}

}

//Le pasamos quien lo lanza y donde instanciarse
void Game::FireLaser(Point2D<double> p, bool origen)
{
	list<SceneObject*>::iterator ite = objects.end();
	//Creamos un nuevo láser
	SceneObject* l = new Laser(this, p, nullptr, 1, renderer, origen);

	//Lo añadimos a la lista de objetos
	objects.push_back(l);
	//Para colocarlo al final de la lista
	ite = objects.end();
	ite--;
	l->setListIterator(ite);
	
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
