#pragma once
#include"GameState.h"

class EndState : public GameState
{
private:
	static const std::string _endID;			//ID del endState

public:

	EndState(SDLApplication* game);

	//Todos los métodos sobrescriben los de la clase padre
	void Render() override;

	bool OnEnter() override;
	bool OnExit() override;

	virtual std::string GetStateID() const { return _endID; }
};

