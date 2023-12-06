#include "PlayState.h"

void PlayState::Render()
{
	//auto i = objects.begin();
	////Limpiamos la pantalla
	//SDL_RenderClear(renderer);

	////Ahora mismo no tenemos el array de texturas
	////Ponemos el fondo...
	//texturas[Fondo]->render();

	//for (auto i : objects) {
	//	i->Render();
	//}
	////renderiza
	//SDL_RenderPresent(renderer);
}

void PlayState::HandleEvents()
{
	//SDL_Event evento;
	//list<SceneObject*>::iterator ite = objects.begin();

	////Mientras exista el evento y estemos jugando
	//while (SDL_PollEvent(&evento) && !gameOver) {

	//	//Para no escribir todo el tiempo lo mismo
	//	SDL_Keycode key = evento.key.keysym.sym;

	//	//Para poder cerrar la propia ventana SDL
	//	if (evento.type == SDL_QUIT) youWin = true;

	//	//Para cargar y guardar partida
	//	else if (evento.type == SDL_KEYDOWN && (key == SDLK_s || key == SDLK_l)) {
	//		//Diferenciamos el guardar y cargar
	//		if (SDLK_s == key) {

	//			//Guarda la partida actual
	//			cout << "Ingrese el numero de la partida: " << endl;

	//			//Si se escribe algo distinto a un int, lanzar una excepción
	//			int k;
	//			cin >> k;

	//			//Ahora mismo si le pone un character distinto a un int lo guarda como 0
	//			string fileName = "saved" + to_string(k) + ".txt";
	//			Save(fileName);

	//			cout << "Su partida se ha guardado con el nombre " << fileName << endl;

	//		}
	//		else if (key == SDLK_l) {
	//			//Carga una partida nueva

	//			cout << "Escriba el número de partida que desea cargar: " << endl;

	//			int k;
	//			cin >> k;
	//			if (k >= 0) {
	//				string fileName = guardadoRoot + "saved" + to_string(k) + ".txt";
	//				objects.clear();
	//				objectToErase.clear();
	//				Mapas(fileName);
	//			}
	//			else {
	//				cout << "El caracter no es válido, se reaunuda la partida" << endl;
	//			}

	//		}
	//	}
	//	else { canon->HandleEvent(evento); }
	//}


}

//Le pasamos quien lo lanza y donde instanciarse
void PlayState::FireLaser(Point2D<double> p, bool origen)
{
	//list<SceneObject*>::iterator ite = objects.end();
	////Creamos un nuevo láser
	//SceneObject* l = new Laser(this, p, nullptr, 1, renderer, origen);

	//IncorporarLista(l, ite);

}

//Método damage del enunciado
bool PlayState::Colisiones(Laser* laser)
{
	/*for (list<SceneObject*>::iterator it = objects.begin(); it != objects.end(); it++) {
		if ((*it)->Hit(laser->GetRect(), laser->Origen())) {
			return true;
		}
	}*/
	//Si no le da a nada devolvemos falso
	return false;
}

void PlayState::hasDied(list<SceneObject*>::iterator& ite)
{
	//Añadimos el objeto a eliminar a la lista de iteradores a eliminar
	/*objectToErase.push_back(ite);*/
}
