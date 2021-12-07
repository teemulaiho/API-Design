#pragma once

#include "Vector2.h"

struct Transform
{
	Transform();
	Transform(const Transform& rhs);
	Transform(float p_x, float p_y, float p_rotation);
	
	void SetPosition(const float p_x, const float p_y);
	void ChangePosition(const float p_x, const float p_y);
	void SetRotation(const float p_rotation);
	void ChangeRotation(const float rotation);

	Vector2 GetPosition();
	float GetX();
	float GetY();
	float GetRotation();

	Vector2 m_position;
	float m_rotation;
};