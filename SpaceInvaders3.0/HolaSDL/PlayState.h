#pragma once
#include "GameState.h"

//Todos los estados heredan de la clase base "GameState"
class PlayState : public GameState
{
private:
	static const std::string _playID;			//ID del PlayState

public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return _playID; }

};

