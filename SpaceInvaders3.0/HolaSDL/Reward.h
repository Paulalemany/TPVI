#pragma once
#include "SceneObject.h"

class Reward : public SceneObject
{
private:

	Vector2D<double> vel;				//Vector velocidad del objeto
	double v = 5;						//Velocidad del objeto al caer

public:
	//Constructora vacía
	Reward() : SceneObject() { }

	//Constructora
	Reward(SDLApplication* g, PlayState* j, Point2D<double> p, Texture* t, int vida)
		: SceneObject(g, j, p, t, vida) 
	{
		vel = Vector2D<double>(0, v);
	}

	void Render() const override;

	void Update() override;

	void save(std::ostream& out) const override;

	bool Hit(const SDL_Rect* r, bool o) override;
};

