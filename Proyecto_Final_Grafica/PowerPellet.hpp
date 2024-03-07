#pragma once
#include "GameObject.hpp"


class PowerPellet : public GameObject
{
private:
    int posX, posY;


public:

    bool touched = false;

    PowerPellet(int x, int y)
    {
        posX = x;
        posY = y;
        objectType = PowerBolitas;
    }

    void Draw()
    {
        if(!touched)
        FillCircle(posX, posY, 14, RAYWHITE);
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

                if (obj->objectType == 1)
                {
                    obj->objectType = SuperPacMan;
                    obj->verification = true;
                }
                

                break; 
            }
        }
    }
};
