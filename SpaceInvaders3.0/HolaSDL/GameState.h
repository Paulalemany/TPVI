#pragma once
#include<string>
#include<iostream>
using namespace std;

class GameState
{
public:
	//Hacemos una clase abstracta base para todos los estados del juego
	//Funciones necesarias para todas las clases hijas de GameState
	virtual void update() = 0;
	virtual void render() = 0;

	//Funciones de transición entre estados
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	//Getter del ID del estado en el que esté
	virtual std::string getStateID() const = 0;
};

