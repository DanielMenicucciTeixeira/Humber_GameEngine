#include "Scene_Matrix.h"

#include<stdio.h>
#include <iostream>


void Scene_Matrix::OnCreate()
{
	SMatrix = FMatrix();
	SMatrix2 = FMatrix();
	SVector = FVector3(0, 1, -2);

	std::cout << "Enter each element of the matrix:" << std::endl;
	for (int col = 0; col < 3; col++)
	{
		std::cout << "Row: " << col + 1 << std::endl;
		for (int row = 0; row < 3; row++)
		{
			std::cin >> MatrixArray[row][col];
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;

	SMatrix.SetToArray33(MatrixArray);

	std::cout << "Your Matrix is:" << std::endl;

	SMatrix.PrintMatrix();
	std::cout << std::endl;

	std::cout << "The Determinant of your Matrix is:" << SMatrix.Det() << std::endl;
	std::cout << std::endl;

	std::cout << "The Inverse Matrix to your Matrix is :" << std::endl;
	if (SMatrix.Det() != 0)
	{
		SMatrix.GetInverse().PrintMatrix();
	}
	else std::cout << "This Matrix has no Inverse!" << std::endl;
	std::cout << std::endl;
	

	std::cout << "Enter each element of a new matrix:" << std::endl;
	for (int col = 0; col < 3; col++)
	{
		std::cout << "Row: " << col + 1 << std::endl;
		for (int row = 0; row < 3; row++)
		{
			std::cin >> MatrixArray[row][col];
		}
	}
	SMatrix2.SetToArray33(MatrixArray);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "The new Matrix is:" << std::endl;
	SMatrix2.PrintMatrix();
	std::cout << std::endl;


	std::cout << "The product of the first matrix times the new is :" <<std::endl;
	(SMatrix*SMatrix2).PrintMatrix();
	std::cout << std::endl;

	std::cout << "The product of the first matrix times the Vector [0 , 1 , -2] is :" << std::endl;
	SVector = SMatrix * SVector;
	std::cout << "[" << SVector.x << " , " << SVector.y << " , " << SVector.z << "]" << std::endl;

	system("PAUSE");

}

Scene_Matrix::Scene_Matrix()
{
	OnCreate();
}


Scene_Matrix::~Scene_Matrix()
{
}

void Scene_Matrix::Update()
{
}
