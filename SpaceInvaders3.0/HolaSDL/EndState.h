#pragma once
#include"GameState.h"

class EndState : public GameState
{
private:
	static const std::string _endID;			//ID del endState

public:
	//Todos los métodos sobrescriben los de la clase padre
	void Update() override;
	void Render() override;
	void HandleEvent(const SDL_Event& event) override;

	bool OnEnter() override;
	bool OnExit() override;

	virtual std::string GetStateID() const { return _endID; }
};

