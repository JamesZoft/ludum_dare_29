#pragma once
#include "OceanObject.h"
#include "Window.h"

class ExplosiveBarrel : public OceanObject
{
public:
	ExplosiveBarrel();
	~ExplosiveBarrel();
	void addRectY(int) override;
	bool move();
	void setRectX(int);
private:
	int ticksOnCreation;
};

