#pragma once
#include"GameState.h"

class PauseState : public GameState
{
private:
	static const std::string _pauseID;			//ID del PauseState

public:
	//Todos los métodos sobrescriben los de la clase padre
	virtual void update() override;
	virtual void render() override;

	virtual bool onEnter() override;
	virtual bool onExit() override;

	virtual std::string getStateID() const { return _pauseID; }
};

