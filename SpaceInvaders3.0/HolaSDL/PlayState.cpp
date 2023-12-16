#include "PlayState.h"

const string PlayState::_playID = "PLAY";

void PlayState::Update()
{
	// nothing for now
}

void PlayState::Render()
{
	// nothing for now
}

void PlayState::Mapas(string file)
{
}

void PlayState::Save(const string& saveFileName) const
{
}

void PlayState::HandleEvent(const SDL_Event& event)
{

}

void PlayState::SetScore(int s)
{
}

void PlayState::FireLaser(Point2D<double> p, bool origen)
{
}

bool PlayState::OnEnter()
{
	cout << "Entrando en PlayState" << endl;
	return true;
}

bool PlayState::OnExit()
{
	cout << "Saliendo de PlayState" << endl;
	return true;
}

void PlayState::AddEventListener()
{
}

void PlayState::AddObject()
{
}
