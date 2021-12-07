#include "Color.h"

Color::Color() : m_r(0), m_g(0), m_b(0), m_a(0) 
{
}

Color::Color(const Color& rhs) : m_r(rhs.m_r), m_g(rhs.m_g), m_b(rhs.m_b), m_a(rhs.m_a)
{
}

Color::Color(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a) : m_r(p_r), m_g(p_g), m_b(p_b), m_a(p_a)
{
}

void Color::SetColor(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a)
{
	this->m_r = p_r; this->m_g = p_g;
	this->m_b = p_b; this->m_a = p_a;
}
