#pragma once
#include "SceneObject.h"
#include "GameObject.h"

class Bunker: public SceneObject
{
public:
	Bunker(SDLApplication* g, PlayState* ps, Point2D<double> p, Texture* t, int v)
		: SceneObject(g, ps, p, t, v) {} ;
	void Render() const override;

	void Update() override { } ;

	bool Hit(const SDL_Rect* r, bool o) override;

	void save(std::ostream& out) const override;
};

