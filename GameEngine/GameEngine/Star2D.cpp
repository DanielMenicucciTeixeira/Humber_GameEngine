#include "Star2D.h"



Star2D::Star2D()
{
}

Star2D::Star2D(FVector3 position, float mass, float radius, float gravityConstant)
{
	Transform.Position = position;
	Mass = mass;
	Radius = radius;
	GravityConstatn = gravityConstant;
	Sprite = new LTexture();
}


Star2D::~Star2D()
{
}

void Star2D::GravityPull(PhysicsBody2D * target)
{
	if ((Transform.Position - target->GetTransform().Position).Length() > Radius)
	{
		FVector3 Displacement = FVector3(Transform.Position - target->GetTransform().Position);
		FVector3 Direction = FVector3(Displacement.GetNormal());
		float Distance = Displacement.Length();

		FVector3 GravityForce = Direction * ((GravityConstatn * Mass * target->GetMass())/(Distance*Distance));

		Planet = target;
		ForceDebug = GravityForce*100;

		target->AddForce(GravityForce);
	}
}