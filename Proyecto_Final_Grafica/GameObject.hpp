#include "Shapes.hpp"

using namespace std;

class GameObject : public Shapes
{
public:
	
	vector<float> vectorinos;

	vector<float> MoveMatrix(vector<float> tumama)
	{
		return tumama;
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