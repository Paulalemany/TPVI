#pragma once
#include "GameState.h"


class Button;
//Todos los estados heredan de la clase base "GameState"
class MenuState : public GameState
{
private:
	static const std::string _menuID;			//ID del MenuState

	//Para poder dibujar los botones 
	SDL_Renderer* renderer;

	//Botones del menú
	Button* _playButton;
	Button* _loadButton;
	Button* _exitButton;

	//Callbacks para los botones
	void Play();
	void Load();
	void Exit();

public:

	//Contructora del menú con el renderer
	MenuState(SDLApplication* game, SDL_Renderer* r);

	//Todos los métodos sobrescriben los de la clase padre
	void Render() override;

	bool OnEnter() override;
	bool OnExit() override;

	virtual std::string GetStateID() const { return _menuID; }
};


