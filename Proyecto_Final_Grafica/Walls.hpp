#pragma once
#include "GameObject.hpp"

class Walls : public GameObject
{
public:

	int posx, posy, width, height;

	Walls(int x, int y, int w, int h)
	{
		posx = x;
		posy = y;
		width = w;
		height = h;
		objectType = Paredes;
	}

	void Draw()
	{
		drawRect(posx, posy, posx, height + posy, width + posx, height + posy, width + posx, posy, BLUE);
	}
};