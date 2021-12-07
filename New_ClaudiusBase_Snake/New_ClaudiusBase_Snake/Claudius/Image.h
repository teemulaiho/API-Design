#pragma once

struct Image
{
	Image();
	Image(const Image& rhs);
	Image(unsigned int p_id, int p_width, int p_height);

	int m_id;
	unsigned int m_width;
	unsigned int m_height;

	int GetID();
	unsigned int GetWidth();
	unsigned int GetHeight();
};