#include <iostream>
#include <ctime>
#include <string>

using namespace std;


struct NPC
{
	int strength;
	int health;
	int tiredness;
	int xpos;
	int ypos;
	bool alive;
};

NPC* createNPC()
{
	NPC* newNPC = new NPC;
	//value between 3 and 20
	newNPC->strength = rand() % 18 + 3;
	//value between 50 and 200
	newNPC->health = rand() % 151 + 50;
	//value between 1 and 14
	newNPC->tiredness = rand() % 14 + 1;
	//position between 0 and 100
	newNPC->xpos = rand() % 100 + 1;
	newNPC->ypos = rand() % 100 + 1;
	//alive = true
	newNPC->alive = true;

	return newNPC;
}

void printNPCDetails(const NPC* npc)
{
	string isAlive = "";
	if (npc->alive == 1)
	{
		isAlive += "Yes";
	}
	else
	{
		isAlive += "No";
	}
	cout << "NPC's Current State:" << endl;
	cout << "Position: (" << npc->xpos << ", " << npc->ypos << ")" << endl;
	cout << "Health: " << npc->health << endl;
	cout << "Strength: " << npc->strength << endl;
	cout << "Tiredness: " << npc->tiredness << endl;
	cout << "Alive: " << isAlive << endl;
}


int main()
{
	srand(time(0));
	NPC* pArray[10];
	//populate array with null
	for (int i = 0; i < 10; i++)
	{
		pArray[i] = NULL;
	}
	//create 10NPC structs and store them 
	for (int i = 0; i < 10; i++)
	{
		pArray[i] = createNPC();
	}
	//print NPC details
	for (int i = 0; i < 10; i++)
	{
		printNPCDetails(pArray[i]);
	}

	return 0;
}