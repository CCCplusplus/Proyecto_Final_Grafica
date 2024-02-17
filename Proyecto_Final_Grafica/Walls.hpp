#pragma once
#include "GameObject.hpp"

class Walls : public GameObject
{
public:


	void Draw()
	{
		if (linePoints.empty())
			drawRect(600, 300, 600, 800, 700, 800, 700, 300, BLUE);
		else
			drawPixelLinePoints(BLUE);
	}
};