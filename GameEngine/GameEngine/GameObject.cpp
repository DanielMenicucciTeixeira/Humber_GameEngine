#include "GameObject.h"
#include "Game.h"


void GameObject::PolymorthFlag()
{
}

GameObject::GameObject()
{
	Transform.Position = FVector3(0);
	Transform.Rotation = FQuaternion();
	Transform.Scale = FVector3(1);
}

GameObject::GameObject(Game * game)
{
	if(game) game->AddToGameObjectList(this);
}

GameObject::GameObject(FTransform transform)
{
	
}

GameObject::GameObject(FVector3 position, FQuaternion rotation, FVector3 scale)
{
	Transform.Position = position;
	Transform.Rotation = rotation;
	Transform.Scale = scale;
}


GameObject::~GameObject()
{
}

FTransform GameObject::GetTransform()
{
	return Transform;
}

void GameObject::SetTransform(FTransform transform)
{
	Transform = transform;
}

void GameObject::SetPosition(FVector3 position)
{
	Transform.Position = position;
}

void GameObject::SetRotation(FQuaternion rotation)
{
	Transform.Rotation = rotation;
}
