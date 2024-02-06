#include <iostream>
#include "raylib.h"
#include "Shapes.hpp"
#include "Player.hpp"

using namespace std;

int main()
{
    Color color = RED;
    Color background = BLACK;
    const int width = 800;
    const int height = 1000;
    InitWindow(width, height, "Pac-Man (the game I totally just invented)");
    SetTargetFPS(60);
    Shapes shapes;
    Player pacman;


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(background);

        pacman.drawCircleShape(width / 2, height / 2, 50, YELLOW);
        pacman.FillCircle(width / 2, height / 2, 50, YELLOW);

        EndDrawing();
    }
    CloseWindow();

    
    return 0;
}

