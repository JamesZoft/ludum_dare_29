#pragma once
class Vector2d
{
public:
	Vector2d();
	~Vector2d();
	float getX();
	float getY();
	void Vector2d::setX(float _x);
	void Vector2d::setY(float _y);
private:
	float x;
	float y;
};

