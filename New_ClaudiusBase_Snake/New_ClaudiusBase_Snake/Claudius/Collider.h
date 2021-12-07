#pragma once

#include "Rectangle.h"

struct Collider
{
	Collider();
	Collider(const Collider& rhs);
	Collider(int p_x, int p_y, int p_w, int p_h);

	void SetBounds(int p_x, int p_y, int p_w, int p_h);

	Rectangle m_rect;
};