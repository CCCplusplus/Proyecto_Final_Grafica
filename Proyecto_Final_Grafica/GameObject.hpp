#pragma once
#include "Shapes.hpp"

using namespace std;

struct Points
{
	int x, y;
	int one = 1;
};

class GameObject : public Shapes
{
public:
	
	vector<float> vectorinos;

    vector<Points> transformedPoints;

    // Actualiza MoveMatrix para aplicar traslación.
    void MoveMatrix(int distanceX, int distanceY) {
        vector<Points> newPoints; // Contenedor para los nuevos puntos trasladados.
        vector<float> newLinePoints; //nuevo vector float para remplazar

        // Matriz de traslación.
        float translationMatrix[3][3] = {
            {1, 0, distanceX},
            {0, 1, distanceY},
            {0, 0, 1}
        };

        // Aplica la matriz de traslación a cada punto.
        for (size_t i = 0; i < linePoints.size(); i += 2) {
            Points originalPoint = { linePoints[i], linePoints[i + 1], 1 };
            Points transformedPoint;

            transformedPoint.x = (originalPoint.x * translationMatrix[0][0]) + (originalPoint.y * translationMatrix[0][1]) + (originalPoint.one * translationMatrix[0][2]);
            transformedPoint.y = (originalPoint.x * translationMatrix[1][0]) + (originalPoint.y * translationMatrix[1][1]) + (originalPoint.one * translationMatrix[1][2]);
            // uno es uno pero se multiplica para que no haya errores
            transformedPoint.one = (originalPoint.x * translationMatrix[2][0]) + (originalPoint.y * translationMatrix[2][1]) + (originalPoint.one * translationMatrix[2][2]);

            newPoints.push_back(transformedPoint);
        }
        // Convierte los puntos transformados de nuevo a vector<float> para el dibujo.
        for (const Points& p : newPoints) {
            newLinePoints.push_back(p.x);
            newLinePoints.push_back(p.y);
        }

        // Actualiza linePoints con los nuevos puntos trasladados.
        linePoints = newLinePoints;
    }
	
	vector<float> RotateMatrix(vector<float> tumama)
	{
		return tumama;
	}

	vector<float> ScalateMatrix(vector<float> tumama)
	{
		return tumama;
	}
};