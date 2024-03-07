#pragma once
#include "GameObject.hpp"

class Enemy : public GameObject
{
private:
    bool killed = false;

    int posX1, posY1, posX2, posY2, posX3, posY3, width;
    int velY = -3;
    int velX = 0;

    double timeKilled = 0.0;

    Sound eaten = LoadSound("resources/pacman_eatghost.wav");

    Color color;

public:

	void Draw(int x1, int y1, int x2, int y2, int x3, int y3, int ancho, Color enemycolor)
	{
        posX1 = x1;
        posY1 = y1;
        posX2 = x2;
        posY2 = y2;
        posX3 = x3;
        posY3 = y3;
        width = ancho;

        color = enemycolor;

        if (!killed) 
        {
            if (linePoints.empty())
                FillTriangleMaxMin(posX1, posY1, posX2, posY2, posX3, posY3, color);
            else
                drawPixelLinePoints(color);
        }

	}

    void Update(const vector<GameObject*>& otherObjects)
    {
        if (killed) {
            // Comprueba si han pasado 3 segundos desde que el enemigo fue matado
            if (GetTime() - timeKilled >= 3.0) {
                // "Revive" al enemigo
                killed = false;


                velX = 0;
                velY = -3;
            }

        }

        bool iscolliding = false;
        int objectID;

        //ahora llamamos directo a la funcion collider.
        for (const auto& obj : otherObjects) {
            if (obj == this) continue;

            if (this->Collider(*obj))
            {
                iscolliding = true;
                objectID = obj->objectType;
                break;
            }
        }
        if (!iscolliding)
        {
            MoveMatrix(velX, velY);
        }
        else
        {
            if (objectID == 3)
            {
                velX *= -2;
                velY *= -2;

                MoveMatrix(velX, velY);

                int velocities[3] = { 0, -3, 3 };
                velX = velocities[rand() % 3]; // Selecciona aleatoriamente 0, -3, o 3 para velX

                if (velX == 0) {
                    // Si velX es 0, entonces velY debe ser -3 o 3 aleatoriamente
                    velY = (rand() % 2) == 0 ? -3 : 3;
                }
                else {
                    // Si velX no es 0, entonces velY debe ser 0
                    velY = 0;
                }

            }
            else if (objectID == 6)
            {
                Kill();
                PlaySound(eaten);
            }
            else
            {
                MoveMatrix(velX, velY);
            }
        }
    }

    void Kill() {
        if (!killed) {
            killed = true;
            timeKilled = GetTime(); // Guarda el momento en que el enemigo fue matado
            ClearLinePoints(); // Opcional: cualquier otra lógica de "muerte"
        }
    }
};