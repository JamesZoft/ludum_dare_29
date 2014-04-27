#pragma once
#include "OceanObject.h"
#include "Window.h"

class Monster : public OceanObject
{
public:
	Monster();
	~Monster();
	bool move();
	void setRectX(int);
private:
	int ticksOnCreation;
};

