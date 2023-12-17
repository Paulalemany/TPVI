#include "GameObject.h"
#include "GameState.h"
#include "PlayState.h"


GameObject::GameObject(GameState* stat) { _gameState = stat; }

GameObject::GameObject(PlayState* game) { _gameState = game; }
