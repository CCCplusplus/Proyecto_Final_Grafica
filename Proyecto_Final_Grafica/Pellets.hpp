#pragma once
#include "GameObject.hpp"

class Pellets : public GameObject
{
private:
	int posX, posY;

public:
	Pellets(int x, int y)
	{
		posX = x;
		posY = y;
		objectType = Bolitas;
	}

	void Draw()
	{
			FillCircle(posX, posY, 8, RAYWHITE);
	}
};