#include "Game.h"
#include "RenderManager.h"
#include <iostream>

Game::Game(ResourceManager& resourceManager) : m_resourceManager(resourceManager), m_width(500), m_height(500)
{
	playerOne.Initialize();
	apple.Initialize(10, 10);
}

Game::~Game()
{
}

bool Game::Enter(unsigned int& p_width, unsigned int& p_height, std::string& p_title)
{
	p_width = this->m_width;	
	p_height = this->m_height;	
	p_title = "Snake";
	return true;
}

const void Game::Update()
{
	playerOne.Update();

	// Player colliding on theirself.
	for (size_t i = 0; i < playerOne.m_player_score; i++)
	{
		if (playerOne.trans.GetPosition() == playerOne.parts[i].trans.GetPosition())
		{
			playerOne.ResetPlayer();
		}
	}

	// Player going out of X bounds.
	if (playerOne.trans.GetX() > m_width || playerOne.trans.GetX() < 0)
	{
		playerOne.ResetPlayer();
	}

	// Player going out of Y bounds.
	if (playerOne.trans.GetY() > m_height || playerOne.trans.GetY() < 0)
	{
		playerOne.ResetPlayer();
	}

	// Player collide on apple.
	if (playerOne.trans.GetPosition() == apple.trans.GetPosition())
	{
		playerOne.m_player_score++;
		apple.trans.SetPosition((rand() % m_width / 10) * 10, (rand() % m_height / 10) * 10);
	}
}

const void Game::Render(RenderManager& renderManager)
{
	playerOne.Render(renderManager);
	apple.Render(renderManager);
}

void Game::OnKeyDown(KeyCode key)
{
	playerOne.OnKeyDown(key);
}

void Game::OnKeyUp(KeyCode key)
{
}
