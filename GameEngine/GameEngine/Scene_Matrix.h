#ifndef SCENE_MATRIX_
#define SCENE_MATTRIX_

#include "FMatrix.h"
#include "FVector3.h"

class Scene_Matrix
{
private:

	void OnCreate();
	FMatrix SMatrix;
	FMatrix SMatrix2;
	FVector3 SVector;
	float MatrixArray[3][3];

public:
	Scene_Matrix();
	~Scene_Matrix();

	void Update();

};
#endif

