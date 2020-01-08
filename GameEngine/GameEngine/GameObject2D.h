
#ifndef GAMEOBJECT2D_
#define GAMEOBJECT2D_

#include "GameObject.h"
#include "LTexture.h"

class Game2D;

class GameObject2D: public GameObject
{
protected:

	Game2D * CurrentGame2D;

	LTexture * Sprite;

	float & Layer = Transform.Position.z;

	double RotationAngle;

	//I need the compiler to know this is a polimorth class, will be removed later
	virtual void PolymorthFlag() override;

public:

	GameObject2D(Game * game = nullptr);

	GameObject2D(FTransform transform, LTexture * sprite = nullptr, float rotationAngle = 0);

	~GameObject2D();

	void SetSprite(LTexture * sprite);

	void SetScale(float scale);

	void SetScale(FVector3 scale);

	LTexture * GetSprite();

	//Rotate the objecte counter clockwise by a given angle (in degrees)
	void Rotate2D(double angle);

	//Returns the 2D rotation angle
	double GetRotation2D();

	virtual void Update(float deltaTime);

	void Render();
};
#endif

