#include "Player.h"
#include <cmath>
#include "RenderManager.h"

const void Player::Initialize()
{
	color.SetColor(0,255,0,0);
	rect.SetBounds(0, 0, m_size, m_size);
	trans.SetPosition(m_starting_x, m_starting_y);
	m_player_score = 0;
	m_direction = MovementDirection::None;

	for (size_t i = 0; i < player_size; i++)
	{
		parts[i].color.SetColor(255, 0, 0, 0);
		parts[i].rect.SetBounds(0, 0, m_size, m_size);
		parts[i].trans.SetPosition(trans.GetX(), trans.GetY());
	}
}

const void Player::Render(RenderManager& renderManager)
{
	renderManager.Render(rect, color, trans);

	for (size_t i = 0; i < m_player_score; i++)
	{
		renderManager.Render(parts[i].rect, parts[i].color, parts[i].trans);
	}
}

const void Player::Update()
{
	m_x_array_difference[0] = trans.GetX() - parts[0].trans.GetX();
	m_y_array_difference[0] = trans.GetY() - parts[0].trans.GetY();

	for (size_t i = 1; i < (player_size - 1); i++)
	{
			m_x_array_difference[i] = parts[i].trans.GetX() - parts[i + 1].trans.GetX();
			m_y_array_difference[i] = parts[i].trans.GetY() - parts[i + 1].trans.GetY();
	}

	if (m_direction == MovementDirection::Left)
	{
		trans.ChangePosition(-m_movement_speed, 0);
		parts[0].trans.ChangePosition(m_x_array_difference[0], m_y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(m_x_array_difference[i - 1], m_y_array_difference[i - 1]);
		}
	}
	else if (m_direction == MovementDirection::Right)
	{
		trans.ChangePosition(m_movement_speed, 0);
		parts[0].trans.ChangePosition(m_x_array_difference[0], m_y_array_difference[0]);

		for (size_t i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(m_x_array_difference[i - 1], m_y_array_difference[i - 1]);
		}
	}
	else if (m_direction == MovementDirection::Up)
	{
		trans.ChangePosition(0, -m_movement_speed);
		parts[0].trans.ChangePosition(m_x_array_difference[0], m_y_array_difference[0]);

		for (size_t i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(m_x_array_difference[i - 1], m_y_array_difference[i - 1]);
		}
	}
	else if (m_direction == MovementDirection::Down)
	{
		trans.ChangePosition(0, m_movement_speed);
		parts[0].trans.ChangePosition(m_x_array_difference[0], m_y_array_difference[0]);

		for (size_t i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(m_x_array_difference[i - 1], m_y_array_difference[i - 1]);
		}
	}
}

const void Player::OnKeyDown(KeyCode key)
{
	if (key == KeyCode::LEFT_ARROW) {
		m_direction = MovementDirection::Left;
	}
	else if (key == KeyCode::RIGHT_ARROW){
		m_direction = MovementDirection::Right;
	}
	else if (key == KeyCode::UP_ARROW) {
		m_direction = MovementDirection::Up;
	}
	else if (key == KeyCode::DOWN_ARROW) {
		m_direction = MovementDirection::Down;
	}
}

const void Player::ResetPlayer()
{
	m_player_score = 0;
	m_direction = MovementDirection::None;

	trans.SetPosition(m_starting_x, m_starting_y);
}