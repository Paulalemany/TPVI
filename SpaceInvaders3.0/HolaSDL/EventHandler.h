#pragma once

#include "Game.h"

class EventHandler
{
public:
	virtual void HandleEvent(const SDL_Event& event) = 0;
};

