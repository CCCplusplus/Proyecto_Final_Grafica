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
	
    void RotateMatrix(float angleDegrees) {
        vector<Points> newPoints;
        vector<float> newLinePoints;

        // Calcula el centro de la figura.
        Points center = CalculateCenter();

        float angleRadians = angleDegrees * (PI / 180.0f);
        float cosTheta = cos(angleRadians);
        float sinTheta = sin(angleRadians);

        // Recorre todos los puntos y aplica la rotación.
        for (size_t i = 0; i < linePoints.size(); i += 2) {
            float x = linePoints[i] - center.x; // Traslada el punto al origen (centro).
            float y = linePoints[i + 1] - center.y;

            // Aplica rotación.
            float newX = x * cosTheta - y * sinTheta;
            float newY = x * sinTheta + y * cosTheta;

            // Traslada el punto de vuelta a su posición original.
            newX += center.x;
            newY += center.y;

            // Guarda los puntos rotados.
            newLinePoints.push_back(newX);
            newLinePoints.push_back(newY);
        }

        // Actualiza linePoints con los puntos rotados.
        linePoints = newLinePoints;
    }


    Points CalculateCenter() {
        float sumX = 0, sumY = 0;
        int pointsCount = linePoints.size() / 2;
        for (size_t i = 0; i < linePoints.size(); i += 2) {
            sumX += linePoints[i];
            sumY += linePoints[i + 1];
        }
        return { static_cast<int>(sumX / pointsCount), static_cast<int>(sumY / pointsCount), 1 };
    }


    void ScaleMatrix(float scaleX, float scaleY) {
        vector<float> newLinePoints; // Nuevo vector float para reemplazar linePoints.

        // Calcula el centro de la figura.
        Points center = CalculateCenter();

        // Recorre todos los puntos y aplica el escalado.
        for (size_t i = 0; i < linePoints.size(); i += 2) {
            float x = linePoints[i] - center.x; // Traslada el punto al origen (centro).
            float y = linePoints[i + 1] - center.y;

            // Aplica escalado.
            float newX = x * scaleX;
            float newY = y * scaleY;

            // Traslada el punto de vuelta a su posición original.
            newX += center.x;
            newY += center.y;

            // Guarda los puntos escalados.
            newLinePoints.push_back(newX);
            newLinePoints.push_back(newY);
        }

        // Actualiza linePoints con los puntos escalados.
        linePoints = newLinePoints;
    }


};

//intente operar la matriz de rotacion igual que la de movimiento...
// los resultados fueron... 
// dejo esto como recuerdo de mis 2 horas de vida.
//void RotateMatrix(float angleDegrees) {
//    vector<Points> newPoints; // Contenedor para los nuevos puntos rotados.
//    vector<float> newLinePoints; // Nuevo vector float para reemplazar linePoints.
//
//    float angleRadians = angleDegrees * (PI / 180.0f);
//    // Matriz de rotación 2D extendida a 3x3.
//    float rotationMatrix[3][3] = {
//        {cos(angleRadians), -sin(angleRadians), 0},
//        {sin(angleRadians), cos(angleRadians), 0},
//        {0, 0, 1}
//    };
//
//    // Calcula el centro de la figura.
//    Points center = CalculateCenter();
//
//    // Aplica la matriz de rotación a cada punto, considerando la rotación alrededor del centro de la figura.
//    for (size_t i = 0; i < linePoints.size(); i += 2) {
//        Points originalPoint = { static_cast<int>(linePoints[i] - center.x), static_cast<int>(linePoints[i + 1] - center.y), 1 };
//        Points transformedPoint;
//
//        transformedPoint.x = static_cast<int>((originalPoint.x * rotationMatrix[0][0]) + (originalPoint.y * rotationMatrix[0][1]) + (originalPoint.one * center.x));
//        transformedPoint.y = static_cast<int>((originalPoint.x * rotationMatrix[1][0]) + (originalPoint.y * rotationMatrix[1][1]) + (originalPoint.one * center.y));
//        // No es necesario modificar el componente 'one', pero se realiza la multiplicación completa por coherencia.
//
//        newPoints.push_back(transformedPoint);
//    }
//
//    // Convierte los puntos transformados de nuevo a vector<float> para el dibujo.
//    for (const Points& p : newPoints) {
//        newLinePoints.push_back(static_cast<float>(p.x));
//        newLinePoints.push_back(static_cast<float>(p.y));
//    }
//
//    // Actualiza linePoints con los nuevos puntos rotados.
//    linePoints = newLinePoints;
//}
