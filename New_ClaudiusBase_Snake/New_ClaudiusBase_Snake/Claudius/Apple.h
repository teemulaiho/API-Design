#pragma once

#include "KeyCode.h"
#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"

struct RenderManager; 

struct Apple
{

	Apple();
	void Render(RenderManager& renderManager);
	void Initialize(unsigned int width, unsigned int height);

	Rectangle rect;
	Color color;
	Transform trans;

	bool new_apple = false;
};