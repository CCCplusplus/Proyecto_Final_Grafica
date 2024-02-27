#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
private:
    int posX, posY, radio, velx, vely;

    bool iscolliding = false;
    bool faceRight = true, faceLeft, faceUp, faceDown;

public:
    void Draw(int x, int y, int rad, Color color)
    {
        posX = x;
        posY = y;
        radio = rad;

        if (linePoints.empty())
        {
            FillTriangleMaxMin(posX, posY, posX + radio, posY + radio, posX + radio, posY - radio, BLACK);
            FillCircle(posX, posY, radio, BLACK);
        }
        else
            drawPixelLinePoints(color);

    }

    void Update(const vector<GameObject*>& otherObjects) {
        iscolliding = false;

        //ahora llamamos directo a la funcion collider.
        for (const auto& obj : otherObjects) {
            if (obj == this) continue;

            if (this->Collider(*obj)) 
            {
                iscolliding = true;
                break;
            }
        }


        if (!iscolliding) {
            if (IsKeyPressed(KEY_D))
            {
                velx = 5;
                vely = 0;
                RotatePacman(faceRight, faceDown, faceUp, faceLeft);
                faceRight = true;
                faceLeft = false;
                faceDown = false;
                faceUp = false;
            }
            if (IsKeyPressed(KEY_A))
            {
                velx = -5;
                vely = 0;
                RotatePacman(faceLeft, faceUp, faceDown, faceRight);
                faceRight = false;
                faceLeft = true;
                faceDown = false;
                faceUp = false;
            }
            if (IsKeyPressed(KEY_W))
            {
                vely = -5;
                velx = 0;
                RotatePacman(faceUp, faceRight, faceLeft, faceDown);
                faceRight = false;
                faceLeft = false;
                faceDown = false;
                faceUp = true;
            }
            if (IsKeyPressed(KEY_S))
            {
                vely = 5;
                velx = 0;
                RotatePacman(faceDown, faceLeft, faceRight, faceUp);
                faceRight = false;
                faceLeft = false;
                faceDown = true;
                faceUp = false;
            }

            MoveMatrix(velx, vely);
        }
        else
        {
            velx *= -2;
            vely *= -2;

            MoveMatrix(velx, vely);

            velx = 0;
            vely = 0;

            if (IsKeyPressed(KEY_D))
            {
                velx = 5;
                vely = 0;

                RotatePacman(faceRight, faceDown, faceUp, faceLeft);
                faceRight = true;
                faceLeft = false;
                faceDown = false;
                faceUp = false;
            }
            if (IsKeyPressed(KEY_A))
            {
                velx = -5;
                vely = 0;
                RotatePacman(faceLeft, faceUp, faceDown, faceRight);
                faceRight = false;
                faceLeft = true;
                faceDown = false;
                faceUp = false;
            }
            if (IsKeyPressed(KEY_W))
            {
                vely = -5;
                velx = 0;
                RotatePacman(faceUp, faceRight, faceLeft, faceDown);
                faceRight = false;
                faceLeft = false;
                faceDown = false;
                faceUp = true;
            }
            if (IsKeyPressed(KEY_S))
            {
                vely = 5;
                velx = 0;
                RotatePacman(faceDown, faceLeft, faceRight, faceUp);
                faceRight = false;
                faceLeft = false;
                faceDown = true;
                faceUp = false;
            }

            MoveMatrix(velx, vely);
        }
    }

    void RotatePacman(bool actualFace, bool rightFace, bool leftFace, bool backFace)
    {
        if (actualFace)
        {
            RotateMatrix(0);
        }
        else if (rightFace)
        {
            RotateMatrix(-90);
        }
        else if (leftFace)
        {
            RotateMatrix(90);
        }
        else if (backFace)
        {
            RotateMatrix(180);
        }
    }
};