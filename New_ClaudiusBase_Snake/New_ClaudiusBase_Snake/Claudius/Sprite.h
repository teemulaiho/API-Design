#pragma once

#include "Rectangle.h"
#include "Color.h"

struct Image;

struct Sprite
{
	Sprite();
	Sprite(const Sprite& rhs);
	Sprite(Image& image);
	Sprite(Rectangle source, Color color, Image& image);
	Sprite(int x, int y, int w, int h, Color color, Image& image);
	Sprite(Rectangle source, char r, char g, char b, char a, Image& image);
	Sprite(int x, int y, int w, int h, char r, char g, char b, char a, Image& image);
	
	void SetImage(Image& p_image);
	void SetSource(int x, int y, int w, int h);
	void SetColor(char r, char g, char b, char a);

	Rectangle source;
	Color color;
	const Image* m_image;
};