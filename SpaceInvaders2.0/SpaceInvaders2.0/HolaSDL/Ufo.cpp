#include "Ufo.h"
#include "Game.h"

void Ufo::Render() const
{
	texture->renderFrame(rect, texture->getNumRows() - 1, texture->getNumColumns() - estado);
	
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
	else {
		//Pasamos el estado a oculto
		estado = oculto;

		//Actualizamos el cooldown
		cont = getRandomRange(minCoolDown, maxCoolDown);
		pos = Vector2D<double>(800, 10);
	}
	
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
		game->SetScore(UFOScore);
     		return true;
	}
	return false;
}

int Ufo::getRandomRange(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(random);
}
