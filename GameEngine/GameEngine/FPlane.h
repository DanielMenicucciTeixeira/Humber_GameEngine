#ifndef FPLANE_H
#define FPLANEH

#include "FVector4.h"

class FPlane :
	public FVector4
{
public:
	FPlane();
	FPlane(const FVector3& vector0, const FVector3& vector1, const FVector3& vector2);
	~FPlane();
};
#endif // !PLANE_H
