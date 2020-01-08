#ifndef SCENE_STARSHIP
#define SCENE_STARSHIP

#include <fstream>
#include <iostream>
#include <string>
#include "PhysicsBody2D.h"
#include "FMatrix.h"

class Scene_Starship
{
private:
	std::ofstream Table;
	std::string TableString = "";
	class PhysicsBody2D * Starship = nullptr;

	void WriteTableLine();
	void CreateStarship();

	FVector3 TurbineForce;
	float TurbineTorque;
	FMatrix RotationMatrix;
	FVector3 ShipAcceleration;
	float ShipAngularAcceleration;

	float DeltaTime = 0.001f;
	float TimeSkip = 1.0f;
	float Time = 0.0f;
	 
public:
	void OnCreate();
	Scene_Starship();
	~Scene_Starship();
};
#endif