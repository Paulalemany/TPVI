#pragma once
#include "SceneObject.h"
#include "GameObject.h"

class Bunker: public SceneObject
{
public:
	Bunker(PlayState* ps, Point2D<double> p, Texture* t, int v)
		: SceneObject(ps, p, t, v) {} ;
	void Render() const override;

	void Update() override { } ;

	void Hit(const SDL_Rect* r, bool o) override;

	void save(std::ostream& out) const override;
};

