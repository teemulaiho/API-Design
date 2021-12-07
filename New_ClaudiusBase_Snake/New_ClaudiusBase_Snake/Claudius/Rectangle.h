#pragma once

struct Rectangle
{
	int m_x{};
	int m_y{};
	int m_w{};
	int m_h{};

	Rectangle();
	Rectangle(const Rectangle& rhs);
	Rectangle(int p_x, int p_y, int p_w, int p_h);

	void SetBounds(int p_x, int p_y, int p_w, int p_h);
};