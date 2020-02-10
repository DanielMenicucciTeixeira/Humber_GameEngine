#ifndef RAY_H
#define RAY_H

#include "FVector3.h"

class Ray
{
public:
	Ray();
	Ray(FVector3 start, FVector3 Direction, bool isInfinite = true, float length = 0.0f);
	~Ray();

protected:
	FVector3 Start;
	FVector3 Direction;

	bool IsInfinite = true;
	float Length = 0.0f;

public:
	FVector3 GetPosition(float time);
};
#endif

