#include "Button.h"

void Button::emit() const
{
	//LLama al HandleEvent de cada oyente
	for (callBack buttonCallback : callbacks) {

		buttonCallback();
	}
}

void Button::Render() const
{
	//Dependiendo del estado del rat�n lo ponemos de un color u otro
	if (currentFrame == MouseOut) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);	//Amarillo clarito
	}
	else {
		SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255);	//Amarillo oscuro
	}

	//dibujamos el boton
	SDL_RenderFillRect(renderer, &Rect);
}

void Button::Update()
{
	SDL_GetMouseState(&point.x, &point.y);

	//Comprobamos si el rat�n est� sobre el rect�ngulo
	if (SDL_PointInRect(&point, &Rect)) {
		currentFrame = MouseOver;
	}
	else { currentFrame = MouseOut; }
}

void Button::save(std::ostream& out) const
{

}

void Button::HandleEvent(const SDL_Event& event)
{
	//Comprueba si se hace el click izquierdo del raton
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
		//posici�n del rat�n cuando se pulsa
		SDL_Point point{ event.button.x, event.button.y };

		//Vemos si el punto est� en el mismo sitio que el bot�n
		if (SDL_PointInRect(&point, &Rect)) {
			emit();
		}
	}
}

void Button::Connect(callBack cb)
{
	//A�adimos el callback al vector
	callbacks.push_back(cb);
}
