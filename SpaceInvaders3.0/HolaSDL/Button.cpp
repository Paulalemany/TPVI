#include "Button.h"

void Button::Render() const
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);				//Color del boton ¿Amarillo?

	//dibujamos el boton
	SDL_RenderFillRect(renderer, &Rect);
}

void Button::Update()
{
	//SDL_Point point;
	//SDL_GetMouseState(&point.x, &point.y);

	////Comprobamos si el ratón está sobre el rectángulo
	//encima = SDL_PointInRect(&point, &caja);
}

void Button::save(std::ostream& out) const
{

}

//void Button::HandleEvent(const SDL_Event& event)
//{
//	//Comprueba si se hace el click izquierdo del raton
//	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
//		//posición del ratón cuando se pulsa
//		SDL_Point point{ event.button.x, event.button.y };
//
//		//Vemos si el punto está en el mismo sitio que el botón
//		if (SDL_PointInRect(&point, &caja)) {
//			//Acción que queremos que se haga
//		}
//	}
//}

void Button::Connect(callBack cb)
{
	//Añadimos el callback al vector
	/*callbacks.push_back(cb);*/
}
