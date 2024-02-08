#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
public:
	void Draw()
	{
		if (linePoints.empty())
			FillCircle(400, 500, 50, YELLOW);
		else
			drawPixelLinePoints(YELLOW);
	}
};