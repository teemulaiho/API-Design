#include "Image.h"

Image::Image() : m_id(-1), m_width(0), m_height(0)
{
}

Image::Image(const Image& rhs) : m_id(rhs.m_id), m_width(rhs.m_width), m_height(rhs.m_height)
{
}

Image::Image(unsigned int p_id, int p_width, int p_height) : m_id(p_id), m_width(p_width), m_height(p_height)
{
}

int Image::GetID()
{
	return m_id;
}

unsigned int Image::GetWidth()
{
	return m_width;
}

unsigned int Image::GetHeight()
{
	return m_height;
}
