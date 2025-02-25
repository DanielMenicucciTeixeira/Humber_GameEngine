#ifndef FVector3_
#define FVector3_

class FVector3
{
public:

	//Variables (coordinates of the vector)
	float x, y, z;

	///Constructors

	//Constructor using initial values for each component.
	FVector3(float X, float Y, float Z);

	//Constructor initializing all components to a single float value.
	FVector3(float Float);

	//Constructor initializing to match a given FVector3, a copy constructor
	inline FVector3(const FVector3& InitilizerVector);

	//Default Constructor, initializes all values to 0;
	FVector3();

	///Destructor

	~FVector3();

	///Operators

	virtual FVector3 operator+ (FVector3 Vector);//Overload of the "+" operator, makes a vector plus vector addition.

	virtual FVector3 operator- (FVector3 Vector);//Overload of the "-" operator, makes a vector minus vector subtraction.

	virtual FVector3 operator* (float Multiplier);//Overload of the "*" operator, makes a vector times scalar multiplication.

	virtual FVector3 operator/ (float Divisor);//Overload of the "/" operator, makes a vector divided by scalar division.

	virtual float operator* (FVector3 Vector);//Overload of the "*" operator, makes a vector times vector dot product.

	virtual void operator= (FVector3 Vector);//Overload of the "=" operator, makes each component of the vector equal to the equivalent component of a given vector.

	virtual void operator= (FVector3 * Vector);//Overload of the "=" operator, makes each component of the vector equal to the equivalent component of a given vector.

	virtual void operator+= (FVector3 Vector);//Overload of the "+=" operator, makes a vector plus vector addition changing the current vector to equal to sum.

	virtual void operator-= (FVector3 Vector);//Overload of the "-=" operator, makes a vector minus vector subtraction. changing the current vector to equal the result.

	///Functions

	//Returns the magnitude of the Vector (or Vector's scalar lenght)
	virtual float Length();

	//Returns the angle between this vector and another given vector in degrees.
	float GetAngle(FVector3 Vector);

	//Returns the angle between this vector and another given vector in radians.
	float GetRadAngle(FVector3 Vector);

	//Returns the cross product between this vector and another given vector.
	virtual FVector3 CrossProduct(FVector3 Vector);

	//Gets the normalized form of this Vector
	virtual FVector3 GetNormal();

	//Divides the vector by its Magnitude to get the normalized unit vector.
	virtual void Normalize();

	//Rotates the vector by disered amount in degrees in the Z axis
	void RotateZ(float Degrees);

	//Rotates the vector by disered amount in radians in the Z axis
	void RotateZRad(float Degrees);

	//Utility to populate vector
	virtual inline void Load(float InX, float InY, float InZ);
};
#endif