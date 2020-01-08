#ifndef GAMEOBJECT_
#define GAMEOBJECT_

#include "FTransform.h"

class Game;

class GameObject
{
protected:

	//Reference to wich game this object is on
	Game * CurrentGame;

	//Stores the objectes position, rotation and scale
	FTransform Transform;

	//I need the compiler to know this is a polimorth class, will be removed later
	virtual void PolymorthFlag();

public:
	///Constructors

	GameObject();

	GameObject(Game * game);

	GameObject(FTransform transform);

	GameObject(FVector3 position, FQuaternion rotation = FQuaternion(), FVector3 scale = FVector3(1));

	~GameObject();

	//Returns the objects transform
	FTransform GetTransform();

	void SetTransform(FTransform transform);

	void SetPosition(FVector3 position);

	void SetRotation(FQuaternion rotation);
};
#endif
