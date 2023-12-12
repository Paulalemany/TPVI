#pragma once
#include"GameState.h"

//Todos los estados heredan de la clase base "GameState"
class MenuState : public GameState
{
private:
	static const std::string _menuID;			//ID del MenuState

public:
	//Todos los métodos sobrescriben los de la clase padre
	virtual void Update() override;
	virtual void Render() override;
	virtual void HandleEvent() override;

	virtual bool OnEnter() override;
	virtual bool OnExit() override;

	virtual void AddEventListener() override;
	virtual void AddObject() override;

	virtual std::string GetStateID() const { return _menuID; }
};


