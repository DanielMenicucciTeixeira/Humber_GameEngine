#ifndef PHYSICSBODY2D_
#define PHYSICSBODY2D_

#include "GameObject2D.h"

class PhysicsBody2D: public GameObject2D
{
protected:

	//The value of this body's inertia
	float Mass;

	//Bodys velocity vector
	FVector3 Velocity;

	//Body's acceleration, resets at every frame
	FVector3 Acceleration;

	//Body's current angular orientation
	float Angle;

	//How fast angle is changing and in wich direction (anti-clockwise is positive), in degrees per second
	float AngularVelocity;
	
	//Acceleration of AngularVelocity, resets at every frame
	float AngularAcceleration;

	//How resistent the body is to change in it's angular orientation
	float RotationalInertia;

public:
	PhysicsBody2D(Game * game = nullptr);

	PhysicsBody2D(float mass, FTransform transform = FTransform(), FVector3 velocity = FVector3(0));

	PhysicsBody2D(FVector3 position, FQuaternion rotation = FQuaternion(), float mass = 0, FVector3 velocity = FVector3(0));

	PhysicsBody2D(FVector3 position, float mass, FVector3 velocity);

	~PhysicsBody2D();

	//Sets the scale of the Physics body given a scale vector, if the second parameter is true, multiplies the mass according to the size increase
	void SetScale(FVector3 scale, bool scaleMass = false);

	//Sets the scale of the Physics body to the given number on both dimensions, if the second parameter is true, multiplies the mass according to the size increase
	void SetScale(float scale, bool scaleMass = false);

	//Applies a force to the body
	void AddForce(FVector3 Force);

	//Returns the magnitude of the velocity FVector3
	float GetSpeed();

	//Returns the bodys current velocity
	FVector3 GetVelocity();

	//Sets the velocity to given FVector3
	void SetVelocity(FVector3 velocity);

	//Retruns bodys current Acceleration
	FVector3 GetAcceleration();

	//Returns bodys Mass
	float GetMass();

	//Sets the bodys Mass
	void SetMass(float mass);

	//Sets the body's orientation angle
	void SetAngle(float angle = 0.0f);

	//Returns the body's orientation angle
	float GetAngle();

	//Sets the agluar velocity
	void SetAngularVelocity(float velocity = 0.0f);

	//Returns angular velocity
	float GetAngularVelocity();

	//Sets the angular acceleration
	void SetAngularAcceleration(float acceleration = 0.0f);

	//Returns the angular acceleration
	float GetAngularAcceleration();

	//Sets angular inertia
	void SetRotationalInertia(float angularInertia);

	//Returns the angular inertia
	float GetRotationalInertia();

	//Applies rotational force to the body
	void AddTorque(float torque);

	virtual void Update(float deltaTime) override;

};

#endif
