#pragma once
#include "GameObject.hpp"

class Enemy : public GameObject
{
public:

	void Draw()
	{
		if (linePoints.empty())
			FillTriangleMaxMin(100, 100, 200, 100, 150, 50, RED);
		else
			drawPixelLinePoints(RED);
	}
};