#pragma once
#include "GameState.h"
#include "Button.h"

//Todos los estados heredan de la clase base "GameState"
class MenuState : public GameState
{
private:
	static const std::string _menuID;			//ID del MenuState

	//Puntero al juego para coger el renderer
	Game* game;

	SDL_Renderer* renderer;

public:

	//Contructora del menú con el renderer
	MenuState(SDL_Renderer* r) {
		renderer = r;
	}
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


