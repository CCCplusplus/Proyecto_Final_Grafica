#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
private:
    int posX, posY, radio;

	bool iscolliding = false;

public:
	void Draw(int x, int y, int rad, Color color)
	{
		posX = x;
		posY = y;
		radio = rad;

		if (linePoints.empty())
			FillCircle(posX, posY, radio, color);
		else
			drawPixelLinePoints(color);

	}

    void Update(const vector<GameObject*>& otherObjects) {
        iscolliding = false; // Resetear estado de colisión

        
        AABB playerAABB = this->calculateAABB();

        for (const auto& obj : otherObjects) {
            
            if (obj == this) continue;

            
            AABB objectAABB = obj->calculateAABB();

            
            if (playerAABB.overlaps(objectAABB)) {
                iscolliding = true;
                break; 
            }
        }

        // Mover al jugador basado en el estado de colisión
        if (!iscolliding) {
            MoveMatrix(5, 0);
            //primer intento de movimiento. la verdad se que no esta bien hecho pero tengo sueño.
            if (IsKeyDown(KEY_D)) MoveMatrix(5, 0);
            if (IsKeyDown(KEY_A)) MoveMatrix(-5, 0);
            if (IsKeyDown(KEY_W)) MoveMatrix(0, -5);
            if (IsKeyDown(KEY_S)) MoveMatrix(0, 5);
        }
        else
            MoveMatrix(0, 0);
    }
};