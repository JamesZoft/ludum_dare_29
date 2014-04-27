#include "MonsterController.h"
#include "GameAttributeManager.h"

MonsterController::MonsterController()
{
}


MonsterController::~MonsterController()
{
}

void MonsterController::createMonster()
{
	if (monsters.size() + 1 <= MAX_MONSTERS)
	{
		monsters.push_back(new Monster());
	}
}
void MonsterController::createMonsters()
{
	for (int i = 0; i < (MAX_MONSTERS - monsters.size()); i++)
	{
		createMonster();
	}
}
int MonsterController::checkDestroyMonsters(SDL_Rect rectB, GameAttributeManager &mgr)
{
	std::list<Monster*> remainingMonsters;
	for (Monster* m : monsters)
	{
		if (!Window::basicSdlRectsIntersect(m->getRect(), rectB))
		{
			remainingMonsters.push_back(m);
		}
		else
		{
			mgr.updateScore();
		}
	}
	monsters = remainingMonsters;
	return monsters.size() - remainingMonsters.size();
}

void MonsterController::moveAndDrawMonsters()
{
	for (Monster* m : monsters)
	{
		m->move();
		m->addRectY(m->getVelocity().getY());
		m->draw();
	}
}


void MonsterController::createBarrel()
{
	if (barrels.size() + 1 <= MAX_BARRELS)
	{
		barrels.push_back(new ExplosiveBarrel());
	}
}
void MonsterController::createBarrels()
{
	for (int i = 0; i < (MAX_BARRELS - barrels.size()); i++)
	{
		createBarrel();
	}
}
int MonsterController::checkDestroyBarrels(SDL_Rect rectB, GameAttributeManager &mgr)
{
	std::list<ExplosiveBarrel*> remainingBarrels;
	for (ExplosiveBarrel* b : barrels)
	{
		if (!Window::basicSdlRectsIntersect(b->getRect(), rectB))
		{
			remainingBarrels.push_back(b);
		}
		else
		{
			return -1;
		}
	}
	barrels = remainingBarrels;
	return barrels.size() - remainingBarrels.size();
}

void MonsterController::moveAndDrawBarrels()
{
	for (ExplosiveBarrel* b : barrels)
	{
		b->move();
		b->addRectY(b->getVelocity().getY());
		b->draw();
	}
}