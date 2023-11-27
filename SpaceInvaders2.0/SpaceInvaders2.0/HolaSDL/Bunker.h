#pragma once

#include "SceneObject.h"

class Bunker : public SceneObject
{
private:
public:
	//Constructora vacía
	Bunker() : SceneObject() {}

	//Constructora
	Bunker(Game* j, Point2D<double> p, Texture* t, int v) 
		: SceneObject(j, p, t, v)
		//Mirar como se hacía si la constructora está vacia y solo utiliza la del padre
	{ }

	void Render() const override;	

	void Update() override;

	void Save() const override;

	//void Hit(const SDL_Rect* r, bool o) override;
};

