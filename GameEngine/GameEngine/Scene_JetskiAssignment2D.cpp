#include "Scene_JetskiAssignment2D.h"
#include "PhysicsBody2D.h"
#include <fstream>
#include "Game2D.h"



void Scene_JetskiAssignment2D::SaveData()
{
	for (int i = 0; i < DataList.size(); i++)
	{
		DataList[i]->x.push_back(DataList[i]->Jetski->GetTransform().Position.x/WorldScale);
		DataList[i]->y.push_back(DataList[i]->Jetski->GetTransform().Position.y/WorldScale);
	}
}

void Scene_JetskiAssignment2D::WriteOutputFile()
{
	std::ofstream OutputFile;
	OutputFile.open("jump.csv");

	OutputFile << "Time,";

	//Write the Hedear fo the Data Table
	for (int i = 0; i < DataList.size(); i++)
	{
		OutputFile << "Jetski" << i + 1 << " PosX," << "Jetski" << i + 1 << " PosY,";
	}
	//Skip to the next line
	OutputFile << std::endl;

	//For each interval of data saved
	for (int i = 0; i < DataList[0]->x.size(); i++)
	{
		//Write the tiime
		OutputFile << DataTimeSkip * i  << ",";

		//For each Jetski
		for (int j = 0; j < DataList.size(); j++)
		{
			//Write Position X and Y
			OutputFile << DataList[j]->x[i] << ",";
			OutputFile << DataList[j]->y[i] << ",";

		}

		//Skip to the next line
		OutputFile << std::endl;
	}
}

void Scene_JetskiAssignment2D::SetJetski(PhysicsBody2D * Jetski, float Mass, Game2D * jetskiGame)
{
	jetskiGame->AddToGameObjectList(Jetski);
	Jetski->SetPosition(FVector3(0, 30, 0));
	Jetski->SetScale(WorldScale/50);
	Jetski->SetVelocity(FVector3(0));
	Jetski->SetMass(Mass);
	Jetski->GetSprite()->LoadFromFile("Textures/Jetski.png");
	DataSaver * dsJetski = new DataSaver;
	dsJetski->Jetski = Jetski;
	DataList.push_back(dsJetski);
}

Scene_JetskiAssignment2D::Scene_JetskiAssignment2D()
{
	Game2D * JetskiGame = new Game2D();

	PhysicsBody2D * Jetski1 = new PhysicsBody2D();
	SetJetski(Jetski1, 200, JetskiGame);

	PhysicsBody2D * Jetski2 = new PhysicsBody2D();
	SetJetski(Jetski2, 400, JetskiGame);

	GameObject2D * Ramp = new GameObject2D();
	JetskiGame->AddToGameObjectList(Ramp);
	Ramp->SetPosition(FVector3(11*WorldScale + Ramp->GetSprite()->GetWidth()*(WorldScale/50), 30, 0));
	Ramp->SetScale(WorldScale / 50);
	Ramp->GetSprite()->LoadFromFile("Textures/Ramp.png");

	GameObject2D * Ocean = new GameObject2D(FTransform());
	Ocean->SetPosition(FVector3(1200,10 - Ocean->GetSprite()->GetHeight(), 0));
	JetskiGame->AddToGameObjectList(Ocean);
	Ocean->SetScale(FVector3(1, WorldScale/50, 1));
	Ocean->GetSprite()->LoadFromFile("Textures/Ocean.png");

	int RampRotationSpeed = 60;;

	while (!JetskiGame->Quit())
	{
		JetskiGame->HandleEvents();

		if (!JetskiGame->Paused())
		{
			for (int i = 0; i < JetskiGame->GetGameObject2DList().size(); i++)
			{
				if (dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i]))
				{
					if (JetskiGame->GetGameObject2DList()[i]->GetTransform().Position.x < 10* WorldScale)
					{
						dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->AddForce(FVector3(3000 * WorldScale, 0, 0));
					}
					else if (dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetTransform().Position.x < 14.33 * WorldScale)
					{
						if (dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetRotation2D() < 30)
						{
							FVector3 newVelocity = dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetVelocity();
							newVelocity.RotateZ(30*deltaTime*RampRotationSpeed);
							dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->SetVelocity(newVelocity);
							dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->Rotate2D(30*deltaTime*RampRotationSpeed);
						}
						FVector3 ForceVector = FVector3(3000, 0, 0);
						ForceVector -= FVector3(dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetMass()*9.8*cos(30) * WorldScale, 0, 0);
						ForceVector.RotateZ(30);
						dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->AddForce(ForceVector);
					}
					else if(dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetTransform().Position.y > 30)
					{
						dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->AddForce(FVector3(0, -dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetMass()*9.8 * WorldScale,0));
					}
					else if(dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetRotation2D() > 0)
					{
						FVector3 newVelocity = FVector3(dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetVelocity().x, 0, 0);
						dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->SetVelocity(newVelocity);

						FVector3 newPosition = FVector3(dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->GetTransform().Position.x, 30, 0);
						dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->SetPosition(newPosition);

						dynamic_cast<PhysicsBody2D*>(JetskiGame->GetGameObject2DList()[i])->Rotate2D(-30*deltaTime*RampRotationSpeed);
						FirstLand = true;
					}
				}
			}
			JetskiGame->Update(deltaTime);
			JetskiGame->Render();
			//Divide time by DataTimeSkip then remove the int part of it, if the result is 0, a hole DataTimeSkipe interval has passed
			if (DataFrameCounter%DataFrameMark == 0)
			{
				SaveData();
			} 
			DataFrameCounter++;

			SDL_Delay(deltaTime * 1000);

			if (Jetski1->GetTransform().Position.y <= 30 && Jetski2->GetTransform().Position.y == 30 && FirstLand)
			{
				JetskiGame->SetQuit(true);
			}
		}
	}
	WriteOutputFile();
	JetskiGame->Close();

	printf("Press enter to end...");
	getchar();
}

Scene_JetskiAssignment2D::~Scene_JetskiAssignment2D()
{
}
