#include <iostream>
#include <vector>
#include "raylib.h"
#include "Shapes.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Walls.hpp"
#include "PowerPellet.hpp"
#include "Pellets.hpp"

using namespace std;

int main()
{
	Color background = BLACK;
	const int width = 800;
	const int height = 1000;
	InitWindow(width, height, "Pac-Man (the game I totally just invented)");
	InitAudioDevice();
	SetTargetFPS(60);

	Player pacman;
	Enemy blinky;
	Enemy pinky;
	Enemy inky;
	Enemy clyde;
	PowerPellet powerup1 = PowerPellet(35, 90);
	PowerPellet powerup2 = PowerPellet(35, 815);
	PowerPellet powerup3 = PowerPellet(width - 35, 85);
	PowerPellet powerup4 = PowerPellet(width - 35, 815);


	pacman.objectType = pacman.Jugador;
	blinky.objectType = blinky.Enemigos;
	pinky.objectType = pinky.Enemigos;
	inky.objectType = inky.Enemigos;
	clyde.objectType = clyde.Enemigos;


	//Paredes limite y centro
	Walls topWall = Walls(0, 0, width, 10);
	Walls bottomWall = Walls(0, height - 11, width, 10);
	Walls leftTopWall = Walls(0, 0, 10, height / 2 - 45);
	Walls leftBottomWall = Walls(0, height / 2 + 20, 10, 500);
	Walls rightTopWall = Walls(width - 11, 0, 10, height / 2 - 45);
	Walls rightBottomWall = Walls(width - 11, height / 2 + 20, 10, 500);
	Walls centerBox = Walls(width / 2 - 105, height / 2 - 125, 205, 235);

	//Paredes de la izquierda
	Walls Wall1 = Walls(75, 70, 70, 50);
	Walls Wall2 = Walls(75, 185, 70, 30);
	Walls Wall3 = Walls(-5, 285, 150, 170);
	Walls Wall6 = Walls(-5, 520, 150, 170);
	Walls Wall9 = Walls(75, 755, 70, 30);
	Walls Wall10 = Walls(115, 785, 30, 80);
	Walls Wall11 = Walls(-5, 845, 50, 20);
	Walls Wall12 = Walls(215, 70, 100, 50);
	Walls Wall13 = Walls(215, 185, 20, 270);
	Walls Wall14 = Walls(215, 520, 20, 170);
	Walls Wall15 = Walls(215, 755, 100, 20);
	Walls Wall16 = Walls(215, 835, 20, 85);
	Walls Wall17 = Walls(75, 920, 240, 20);
	Walls Wall18 = Walls(215, 285, 100, 20);

	//Paredes de la derecha
	Walls Wall19 = Walls(width - 151, 70, 70, 50);
	Walls Wall20 = Walls(width - 151, 185, 70, 30);
	Walls Wall21 = Walls(width - 151, 285, 150, 170);
	Walls Wall24 = Walls(width - 151, 520, 150, 170);
	Walls Wall27 = Walls(width - 151, 760, 70, 30);
	Walls Wall28 = Walls(width - 151, 790, 30, 80);
	Walls Wall29 = Walls(width - 51, 850, 50, 20);
	Walls Wall30 = Walls(width - 321, 70, 100, 50);
	Walls Wall31 = Walls(width - 241, 185, 20, 270);
	Walls Wall32 = Walls(width - 241, 520, 20, 170);
	Walls Wall33 = Walls(width - 321, 755, 100, 20);
	Walls Wall34 = Walls(width - 241, 835, 20, 85);
	Walls Wall35 = Walls(width - 321, 920, 240, 20);
	Walls Wall36 = Walls(width - 321, 285, 100, 20);

	//Paredes centrales
	Walls Wall37 = Walls(width / 2 - 10, 0, 20, 125);
	Walls Wall38 = Walls(width / 2 - 10, 185, 20, 120);
	Walls Wall39 = Walls(width / 2 - 95, 185, 190, 20);
	Walls Wall40 = Walls(width / 2 - 10, 670, 20, 110);
	Walls Wall41 = Walls(width / 2 - 95, 670, 190, 20);
	Walls Wall42 = Walls(width / 2 - 10, 835, 20, 110);
	Walls Wall43 = Walls(width / 2 - 95, 835, 190, 20);

	// Lista de objetos con los que el jugador puede colisionar
	vector<GameObject*> gameObjects;
	vector<GameObject*> gameObjects2;
	vector<GameObject*> pacObjects;
	vector<GameObject*> enemyObjects;
	vector<Pellets> pellets;

	gameObjects.push_back(&topWall);
	gameObjects.push_back(&bottomWall);
	gameObjects.push_back(&leftTopWall);
	gameObjects.push_back(&leftBottomWall);
	gameObjects.push_back(&rightTopWall);
	gameObjects.push_back(&rightBottomWall);
	gameObjects.push_back(&centerBox);

	gameObjects.push_back(&Wall1);
	gameObjects.push_back(&Wall2);
	gameObjects.push_back(&Wall3);
	gameObjects.push_back(&Wall6);
	gameObjects.push_back(&Wall9);
	gameObjects.push_back(&Wall10);
	gameObjects.push_back(&Wall11);
	gameObjects.push_back(&Wall12);
	gameObjects.push_back(&Wall13);
	gameObjects.push_back(&Wall14);
	gameObjects.push_back(&Wall15);
	gameObjects.push_back(&Wall16);
	gameObjects.push_back(&Wall17);
	gameObjects.push_back(&Wall18);
	gameObjects.push_back(&Wall19);
	gameObjects.push_back(&Wall20);
	gameObjects.push_back(&Wall21);
	gameObjects.push_back(&Wall24);
	gameObjects.push_back(&Wall27);
	gameObjects.push_back(&Wall28);
	gameObjects.push_back(&Wall29);
	gameObjects.push_back(&Wall30);
	gameObjects.push_back(&Wall31);
	gameObjects.push_back(&Wall32);
	gameObjects.push_back(&Wall33);
	gameObjects.push_back(&Wall34);
	gameObjects.push_back(&Wall35);
	gameObjects.push_back(&Wall36);
	gameObjects.push_back(&Wall37);
	gameObjects.push_back(&Wall38);
	gameObjects.push_back(&Wall39);
	gameObjects.push_back(&Wall40);
	gameObjects.push_back(&Wall41);
	gameObjects.push_back(&Wall42);
	gameObjects.push_back(&Wall43);

	gameObjects2.push_back(&topWall);
	gameObjects2.push_back(&bottomWall);
	gameObjects2.push_back(&leftTopWall);
	gameObjects2.push_back(&leftBottomWall);
	gameObjects2.push_back(&rightTopWall);
	gameObjects2.push_back(&rightBottomWall);

	gameObjects2.push_back(&Wall1);
	gameObjects2.push_back(&Wall2);
	gameObjects2.push_back(&Wall3);
	gameObjects2.push_back(&Wall6);
	gameObjects2.push_back(&Wall9);
	gameObjects2.push_back(&Wall10);
	gameObjects2.push_back(&Wall11);
	gameObjects2.push_back(&Wall12);
	gameObjects2.push_back(&Wall13);
	gameObjects2.push_back(&Wall14);
	gameObjects2.push_back(&Wall15);
	gameObjects2.push_back(&Wall16);
	gameObjects2.push_back(&Wall17);
	gameObjects2.push_back(&Wall18);
	gameObjects2.push_back(&Wall19);
	gameObjects2.push_back(&Wall20);
	gameObjects2.push_back(&Wall21);
	gameObjects2.push_back(&Wall24);
	gameObjects2.push_back(&Wall27);
	gameObjects2.push_back(&Wall28);
	gameObjects2.push_back(&Wall29);
	gameObjects2.push_back(&Wall30);
	gameObjects2.push_back(&Wall31);
	gameObjects2.push_back(&Wall32);
	gameObjects2.push_back(&Wall33);
	gameObjects2.push_back(&Wall34);
	gameObjects2.push_back(&Wall35);
	gameObjects2.push_back(&Wall36);
	gameObjects2.push_back(&Wall37);
	gameObjects2.push_back(&Wall38);
	gameObjects2.push_back(&Wall39);
	gameObjects2.push_back(&Wall40);
	gameObjects2.push_back(&Wall41);
	gameObjects2.push_back(&Wall42);
	gameObjects2.push_back(&Wall43);
	

	pacObjects.push_back(&pacman);

	enemyObjects.push_back(&blinky);
	enemyObjects.push_back(&pinky);
	enemyObjects.push_back(&inky);
	enemyObjects.push_back(&clyde);


	for (int y = 30; y < height - 15; y += 45)
	{
		for (int x = 35; x < width - 20; x += 45)
		{
			pellets.push_back(Pellets(x, y));
		}
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(background);
		cout << GetFPS() << "\n";
		blinky.Draw(375, 430, 425, 430, width/2, 395, width, RED);
		pinky.Draw(305, 500, 355, 500, width / 2 -70, 465, width, PINK);
		inky.Draw(375, 500, 425, 500, width / 2, 465, width, SKYBLUE);
		clyde.Draw(375 +70, 500, 425 +70, 500, width / 2 + 70, 465, width, ORANGE);

		topWall.Draw();
		bottomWall.Draw();
		leftTopWall.Draw();
		leftBottomWall.Draw();
		rightTopWall.Draw();
		rightBottomWall.Draw();
		centerBox.Draw();

		Wall1.Draw();
		Wall2.Draw();
		Wall3.Draw();
		Wall6.Draw();
		Wall9.Draw();
		Wall10.Draw();
		Wall11.Draw();
		Wall12.Draw();
		Wall13.Draw();
		Wall14.Draw();
		Wall15.Draw();
		Wall16.Draw();
		Wall17.Draw();
		Wall18.Draw();
		Wall19.Draw();
		Wall20.Draw();
		Wall21.Draw();
		Wall24.Draw();
		Wall27.Draw();
		Wall28.Draw();
		Wall29.Draw();
		Wall30.Draw();
		Wall31.Draw();
		Wall32.Draw();
		Wall33.Draw();
		Wall34.Draw();
		Wall35.Draw();
		Wall36.Draw();
		Wall37.Draw();
		Wall38.Draw();
		Wall39.Draw();
		Wall40.Draw();
		Wall41.Draw();
		Wall42.Draw();
		Wall43.Draw();

		powerup1.Draw();
		powerup2.Draw();
		powerup3.Draw();
		powerup4.Draw();

		pacman.Update(gameObjects);
		pacman.Update(enemyObjects);
		pacman.Draw(400, 640, 18, 3, width, YELLOW);

		powerup1.Update(pacObjects);
		powerup2.Update(pacObjects);
		powerup3.Update(pacObjects);
		powerup4.Update(pacObjects);

		for (int i = 0; i < pellets.size(); i++)
		{
			pellets[i].Draw();
			pellets[i].Update(pacObjects);
			pellets[i].Update(gameObjects);
		}

		blinky.Update(gameObjects2);
		pinky.Update(gameObjects2);
		inky.Update(gameObjects2);
		clyde.Update(gameObjects2);
		blinky.Update(pacObjects);
		pinky.Update(pacObjects);
		inky.Update(pacObjects);
		clyde.Update(pacObjects);

		EndDrawing();
		//Cuando termines de dibujar en el loop borra los linepoints de todos los objetos estaticos.
		topWall.ClearLinePoints();
		bottomWall.ClearLinePoints();
		leftTopWall.ClearLinePoints();
		leftBottomWall.ClearLinePoints();
		rightTopWall.ClearLinePoints();
		rightBottomWall.ClearLinePoints();
		centerBox.ClearLinePoints();

		Wall1.ClearLinePoints();
		Wall2.ClearLinePoints();
		Wall3.ClearLinePoints();
		Wall6.ClearLinePoints();
		Wall9.ClearLinePoints();
		Wall10.ClearLinePoints();
		Wall11.ClearLinePoints();
		Wall12.ClearLinePoints();
		Wall13.ClearLinePoints();
		Wall14.ClearLinePoints();
		Wall15.ClearLinePoints();
		Wall16.ClearLinePoints();
		Wall17.ClearLinePoints();
		Wall18.ClearLinePoints();
		Wall19.ClearLinePoints();
		Wall20.ClearLinePoints();
		Wall21.ClearLinePoints();
		Wall24.ClearLinePoints();
		Wall27.ClearLinePoints();
		Wall28.ClearLinePoints();
		Wall29.ClearLinePoints();
		Wall30.ClearLinePoints();
		Wall31.ClearLinePoints();
		Wall32.ClearLinePoints();
		Wall33.ClearLinePoints();
		Wall34.ClearLinePoints();
		Wall35.ClearLinePoints();
		Wall36.ClearLinePoints();
		Wall37.ClearLinePoints();
		Wall38.ClearLinePoints();
		Wall39.ClearLinePoints();
		Wall40.ClearLinePoints();
		Wall41.ClearLinePoints();
		Wall42.ClearLinePoints();
		Wall43.ClearLinePoints();
		powerup1.ClearLinePoints();
		powerup2.ClearLinePoints();
		powerup3.ClearLinePoints();
		powerup4.ClearLinePoints();
		for (int i = 0; i < pellets.size(); i++)
		{
			pellets[i].ClearLinePoints();
		}
	}
	CloseAudioDevice();
	CloseWindow();

	return 0;
}