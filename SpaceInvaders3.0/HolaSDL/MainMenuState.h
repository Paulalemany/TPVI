#pragma once
#include "GameState.h"
#include "Button.h"

class Button;

//Todos los estados heredan de la clase base "GameState"
class MenuState : public GameState
{
private:
	static const std::string _menuID;			//ID del MenuState

	//Para poder dibujar los botones 
	SDL_Renderer* renderer;
	Button* bb;

public:

	//Contructora del menú con el renderer
	MenuState(SDL_Renderer* r);

	//Todos los métodos sobrescriben los de la clase padre
	virtual void Update() override;
	virtual void Render() override;
	virtual void HandleEvent(const SDL_Event& event) override;

	virtual bool OnEnter() override;
	virtual bool OnExit() override;

	virtual void AddEventListener() override;
	virtual void AddObject() override;

	virtual std::string GetStateID() const { return _menuID; }
};


