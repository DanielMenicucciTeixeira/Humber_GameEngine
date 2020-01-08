#include "Scene_Starship.h"
#include "FVector3.h"


void Scene_Starship::WriteTableLine()
{
	if (Starship == nullptr)
	{
		printf("Starhip is NUll\n");
		return;
	}

	TableString += std::to_string((int)(Time*DeltaTime));
	TableString += "\t";
	TableString += std::to_string(TurbineTorque);
	TableString += "\t";
	TableString += std::to_string(ShipAngularAcceleration);
	TableString += "\t";
	TableString += std::to_string(Starship->GetAngularVelocity());
	TableString += "\t";
	TableString += std::to_string(Starship->GetAngle());
	TableString += "\t";
	TableString += std::to_string(TurbineForce.x);
	TableString += "\t";
	TableString += std::to_string(TurbineForce.y);
	TableString += "\t";
	TableString += std::to_string(ShipAcceleration.x);
	TableString += "\t";
	TableString += std::to_string(ShipAcceleration.y);
	TableString += "\t";
	TableString += std::to_string(Starship->GetVelocity().x);
	TableString += "\t";
	TableString += std::to_string(Starship->GetVelocity().y);
	TableString += "\t";
	TableString += std::to_string(Starship->GetTransform().Position.x);
	TableString += "\t";
	TableString += std::to_string(Starship->GetTransform().Position.y);
	TableString += "\n";
}

void Scene_Starship::CreateStarship()
{
	Starship = new PhysicsBody2D;
	Starship->SetMass(1000000.0f);
	Starship->SetRotationalInertia(26700000000.0f);
	TurbineForce = FVector3(50000000.0f, 0.0f, 0.0f);
	TurbineTorque = 629100000.0f;
}

void Scene_Starship::OnCreate()
{
	Table.open("StarShip.csv");
	CreateStarship();
	TableString = "Time\tTorque\tAngularAcceleration\tAngularVelocity\tAngle\tForce X\tForce Y\tAcceleration X\tAcceleration Y\tVelocity X\tVelocity Y\tPosition x\t Positoin Y\n";

	while (Time <= 60 / DeltaTime )
	{
		if (Time*DeltaTime < 31.0f)
		{
			Starship->AddForce(TurbineForce);
		}
		else if (Time*DeltaTime < 51.0f)
		{
			Starship->AddTorque(TurbineTorque);
			RotationMatrix.SetToRotationMatrix(Y, Starship->GetAngle(), true);
			TurbineForce = RotationMatrix * TurbineForce;
			Starship->AddForce(TurbineForce/2);
		}

		ShipAcceleration = Starship->GetAcceleration();
		ShipAngularAcceleration = Starship->GetAngularAcceleration();
		Starship->Update(DeltaTime);

		if ((int)Time%((int)(1/DeltaTime)) == 0)
		{
			WriteTableLine();
		}

		Time ++;
	}
	
	std::cout << TableString;
	Table << TableString;
	Table.close();
	getchar();
}

Scene_Starship::Scene_Starship()
{
	OnCreate();
}


Scene_Starship::~Scene_Starship()
{
	delete(Starship);
}
