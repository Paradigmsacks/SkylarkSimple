#pragma once
#include <memory>
#include <SFML\Graphics.hpp>
#include "GameObjects\SkylarkBall.h"
#include "TextureManager.h"



class GameObject;
class Game : public std::enable_shared_from_this<Game>
{
public:
	Game();
	~Game();

	void initialize();
	void mainLoop();


	//Globally accessible getters
	std::shared_ptr<sf::RenderWindow>  getWindow();


	/*
		Adds a GameObject to the vector of gameobjects. 
		This automatically sets a weak_ptr to the 
		Game inside the GameObject
	*/

	template <class T>
	std::shared_ptr<GameObject> addGameObject(T& obj)
	{
		//Forward to other method
		std::shared_ptr<T> objPtr = std::make_shared<T>(obj);
		return addGameObject_Engine(objPtr);
	}

private:
	std::shared_ptr<sf::RenderWindow> mWindow;
	sf::Event mEvent;
	void createWindow();
	void pollEvents();
	void update(double delta);
	void render(double alpha);
	std::vector<std::shared_ptr<GameObject>> mGameObjects;
	std::unique_ptr<TextureManager> mTextureManager;
	std::shared_ptr<GameObject> addGameObject_Engine(std::shared_ptr<GameObject> obj);
};
