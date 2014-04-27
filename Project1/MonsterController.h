#pragma once
#include <list>
#include "Monster.h"
#include "GameAttributeManager.h"
#include "ExplosiveBarrel.h"

class MonsterController
{
public:
	MonsterController();
	~MonsterController();
	void createMonster();
	void createMonsters();
	/**
	* Checks if any monsters need destroying, and if so, destroys them
	* @param rect The SDL_Rect to check any monster intersections with
	* @returns The number of monsters destroyed
	*/
	int checkDestroyMonsters(SDL_Rect rect, GameAttributeManager& mgr);
	void moveAndDrawMonsters();

	void createBarrel();
	void createBarrels();
	/**
	* Checks if any monsters need destroying, and if so, destroys them
	* @param rect The SDL_Rect to check any monster intersections with
	* @returns The number of monsters destroyed
	*/
	int checkDestroyBarrels(SDL_Rect rect, GameAttributeManager& mgr);
	void moveAndDrawBarrels();
private:
	std::list<Monster*> monsters;
	const int MAX_MONSTERS = 10;
	std::list<ExplosiveBarrel*> barrels;
	const int MAX_BARRELS = 4;
};

