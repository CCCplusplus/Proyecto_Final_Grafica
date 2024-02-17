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
    Walls walls;

    // Lista de objetos con los que el jugador puede colisionar
    std::vector<GameObject*> gameObjects;
    gameObjects.push_back(&evilboi);
    gameObjects.push_back(&walls); 

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(background);

        
        evilboi.RotateMatrix(90); 
        evilboi.Draw();

        
        walls.Draw(); 

        
        pacman.Update(gameObjects);
        pacman.Draw(400, 500, 30, YELLOW);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}


