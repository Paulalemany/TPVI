#pragma once
#include"GameState.h"

class EndState : public GameState
{
private:
	static const std::string _endID;			//ID del endState

	////Botones
	//Button* _exitButton;						//Boton para salir del juego
	//Button* _newGameButton;					//Boton para cargar partida

public:

	EndState(SDLApplication* game);

	//Todos los m�todos sobrescriben los de la clase padre
	void Render() override;

	bool OnEnter() override;
	bool OnExit() override;

	virtual std::string GetStateID() const { return _endID; }
};

