#include "Button.h"

void Button::Render() const
{
	//Hacemos que simplemente lo renderice por ahora
	textura->renderFrame(caja, textura->getNumRows() - 1, textura->getNumColumns() - 1);
}

void Button::Update()
{
	SDL_Point point;
	SDL_GetMouseState(&point.x, &point.y);

	//Comprobamos si el rat�n est� sobre el rect�ngulo
	encima = SDL_PointInRect(&point, &caja);
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
		if (SDL_PointInRect(&point, &caja)) {
			//Acci�n que queremos que se haga
		}
	}
}

void Button::Connect(callBack cb)
{
	//A�adimos el callback al vector
	callbacks.push_back(cb);
}
