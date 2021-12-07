#pragma once
#include "SDL_stdinc.h"

struct Color
{
	Uint8 m_r;
	Uint8 m_g;
	Uint8 m_b;
	Uint8 m_a;

	Color();
	Color(const Color& rhs);
	Color(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a);

	void SetColor(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a);
};