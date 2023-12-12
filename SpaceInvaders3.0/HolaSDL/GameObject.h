#pragma once
#include <ostream>

//Reune la funcionalidad común a todos los objetos del juego
class Game;
class GameObject
{
protected:
	Game* game;		//Puntero al juego

public:

	//Constructora vacía
	GameObject() { game = nullptr; }

	//Contructora
	GameObject(Game* g) { game = g; }

	//Métodos virtuales puros
	virtual void Render() const = 0;

	virtual void Update() = 0;

	virtual void save(std::ostream& out) const = 0;

	//Destructora virtual
	virtual ~GameObject() = default;
};

