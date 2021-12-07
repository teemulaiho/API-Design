#include "Sprite.h"

Sprite::Sprite() : source(), color(), m_image()
{
}

Sprite::Sprite(const Sprite& rhs) : source(rhs.source), color(rhs.color), m_image(rhs.m_image)
{
}

Sprite::Sprite(Image& image) : source(0, 0, 0, 0), color(0, 0, 0, 0), m_image(&image)
{
}

Sprite::Sprite(Rectangle source, Color color, Image& image) : source(source), color(color), m_image(&image)
{
}

Sprite::Sprite(int x, int y, int w, int h, Color color, Image& image) : source(x,y,w,h), color(color), m_image(&image)
{
}

Sprite::Sprite(Rectangle source, char r, char g, char b, char a, Image& image) : source(source), color(r,g,b,a), m_image(&image)
{
}

Sprite::Sprite(int x, int y, int w, int h, char r, char g, char b, char a, Image& image) : source(x,y,w,h), color(r,g,b,a), m_image(&image)
{
}

void Sprite::SetImage(Image& p_image)
{
	this->m_image = &p_image;
}

void Sprite::SetSource(int x, int y, int w, int h)
{
	source.SetBounds(x, y, w, h);
}

void Sprite::SetColor(char r, char g, char b, char a)
{
	color.SetColor(r, g, b, a);
}
