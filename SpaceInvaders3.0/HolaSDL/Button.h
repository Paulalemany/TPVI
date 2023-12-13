#pragma once

#include "GameObject.h"
#include "EventHandler.h"
#include "Game.h"

#include <functional> 

// Tipo de función que recibe un evento SDL por referencia
using callBack = std::function<void(void)>;


class Button : public GameObject,
			   public EventHandler
{
private:

	//Dibujo del boton
	SDL_Renderer* renderer = nullptr;	//Puntero al renderer
	const int buttonW = 175;				//Ancho del boton
	const int buttonH = 50;				//largo del boton

	SDL_Rect Rect;						//Rect del boton

	////Callback para las funciones que se tengan que hacer al ser pulsado
	//vector<callBack> callbacks;

public:
	Button() {
		
	}

	Button(SDL_Renderer* r, Vector2D<double> pos ) {
		renderer = r;

		Rect.x = pos.LeerPosX();
		Rect.y = pos.LeerPosY();

		//Dimensiones del botón
		Rect.w = buttonW;
		Rect.h = buttonH;
		
	}

	void Render() const override;

	void Update() override;

	void save(std::ostream& out) const override;

	//void HandleEvent(const SDL_Event& event) override;

	////Asocia los callBacks
	void Connect(callBack cb);

};

