#include "PhysicsBody2D.h"



PhysicsBody2D::PhysicsBody2D(Game * game) : GameObject2D{game}
{
	Mass = 0;
}

PhysicsBody2D::PhysicsBody2D(float mass, FTransform transform, FVector3 velocity)
{
	Transform = transform;
	Mass = mass;
	SetVelocity(velocity);
}

PhysicsBody2D::PhysicsBody2D(FVector3 position, FQuaternion rotation, float mass, FVector3 velocity)
{
	Transform.Position = position;
	Transform.Rotation = rotation;
	Transform.Scale = FVector3 (1);
	Mass = mass;
	SetVelocity(velocity);
}

PhysicsBody2D::PhysicsBody2D(FVector3 position, float mass, FVector3 velocity)
{
	Transform.Position = position;
	Mass = mass;
	Velocity = velocity;
	Sprite = new LTexture();
}


PhysicsBody2D::~PhysicsBody2D()
{
}

void PhysicsBody2D::SetScale(FVector3 scale, bool scaleMass)
{
	Transform.Scale = scale;

	if (scaleMass) Mass *= (scale.x)*(scale.y);
}

void PhysicsBody2D::SetScale(float scale, bool scaleMass)
{
	Transform.Scale = FVector3(scale);

	if (scaleMass) Mass *= scale * scale;
}

void PhysicsBody2D::AddForce(FVector3 Force)
{
	if(Mass != 0) Acceleration += Force/Mass;
	else Acceleration += Force;
}

float PhysicsBody2D::GetSpeed()
{
	return Velocity.Length();
}

FVector3 PhysicsBody2D::GetVelocity()
{
	return Velocity;
}

void PhysicsBody2D::SetVelocity(FVector3 velocity)
{
	Velocity.x = velocity.x;
	Velocity.y = velocity.y;
	Velocity.z = 0;
}

FVector3 PhysicsBody2D::GetAcceleration()
{
	return Acceleration;
}

float PhysicsBody2D::GetMass()
{
	return Mass;
}

void PhysicsBody2D::SetMass(float mass)
{
	Mass = mass;
}

void PhysicsBody2D::SetAngle(float angle)
{
	Angle = angle;
}

float PhysicsBody2D::GetAngle()
{
	return Angle;
}

void PhysicsBody2D::SetAngularVelocity(float velocity)
{
	AngularVelocity = velocity;
}

float PhysicsBody2D::GetAngularVelocity()
{
	return AngularVelocity;
}

void PhysicsBody2D::SetAngularAcceleration(float acceleration)
{
	AngularAcceleration = acceleration;
}

float PhysicsBody2D::GetAngularAcceleration()
{
	return AngularAcceleration;
}

void PhysicsBody2D::SetRotationalInertia(float angularInertia)
{
	RotationalInertia = angularInertia;
}

float PhysicsBody2D::GetRotationalInertia()
{
	return RotationalInertia;
}

void PhysicsBody2D::AddTorque(float torque)
{
	if (RotationalInertia != 0) Acceleration += torque / RotationalInertia;
	else Acceleration += torque;
}

void PhysicsBody2D::Update(float deltaTime)
{
	Transform.Position += ((Velocity*deltaTime) + ((Acceleration*(deltaTime*deltaTime)) / 2));

	Velocity += Acceleration * deltaTime;

	Angle = ((AngularVelocity * deltaTime) + ((AngularAcceleration*(deltaTime*deltaTime)) / 2));
	AngularVelocity = (AngularAcceleration * deltaTime);

	Acceleration = FVector3(0);
	AngularAcceleration = 0.0f;
}
