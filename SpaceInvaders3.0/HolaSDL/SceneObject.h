#pragma once
#include "GameObject.h"
#include "texture.h"

class PlayState;
class SceneObject: public GameObject
{
protected:
	Point2D<double> pos;			//Posición del objeto instanciado

	SDL_Rect rect;					//Rect de la imagen
	Texture* textura = nullptr;		//Puntero a la textura
	int vida;						//Vida del objeto

	PlayState* _playState;			//Puntero al playState
	//No se si hace falta interador

public:

	//Constructora vacía
	SceneObject() {
		pos = Point2D<double>(0, 0);
		rect.h = rect.w = rect.x = rect.y = 0;
		vida = 1;
	}

	//Constructora
	SceneObject(PlayState* ps, Point2D<double> p, Texture* t, int v)
	: GameObject(ps)
	{
		_playState = ps;
		pos = p;
		textura = t;
		vida = v;

		//inicializamos el rect dependiendo de la textura
		if (textura != nullptr) {
			rect.w = textura->getFrameWidth();
			rect.h = textura->getFrameHeight();
		}
		else {	//Si no tiene textura significa que es un laser
			rect.w = 5;
			rect.h = 25;
		}
		
		//El objeto se dibuja en su posición
		rect.x = pos.LeerPosX();
		rect.y = pos.LeerPosY();
	}

	virtual void Hit(const SDL_Rect* r, bool o);

	void save(std::ostream& out) const override;

	//Getters para las coordenadas
	int LeerPosX() { return pos.LeerPosX(); }

	//Devuelve un puntero al rect del objeto
	const SDL_Rect* GetRect() const { return &rect; }

	//No se si hacen falta los métodos del iterator
};

