#pragma once
#include "GameObject.h"
class SkylarkBall : public GameObject
{
public:
	void setVelocity(sf::Vector2f vel);

	virtual void update(float delta) override;

private:
	sf::Vector2f mVelocity;

protected:


	virtual void initialize() override;

};

