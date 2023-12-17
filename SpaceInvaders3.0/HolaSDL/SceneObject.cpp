#include "SceneObject.h"
#include "PlayState.h"

//Le restamos vida si es golpeado
void SceneObject::Hit(const SDL_Rect* r, bool o)
{
    vida--;
}

//Guardamos la pos del objeto
void SceneObject::save(std::ostream& out) const
{
    out << pos.LeerPosX() << " " << pos.LeerPosY();
}
