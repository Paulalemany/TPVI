#pragma once

#include "GameObject.h"
#include "EventHandler.h"

#include <functional> 

// Tipo de función que recibe un evento SDL por referencia
using callBack = std::function<void(void)>;

class Button : public GameObject,
			   public EventHandler
{
private:

	Texture* textura;			//Puntero a la textura
	SDL_Rect caja;				//Rect del boton
	bool encima;

	//Callback para las funciones que se tengan que hacer al ser pulsado
	vector<callBack> callbacks;

public:
	Button(Texture* t) {
		textura = t;
		caja.w = textura->getFrameWidth();
		caja.h = textura->getFrameHeight();
	}

	void Render() const override;

	void Update() override;

	void save(std::ostream& out) const override;

	void HandleEvent(const SDL_Event& event) override;

	//Asocia los callBacks
	void Connect(callBack cb);

};

