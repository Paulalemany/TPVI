#pragma once
#include "SceneObject.h"
#include "MotherShip.h"

class Alien: public SceneObject
{
protected:
	const int alienHigh = 300;		//Altura a la que deben llegar los aliens para ganar
	int indice;						//Tipo de alien
	MotherShip* mother;				//Puntero a Mothership
	int frame;						//Para decidir que frame de los dos tenemos que renderizar
	int margenAlien;				//Margen del sprite para el rebote de la pantalla
	bool bajado = false;			//Comprueba si los aliens han bajado de fila
	double speed = 5;				//Velocidad a la que se mueve el alien

	int AlienScore = 30;			//Puntos que se suman cuando se mata un alien

public:
	//Constructora vac�a
	Alien() : SceneObject() {
		indice = 0;
		mother = nullptr;
		frame = 0;
		margenAlien = 0;
	}

	//Constructora
	Alien(SDLApplication* a, PlayState* ps, Point2D<double> p, Texture* t, MotherShip* m, int v, int i, int f)
		: SceneObject(a, ps, p, t, v)
	{
		indice = i;
		frame = f;
		mother = m;
		margenAlien = t->getFrameWidth() / 2;
	}

	void Render() const override;

	virtual void Update() override;

	void save(std::ostream& out) const override;

	bool Hit(const SDL_Rect* r, bool o) override;

	//Tal vez habr�a que ponerlo tambi�n en el SceneObject en vez de aqu�
	int MargenAlien() { return margenAlien; }

	bool Bajado() { return bajado; }
};

