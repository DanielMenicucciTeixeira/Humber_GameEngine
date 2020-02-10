#ifndef FVECTOR4_H
#define FVECTOR4_H
#include "FVector3.h"

class FVector4
{
public:
	FVector4();
	FVector4(float inX, float inY, float inZ, float inW);
	FVector4(FVector3 inVector3, float inW = 1.0f);
	~FVector4();

	float x, y, z, w;

	///Operators

	FVector4 operator+ (FVector4 Vector);//Overload of the "+" operator, makes a vector plus vector addition.

	 FVector4 operator- (FVector4 Vector);//Overload of the "-" operator, makes a vector minus vector subtraction.

	FVector4 operator* (float Multiplier);//Overload of the "*" operator, makes a vector times scalar multiplication.

	FVector4 operator/ (float Divisor);//Overload of the "/" operator, makes a vector divided by scalar division.

	float operator* (FVector4 Vector);//Overload of the "*" operator, makes a vector times vector dot product.

	void operator= (FVector4 Vector);//Overload of the "=" operator, makes each component of the vector equal to the equivalent component of a given vector.

	void operator+= (FVector4 Vector);//Overload of the "+=" operator, makes a vector plus vector addition changing the current vector to equal to sum.

	void operator-= (FVector4 Vector);//Overload of the "-=" operator, makes a vector minus vector subtraction. changing the current vector to equal the result.

	///Functions

	//Returns the magnitude of the Vector (or Vector's scalar lenght)
	float Length();

	//Gets the normalized form of this Vector
	FVector4 GetNormal();

	//Divides the vector by its Magnitude to get the normalized unit vector.
	void Normalize();

	//Utility to populate vector
	inline void Load(float InX, float InY, float InZ, float InW) { x = InX; y = InY; z = InZ; w = InW; };
};
#endif

