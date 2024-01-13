#pragma once
#include"GameState.h"
#include "checkML.h"

class EndState : public GameState
{
private:
	static const std::string _endID;			//ID del endState

	////Botones
	//Button* _exitButton;						//Boton para salir del juego
	//Button* _newGameButton;					//Boton para cargar partida

public:

	EndState(SDLApplication* game);

	//Todos los métodos sobrescriben los de la clase padre
	void Render() override;

	bool OnEnter() override;
	bool OnExit() override;
};

