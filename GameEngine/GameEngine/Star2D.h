#ifndef STAR2D_
#define STAR2D_

#include "PhysicsBody2D.h"

class Star2D : public GameObject2D
{
protected:

	//Mass of the star
	float Mass;

	//Base gravitational multiplier for the star's gravitational pull, default is 1
	float GravityConstatn;

	//Star's Radius, default is 1
	float Radius;

public:

	Star2D();

	Star2D(FVector3 position, float mass, float radius = 1, float gravityConstant = 1);

	~Star2D();

	void GravityPull(PhysicsBody2D * target);

	FVector3 ForceDebug = FVector3();

	GameObject2D * Planet;
};

#endif

