#pragma once
#include "SceneObject.h"

class Cannon : public SceneObject
{
private:
	enum dir { still, left, right };

	int maxCooldown = 7;			//Cooldown 
	int cooldown;					//Contador del cooldown

	int maxVidas;					//Vidas m�ximas del jugador

	int dirC = still;				//Direccion en la que se mueve el jugador
	double speed = 2;				//Velocidad a la que se mueve el jugador
	int margenCannon;				//Ancho del sprite

public:

	//Constructora vac�a
	Cannon() : SceneObject()
	{
		maxVidas = 3;
	}

	//Constructora 
	Cannon(SDLApplication* j, PlayState* ps, Point2D<double> p, Texture* t, int v, int c)
		: SceneObject(j, ps, p, t, v)
	{
		maxVidas = v;
		margenCannon = textura->getFrameWidth() / 2;

		cooldown = c;
	}

	void Render() const override;

	void Update() override;

	void save(std::ostream& out) const override;

	bool Hit(const SDL_Rect* r, bool o) override;

	void HandleEvent(SDL_Event evento);
};

