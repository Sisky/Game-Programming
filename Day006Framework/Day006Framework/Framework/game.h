// 717310 C++ SDL Framework
#ifndef __GAME_H__
#define __GAME_H__

// Forward Declarations
#include <vector>


class BackBuffer;
class InputHandler;
class Sprite;
class Player;
class Entity;
class Bullet;
class Background;
class Platform;

class Game
{
	//Member Methods:
public:
	static Game& GetInstance();
	static void DestroyInstance();
	~Game();

	bool Initialise();
	bool DoGameLoop();
	void Quit();

	void MoveSpaceShipLeft();
	void MoveSpaceShipRight();
	void FireSpaceShipBullet();
	void StopSpaceShipMovement();
	void Jump();

	void SpawnEnemy(float x, float y);
	void SpawnExplosion(int x, int y);
	void SpawnPlatform(float x, float y);

protected:
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

private:
	Game(const Game& game);
	Game& operator=(const Game& game);
	
	Game();

	//Member Data:
public:

protected:
	static Game* sm_pInstance;
	BackBuffer* m_pBackBuffer;
	InputHandler* m_pInputHandler;
	bool m_looping;

	// Simulation Counters:
	float m_elapsedSeconds;
	float m_lag;
	float m_executionTime;
	int m_lastTime;
	int m_frameCount;
	int m_FPS;
	int m_numUpdates;
	bool m_drawDebugInfo;

	// Game Entities:
	Player* m_pPlayer;
	Background* bg;
	Platform* plat;


	// Add an alien enemy container field.
	std::vector<Entity*> m_EnemyVector;
	//platforms
	std::vector<Platform*> m_PlatVector;

	// Add a bullet container field.
	std::vector<Bullet*> m_BulletVector;

private:

};

#endif // __GAME_H__
