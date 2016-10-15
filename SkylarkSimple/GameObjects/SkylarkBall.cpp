#include "stdafx.h"
#include "SkylarkBall.h"
#include "../Game.h"


void SkylarkBall::update(float delta)
{

	//Bounce
	sf::Vector2f currentPos = getPosition();
	sf::Vector2u screenSize = getGame()->getWindow()->getSize();
	int amt = 100;
	screenSize.x -= amt;
	screenSize.y -= amt;
	if (currentPos.x > screenSize.x)
	{
		mVelocity.x *= -1;
	}
	else if (currentPos.x < amt)
	{
		mVelocity.x *= -1;
	}

	if (currentPos.y > screenSize.y)
	{
		mVelocity.y *= -1;
	}
	else if (currentPos.y < amt)
	{
		mVelocity.y *= -1;
	}

	//Apply velocity
	move(mVelocity * delta);
	//Rotate?
	float angle = atan2(mVelocity.x, -mVelocity.y);
	setRotation(angle * 57.2958);
	
}

void SkylarkBall::initialize()
{
	sf::Vector2u s = getTexture()->getSize();
	setOrigin(s.x/2,s.y/2);
	setScale(1.5f, 1.5f5);
}

void SkylarkBall::setVelocity(sf::Vector2f vel)
{
	mVelocity = vel;
}

