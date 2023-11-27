#include "SceneObject.h"

bool SceneObject::Hit(const SDL_Rect* r, bool o)
{
	if (SDL_HasIntersection(r, GetRect()))
	{
		vida--;
		return true;
	}
	return false;
}
