#pragma once
#include"GameState.h"


class EndState : public GameState
{
private:
	static const std::string _endID;			//ID del endState

public:
	//Todos los métodos sobrescriben los de la clase padre
	virtual void Update() override;
	virtual void Render() override;
	virtual void HandleEvent() override;


	//Funciones de transición entre estados
	virtual bool OnEnter() override;
	virtual bool OnExit() override;

	virtual std::string getStateID() const { return _endID; }
};

