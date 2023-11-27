#include "Ufo.h"

void Ufo::Render() const
{
	//Se puede hacer que se renderice solo si es visible para que no gaste tanto
	if (estado == visible) {
		texture->renderFrame(rect, texture->getNumRows() - 1, texture->getNumColumns() - 2);
	}
	//else if (estado == destruido) {
	//	//Animación de destruirse
	//}
	
}

void Ufo::Update()
{
	if (estado != destruido) {
		//Se mantiene oculto mientras se decrementa el contador
		if (cont > 0) {
			cont--;
		}
		else if (cont == 0) {
			estado = visible;
			//Paramos y reiniciamos el movimiento si llegamos al final
			if (pos.LeerPosX() <= 0) {
				//Pasamos el estado a oculto
				estado = oculto;

				//Actualizamos el cooldown
				cont = getRandomRange(minCoolDown, maxCoolDown);
				pos = Vector2D<double>(800, 10);
			}
			else {
				//Siempre se mueve de derecha a izquierda
				pos = pos - Vector2D<double>(speed, 0);
			}

			rect.x = pos.LeerPosX();
			rect.y = pos.LeerPosY();
		}
	}

	//Investigar como hacer lo de la animación si hay que hacer un contador o algos
	
}

void Ufo::Save() const
{
	//Guarda el estado del contador
	//Guarda el estado del bicho
}

bool Ufo::Hit(const SDL_Rect* r, bool o)
{
	//Si le golpean pasamos el estado pasa a destruido y hacemos la animación
	if (!o && SDL_HasIntersection(r, GetRect())) {
		estado = destruido;
		return true;
	}
	return false;
}

int Ufo::getRandomRange(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(random);
}
