#include "GameObject2D.h"
#include "Game2D.h"

void GameObject2D::PolymorthFlag()
{
}

GameObject2D::GameObject2D(Game * game) : GameObject{game}
{
	Sprite = new LTexture(this);
}

GameObject2D::GameObject2D(FTransform transform, LTexture * sprite, float rotationAngle)
{
	Transform = transform;
	Transform.Position.z = round(Transform.Position.z);
	Layer = int(Transform.Position.z);
	RotationAngle = rotationAngle;

	if (sprite) Sprite = sprite;
	else Sprite = new LTexture(this);
}


GameObject2D::~GameObject2D()
{
	delete(Sprite);
}

void GameObject2D::SetSprite(LTexture * sprite)
{
	Sprite = sprite;
}

void GameObject2D::SetScale(float scale)
{
	Transform.Scale = scale;
}

void GameObject2D::SetScale(FVector3 scale)
{
	Transform.Scale = scale;
}

LTexture * GameObject2D::GetSprite()
{
	return Sprite;
}

void GameObject2D::Rotate2D(double angle)
{
	RotationAngle += angle;
}

double GameObject2D::GetRotation2D()
{
	return RotationAngle;
}

void GameObject2D::Update(float deltaTime)
{
}

void GameObject2D::Render()
{
	Sprite->Render(Transform.Position.x, Transform.Position.y, -RotationAngle);
}
