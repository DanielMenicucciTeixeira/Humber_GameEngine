#include "FVector4.h"
#include <math.h>



FVector4::FVector4()
{
	x = y = z = 0;
	w = 1;
}

FVector4::FVector4(float inX, float inY, float inZ, float inW)
{
	x = inX;
	y = inY;
	z = inZ;
	w = inW;
}

FVector4::FVector4(FVector3 inVector3, float inW)
{
	x = inVector3.x;
	y = inVector3.y;
	z = inVector3.z;
	w = inW;
}

FVector4::~FVector4()
{
}

FVector4 FVector4::operator+(FVector4 Vector)
{
	return FVector4(x + Vector.x, y + Vector.y, z + Vector.z, w + Vector.w);
}

FVector4 FVector4::operator-(FVector4 Vector)
{
	return FVector4(x - Vector.x, y - Vector.y, z - Vector.z, w - Vector.w);
}

FVector4 FVector4::operator*(float Multiplier)
{
	return FVector4(x * Multiplier, y * Multiplier, z * Multiplier, w * Multiplier);
}

FVector4 FVector4::operator/(float Divisor)
{
	return FVector4(x/Divisor, y/Divisor, z/Divisor, w/Divisor);
}

float FVector4::operator*(FVector4 Vector)
{
	return(x*Vector.x + y * Vector.y + z * Vector.z + w * Vector.w);
}

void FVector4::operator=(FVector4 Vector)
{
	x = Vector.x;
	y = Vector.y;
	z = Vector.z;
	w = Vector.w;
}

void FVector4::operator+=(FVector4 Vector)
{
	x += Vector.x;
	y += Vector.y;
	z += Vector.z;
	w += Vector.w;
}

void FVector4::operator-=(FVector4 Vector)
{
	x -= Vector.x;
	y -= Vector.y;
	z -= Vector.z;
	w -= Vector.w;
}

float FVector4::Length()
{
	return sqrt(x*x + y*y + z*z + w*w);
}

FVector4 FVector4::GetNormal()
{
	FVector4 Result = FVector4(x, y, z, w);
	return Result/ Result.Length();
}

void FVector4::Normalize()
{
	x = x / Length();
	y = y / Length();
	z = z / Length();
	w = w / Length();
}
