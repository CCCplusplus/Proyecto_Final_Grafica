#pragma once
#include "GameObject.hpp"

class Pellets : public GameObject
{
private:
	int posX, posY;

    bool touched = false;


public:
	Pellets(int x, int y)
	{
		posX = x;
		posY = y;
		objectType = Bolitas;
	}

	void Draw()
	{
        if (!touched)
		    FillCircle(posX, posY, 6, RAYWHITE);
	}

    void Update(const vector<GameObject*>& otherObjects)
    {
        for (const auto& obj : otherObjects)
        {
            if (obj == this) continue;


            if (this->Collider(*obj))
            {
                // Aplica una transformación de escala para simular un efecto específico.
                ScaleMatrix(0.01f, 0.01f);
                
                touched = true;
                
                break;
            }
        }
    }
};