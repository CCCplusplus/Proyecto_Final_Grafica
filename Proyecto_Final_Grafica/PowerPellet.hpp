#pragma once
#include "GameObject.hpp"

class PowerPellet : public GameObject
{
private:
    int posX, posY, radio;

    bool touched = false;

public:
    void Draw(int x, int y, int rad, Color color)
    {
        posX = x;
        posY = y;
        radio = rad;
        if(!touched)
        FillCircle(posX, posY, radio, color);
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
