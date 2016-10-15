#include "stdafx.h"
#include "GameObject.h"
#include <memory>
#include "../Game.h"


	void GameObject::addChild(std::shared_ptr<GameObject> gObject)
	{
		gObject->setParent(shared_from_this());
		mChildren.push_back(gObject);
	}

	void GameObject::setParent(GameObject::GoPtr parent)
	{
		mParent = parent;
	}

	const std::vector<GameObject::GoPtr>& GameObject::getChildren() const
	{
		return mChildren;
	}

	std::shared_ptr<Game> GameObject::getGame()
	{
		return mTheGame.lock();
	}

	void GameObject::setGame(std::shared_ptr<Game> game)
	{
		mTheGame = game;
	}

	void GameObject::update_Engine(float delta)
	{
		//This update is called by the main loop. Does some basic stuff
		//then passes responsibility to the virtual method update
		if (!isInitialized)
		{
			initialize();
			isInitialized = true;
		}
		previousPosition = getPosition();
		update(delta);
	}

	void GameObject::initialize()
	{

	}

	void GameObject::update(float delta)
	{

	}

	void GameObject::render(sf::RenderTarget& target, sf::RenderStates states, double alpha)
	{
		//Interpolate previous and current position based on alpha
		sf::Vector2f currentPos = getPosition();
		sf::Vector2f change = currentPos - previousPosition;
		states.transform.translate(-change);
		change.x *= alpha;
		change.y *= alpha;
		states.transform.translate(change);
		
		target.draw(*this, states);
	}
