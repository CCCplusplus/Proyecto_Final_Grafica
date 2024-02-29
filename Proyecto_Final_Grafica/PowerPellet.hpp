#pragma once
#include "GameObject.hpp"

class PowerPellet : public GameObject
{
private:
    int posX, posY, radio;

public:
    void Draw(int x, int y, int rad, Color color)
    {
        posX = x;
        posY = y;
        radio = rad;
        if(linePoints.empty())
        FillCircle(posX, posY, radio, color);
        else
            drawPixelLinePoints(color);
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

                break; 
            }
        }
    }
};
