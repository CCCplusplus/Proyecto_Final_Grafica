#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
private:
    int posX, posY, radio, velo, velx, vely, width;
    float score = 0;

    double powerupTime = 0.0;

    bool iscolliding = false;
    bool faceRight = true, faceLeft, faceUp, faceDown;

    bool dead = false;

    Sound death = LoadSound("resources/pacman_death.wav");

public:


    void Draw(int x, int y, int rad, int vel, int ancho, Color color)
    {
        Points center = CalculateCenter();
        posX = x;
        posY = y;
        radio = rad;
        velo = vel;
        width = ancho;

        if (linePoints.empty())
        {
            FillTriangleMaxMin(posX, posY, posX + radio, posY + radio, posX + radio, posY - radio, BLACK);
            FillCircle(posX, posY, radio, BLACK);
        }
        else
            drawPixelLinePoints(color);

        if (center.x <= 0) 
        {
            Points center = CalculateCenter();
            ClearLinePoints();
            posY = center.y;
            posX = width - 5;
            FillTriangleMaxMin(posX, posY, posX + radio, posY + radio, posX + radio, posY - radio, color);
            FillCircle(posX, posY, radio, color);
            faceLeft = true;
            faceRight = false;
            RotateMatrix(180);
        }
        else if (center.x >= width)
        {
            Points center = CalculateCenter();
            ClearLinePoints();
            posX = 5;
            posY = center.y;
            FillTriangleMaxMin(posX, posY, posX + radio, posY + radio, posX + radio, posY - radio, color);
            FillCircle(posX, posY, radio, color);
            faceLeft = false;
            faceRight = true;
            RotateMatrix(0);
        }

    }

    void Update(const vector<GameObject*>& otherObjects) {

        if (verification)
            PowerDown();

        if (objectType == SuperPacMan) 
            if (GetTime() - powerupTime >= 3.0)
                objectType = Jugador;
        


        iscolliding = false;
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


        if (!iscolliding) {
            if (!dead)
            {
                if (IsKeyPressed(KEY_D))
                {
                    velx = velo;
                    vely = 0;
                    RotatePacman(faceRight, faceDown, faceUp, faceLeft);
                    faceRight = true;
                    faceLeft = false;
                    faceDown = false;
                    faceUp = false;
                }
                if (IsKeyPressed(KEY_A))
                {
                    velx = -velo;
                    vely = 0;
                    RotatePacman(faceLeft, faceUp, faceDown, faceRight);
                    faceRight = false;
                    faceLeft = true;
                    faceDown = false;
                    faceUp = false;
                }
                if (IsKeyPressed(KEY_W))
                {
                    vely = -velo;
                    velx = 0;
                    RotatePacman(faceUp, faceRight, faceLeft, faceDown);
                    faceRight = false;
                    faceLeft = false;
                    faceDown = false;
                    faceUp = true;
                }
                if (IsKeyPressed(KEY_S))
                {
                    vely = velo;
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
        else
        {
            if (this->objectType == Jugador && objectID == 2)
            {
                ScaleMatrix(0.01, 0.01);
                velx = 0;
                vely = 0;
                if (!dead) 
                {
                    PlaySound(death);
                    dead = true;
                }
            }
            if (objectID == 3)
            {
                velx *= -5;
                vely *= -5;

                MoveMatrix(velx, vely);

                velx = 0;
                vely = 0;

                if (IsKeyPressed(KEY_D))
                {
                    velx = velo;
                    vely = 0;

                    RotatePacman(faceRight, faceDown, faceUp, faceLeft);
                    faceRight = true;
                    faceLeft = false;
                    faceDown = false;
                    faceUp = false;
                }
                if (IsKeyPressed(KEY_A))
                {
                    velx = -velo;
                    vely = 0;
                    RotatePacman(faceLeft, faceUp, faceDown, faceRight);
                    faceRight = false;
                    faceLeft = true;
                    faceDown = false;
                    faceUp = false;
                }
                if (IsKeyPressed(KEY_W))
                {
                    vely = -velo;
                    velx = 0;
                    RotatePacman(faceUp, faceRight, faceLeft, faceDown);
                    faceRight = false;
                    faceLeft = false;
                    faceDown = false;
                    faceUp = true;
                }
                if (IsKeyPressed(KEY_S))
                {
                    vely = velo;
                    velx = 0;
                    RotatePacman(faceDown, faceLeft, faceRight, faceUp);
                    faceRight = false;
                    faceLeft = false;
                    faceDown = true;
                    faceUp = false;
                }

                MoveMatrix(velx, vely);
            }
            if (objectID == 4)
            {
                score += 100;
                cout << score << "\n";
            }
            if (objectID == 5) {
                this->objectType = SuperPacMan;
                PowerDown();
            }
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

    void PowerDown() 
    {
        if (objectType == SuperPacMan)
        {
            verification = false;
            powerupTime = GetTime();
        }
    }
};