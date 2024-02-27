#include <iostream>
#include <vector>
#include "raylib.h"
#include "Shapes.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Walls.hpp"

using namespace std;

int main()
{
    Color background = BLACK;
    const int width = 800;
    const int height = 1000;
    InitWindow(width, height, "Pac-Man (the game I totally just invented)");
    SetTargetFPS(60);

    Player pacman;
    Enemy evilboi;
    Walls topWall = Walls(0, 0, width, 10);
    Walls bottomWall = Walls(0, height - 11, width, 10);
    Walls leftWall = Walls(0, 0, 10, height);
    Walls rightWall = Walls(width - 11, 0, 10, height);

    Walls centerBox = Walls(width / 2 - 75, height / 2 - 150, 150, 100);
    Walls Wall1 = Walls(80, 70, 60, 30);
    Walls Wall2 = Walls(80, 170, 60, 30);
    Walls Wall3 = Walls(80, 170, 25, 90);
    Walls Wall4 = Walls(80, 320, 60, 50);
    Walls Wall5 = Walls(80, 430, 60, 30);
    Walls Wall6 = Walls(80, 630, 60, 30);

    // Lista de objetos con los que el jugador puede colisionar
    std::vector<GameObject*> gameObjects;

    gameObjects.push_back(&topWall);
    gameObjects.push_back(&bottomWall);
    gameObjects.push_back(&leftWall);
    gameObjects.push_back(&rightWall);

    gameObjects.push_back(&centerBox);
    gameObjects.push_back(&Wall1);
    gameObjects.push_back(&Wall2);
    gameObjects.push_back(&Wall3);
    gameObjects.push_back(&Wall4);
    gameObjects.push_back(&Wall5);
    gameObjects.push_back(&Wall6);

    gameObjects.push_back(&evilboi);
    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(background);
        cout << GetFPS() << "\n";
        evilboi.RotateMatrix(90);
        evilboi.Draw();

        topWall.Draw();
        bottomWall.Draw();
        leftWall.Draw();
        rightWall.Draw();

        centerBox.Draw();
        Wall1.Draw();
        Wall2.Draw();
        Wall3.Draw();
        Wall4.Draw();
        Wall5.Draw();
        Wall6.Draw();

        pacman.Update(gameObjects);
        pacman.Draw(400, 500, 23, YELLOW);

        EndDrawing();
        //Cuando termines de dibujar en el loop borra los linepoints de todos los objetos estaticos.
        topWall.ClearLinePoints();
        bottomWall.ClearLinePoints();
        leftWall.ClearLinePoints();
        rightWall.ClearLinePoints();
        centerBox.ClearLinePoints();

        Wall1.ClearLinePoints();
        Wall2.ClearLinePoints();
        Wall3.ClearLinePoints();
        Wall4.ClearLinePoints();
        Wall5.ClearLinePoints();
        Wall6.ClearLinePoints();
    }
    CloseWindow();

    return 0;
}