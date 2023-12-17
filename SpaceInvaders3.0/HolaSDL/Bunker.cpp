#include "Bunker.h"
#include "PlayState.h"


void Bunker::Render() const
{
	textura->renderFrame(rect, textura->getNumRows() - 1, 4 - vida);
}

 bool Bunker::Hit(const SDL_Rect* r, bool o)
{
	//Al ser un bunker nos da igual el origen del laser
	 if (SDL_HasIntersection(r, GetRect())) { 
		 SceneObject::Hit(r, o);
		 return true; 
	 }

	//Si se queda sin vidas llama al hasDied del estado en el que est�
	if (vida == 0) { _playState->hasDied(); }
	
}

void Bunker::save(std::ostream& out) const
{
	out << "4 ";
	SceneObject::save(out);
	out << " " << vida << endl;
}
