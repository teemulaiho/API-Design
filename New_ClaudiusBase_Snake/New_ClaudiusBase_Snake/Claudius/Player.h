#pragma once		

#include "Transform.h"
#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"

struct RenderManager;

enum class MovementDirection {
	None,
	Up,
	Right,
	Down,
	Left
};

struct Player
{
	struct PlayerPart
	{
		Transform trans;
		Color color;
		Rectangle rect;
	};

	static const int player_size = 50;
	PlayerPart parts[player_size];
	
	Transform trans;
	Color color;
	Rectangle rect;
	const void OnKeyDown(KeyCode key);
	const void Initialize();
	const void Render(RenderManager& renderManager);				
	const void Update();
	const void ResetPlayer();


	int m_size = 10;
	const float m_movement_speed = 10.0f;
	const float m_starting_x = 300.0f;
	const float m_starting_y = 300.0f;

	MovementDirection m_direction;

	bool moving_right = false;
	bool moving_left = false;
	bool moving_up = false;
	bool moving_down = false;
	bool new_snake = false;

	float m_x_array_difference[player_size] = {};
	float m_y_array_difference[player_size] = {};

	unsigned int m_player_score = 0;
};