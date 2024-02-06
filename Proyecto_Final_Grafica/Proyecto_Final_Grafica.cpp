#include <iostream>
#include "raylib.h"
#include "Shapes.hpp"

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


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(background);

        shapes.drawTriangle(100, 100, 200, 100, 150, 50, color);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

