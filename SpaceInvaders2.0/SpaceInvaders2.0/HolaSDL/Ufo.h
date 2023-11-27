#pragma once
#include "SceneObject.h"
#include <random>

class Ufo : public SceneObject
{
private:
	enum state {oculto, visible, destruido};
	int estado = oculto;			//Estado del ovni
	std::mt19937_64 random;			//Generador de randoms
	int minCoolDown = 250, maxCoolDown = 750;

	int cont = 0;					//Contador del tiempo en oculto
	int speed = 5;

public:
	//Constructora vacia
	Ufo() : SceneObject() {}

	//Constructora
	Ufo(Game* j, Point2D<double> p, Texture* t, int v, int e, int c)
		: SceneObject(j, p, t, v) {
		estado = e;
		cont = c;
	}

	//Implementamos los métodos de GameObject

	void Render() const override;

	void Update() override;

	void Save() const override;

	bool Hit(const SDL_Rect* r, bool o) override;

	int getRandomRange(int min, int max);
};

