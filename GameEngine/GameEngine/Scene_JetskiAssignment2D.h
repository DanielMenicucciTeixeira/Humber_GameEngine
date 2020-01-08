#ifndef SCENE_JETSKIASSIGNMENT2D_
#define	SCENE_JETSKIASSIGNMENT2D_

#include <vector>

class PhysicsBody2D;
class Game2D;

//Used to store the data that will be saved at the end of the game.
struct DataSaver
{
	//Pointer to the jeski whose position we are recording 
	PhysicsBody2D * Jetski;
	
	//The 2D coordinates of the Jetskis position at every recorded time interaval;
	std::vector<float> x, y;
};

class Scene_JetskiAssignment2D
{
protected:

	//Used to store the data of every jetski
	std::vector<DataSaver*> DataList;
	
	float deltaTime = 0.1f;
	float DataTimeSkip = 1.0f;
	float Time = 0.0f;

	void SaveData();
	void WriteOutputFile();

	void SetJetski(PhysicsBody2D * Jetski, float Mass, Game2D * jetskiGame);

	int DataFrameMark = DataTimeSkip / deltaTime;
	int DataFrameCounter = 0;
	float WorldScale = 20;
	bool FirstLand = false;

public:
	Scene_JetskiAssignment2D();
	~Scene_JetskiAssignment2D();
};
#endif

