#pragma once

#include "GameState.h"
#include "SceneObject.h"

#include "Bunker.h"
#include "ShooterAlien.h"
#include "Cannon.h"
#include "Laser.h"
#include "Ufo.h"


using namespace std;

class PlayState : public GameState
{
private:


	string mapa = "..\\mapas\\original.txt";					//Ruta del mapa a utilizar
	string guardadoRoot = "..\\mapas\\";						//Ruta de partida guardada
	string savedCode = " ";										//Código de la partida guardada

	bool gameOver = false;										//booleano fin del juego
	bool youWin = false;
	int ScorePlayer = 0;

	enum elem {
		cannon, alien, shooterAlien, mother,					//Enum de los elementos
		bunker, ufo, laser, puntos
	};

	//Mothership* mothership = new Mothership();				//Puntero al mothership
	Cannon* canon = new Cannon();

	GameList<SceneObject> _Objects;								//Lista de objetos en la escena
	//list<SceneObject*> objects;									//Lista de objetos del juego
	//list<list<SceneObject*>::iterator> objectToErase;			//Lista de objetos a eliminar

	

public:

	void HandleEvents();

	void FireLaser(Point2D<double> p, bool origen);

	bool Colisiones(Laser* laser);

	void IsGameOver() { gameOver = true; }

	void hasDied(list<SceneObject*>::iterator& ite);


	bool GameOver() { return gameOver; }

	int CannonHeight() { return canon->LeerPosX(); }
};

