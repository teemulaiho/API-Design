#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"
#include "SDL_stdinc.h"

struct RenderManager;
struct ResourceManager;

class Game
{
	Player playerOne;
	Apple apple;

	ResourceManager& m_resourceManager;

public:

	unsigned int m_width;
	unsigned int m_height;

	Game(ResourceManager& resourceManager);
	~Game();
	bool Enter(unsigned int& p_width, unsigned int& p_height, std::string& p_title);
	const void Update();
	const void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
	void OnKeyUp(KeyCode key);
};