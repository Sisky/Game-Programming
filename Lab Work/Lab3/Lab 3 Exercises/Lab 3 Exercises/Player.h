#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player
{
public:
	Player();
	~Player();
	int getHealth() const;
	int getExperience() const;
	int getRageLevel() const;
	void setHealth(int h);
	void setExperience(int h);
	void setRageLevel(int h);
	void printStats();

private:
	int m_health;
	int m_experienceLevel;
	int m_rageLevel;
};

#endif // __PLAYER_H__