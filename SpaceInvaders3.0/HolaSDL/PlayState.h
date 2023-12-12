#pragma once
#include "GameState.h"

//Todos los estados heredan de la clase base "GameState"
class PlayState : public GameState
{
private:
	static const std::string _playID;			//ID del PlayState

public:

	virtual void Update() override;
	virtual void Render() override;
	virtual void HandleEvent() override;

	virtual bool OnEnter() override;
	virtual bool OnExit() override;

	virtual void AddEventListener() override;
	virtual void AddObject() override;

	virtual std::string GetStateID() const { return _playID; }

};

