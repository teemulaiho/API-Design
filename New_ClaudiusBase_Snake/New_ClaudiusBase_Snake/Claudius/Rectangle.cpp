#include "Rectangle.h"

Rectangle::Rectangle() : m_x(0), m_y(0), m_w(0), m_h(0)
{
}

Rectangle::Rectangle(const Rectangle& rhs) : m_x(rhs.m_x), m_y(rhs.m_y), m_w(rhs.m_w), m_h(rhs.m_h)
{
}

Rectangle::Rectangle(int p_x, int p_y, int p_w, int p_h) : m_x(p_x), m_y(p_y), m_w(p_w), m_h(p_h)
{
}

void Rectangle::SetBounds(int p_x, int p_y, int p_w, int p_h)
{
	this->m_x = p_x; this->m_y = p_y; this->m_w = p_w; this->m_h = p_h;
}
