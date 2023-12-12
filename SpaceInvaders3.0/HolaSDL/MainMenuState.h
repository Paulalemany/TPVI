#pragma once
#include"GameState.h"

//Todos los estados heredan de la clase base "GameState"
class MenuState : public GameState
{
private:
	static const std::string _menuID;			//ID del MenuState

public:
	//Todos los métodos sobrescriben los de la clase padre
	virtual void update() override;
	virtual void render() override;

	virtual bool onEnter() override;
	virtual bool onExit() override;

	virtual std::string getStateID() const { return _menuID; }
};


