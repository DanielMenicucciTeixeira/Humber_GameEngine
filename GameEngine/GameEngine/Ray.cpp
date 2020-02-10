#include "Ray.h"



Ray::Ray()
{
	Start = new FVector3(0.0f);
	Direction = new FVector3(1, 0.0f, 0.0f);
	IsInfinite = true;
	Length = 0.0f;
}

Ray::Ray(FVector3 start, FVector3 direction, bool isInfinite, float length)
{
	Start = start;
	if(isInfinite) Direction = direction.GetNormal();
	else Direction = direction;

	IsInfinite = isInfinite;
	Length = length;
}


Ray::~Ray()
{
}

FVector3 Ray::GetPosition(float time)
{
	return Start + Direction * time;
}
