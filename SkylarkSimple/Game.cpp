#include "stdafx.h"
#include "Game.h"
#include "TextureManager.h"
#include "GameObjects/GameObject.h"
#include <iostream>


	Game::Game()
	{
	}


	Game::~Game()
	{
	}

	void Game::initialize()
	{
		createWindow();
		//Initialize texture manager
		mTextureManager.reset(new TextureManager());
		mTextureManager->loadTextures();

		//Create skylark
		SkylarkBall skylarkBall;
		skylarkBall.setTexture(*mTextureManager->getTexture("skylark_ball"));
		skylarkBall.setPosition(150, 150);
		skylarkBall.setVelocity(sf::Vector2f(500, 350));
		//Add to game
		addGameObject<SkylarkBall>(skylarkBall);
	}

	void Game::mainLoop()
	{
		sf::Clock mClock;
		mClock.restart();
		double accumulator = 0;
		float timestep = 1.0 / 30.0;
		double frametime = 0;

		while (mWindow->isOpen())
		{
			pollEvents();

			frametime = mClock.getElapsedTime().asSeconds();
			mClock.restart();
			if (frametime > timestep)
			{
				frametime = timestep;
			}
			accumulator += frametime;
			while (accumulator >= timestep)
			{
				update(timestep);
				accumulator -= timestep;


			}
			const double alpha = accumulator / timestep;
			render(alpha);
		}
	}

	void Game::createWindow()
	{
		mWindow = std::make_shared<sf::RenderWindow>();
		mWindow->create(sf::VideoMode(1600, 900), "SKYLARK", sf::Style::Default);

	}

	void Game::pollEvents()
	{
		if (mWindow->pollEvent(mEvent))
		{
			if (mEvent.type == sf::Event::KeyPressed)
			{
				if (mEvent.key.code == sf::Keyboard::Escape)
				{
					mWindow->close();
				}
			}

			if (mEvent.type == sf::Event::Closed)
			{
				mWindow->close();
			}
		}
	}

	void Game::update(double delta)
	{
		for each (GameObject::GoPtr gO in mGameObjects)
		{
			gO->update_Engine(delta);
		}

	}

	void Game::render(double alpha)
	{
		sf::RenderStates states;
		mWindow->clear(sf::Color::Color(51, 51, 51));
		for each (GameObject::GoPtr gO in mGameObjects)
		{
			gO->render(*mWindow, states,alpha);
		}
		mWindow->display();
	}

	std::shared_ptr<GameObject> Game::addGameObject_Engine(std::shared_ptr<GameObject> obj)
	{
		obj->setGame(shared_from_this());
		mGameObjects.push_back(obj);
		return obj;
	}

	std::shared_ptr<sf::RenderWindow>  Game::getWindow()
	{
		return mWindow;
	}
