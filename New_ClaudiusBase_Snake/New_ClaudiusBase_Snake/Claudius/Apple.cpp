#pragma once

#include <iostream>
#include "Apple.h"
#include "RenderManager.h"

Apple::Apple()
{

}

void Apple::Initialize(unsigned int width, unsigned int height)
{
	color.SetColor(0, 255, 0, 0);
	rect.SetBounds(0, 0, width, height);
	trans.SetPosition(100, 200);
}

void Apple::Render(RenderManager& renderManager)
{
	renderManager.Render(rect, color, trans);
}


