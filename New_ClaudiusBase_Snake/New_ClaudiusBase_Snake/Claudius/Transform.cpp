#include "Transform.h"
#include "iostream"

Transform::Transform() : m_position(), m_rotation(0.0f)
{
}

Transform::Transform(const Transform& rhs) : m_position(rhs.m_position), m_rotation(rhs.m_rotation)
{
}

Transform::Transform(float x, float y, float rotation) : m_position(x,y), m_rotation(rotation)
{
}

void Transform::SetPosition(const float x, const float y)
{
	m_position.x = x;
	m_position.y = y;
}

void Transform::ChangePosition(const float x, const float y)
{
	m_position.x += x;
	m_position.y += y;
}

void Transform::SetRotation(const float p_rotation)
{
	this->m_rotation = p_rotation;
}

void Transform::ChangeRotation(const float rotation)
{
	this->m_rotation += rotation;
}

Vector2 Transform::GetPosition()
{
	return m_position;
}

float Transform::GetX()
{
	return m_position.x;
}

float Transform::GetY()
{
	return m_position.y;
}

float Transform::GetRotation()
{
	return m_rotation;
}
