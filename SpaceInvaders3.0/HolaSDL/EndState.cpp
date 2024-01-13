#include "EndState.h"

const std::string EndState::_endID = "END";

EndState::EndState(SDLApplication* game)
	: GameState(game)
{

}

void EndState::Render()
{
	// nothing for now
}

bool EndState::OnEnter()
{
	std::cout << "Entrando al EndState" << std::endl;
	return true;
}

bool EndState::OnExit()
{
	std::cout << "Saliendo del EndState" << std::endl;
	return true;
}
