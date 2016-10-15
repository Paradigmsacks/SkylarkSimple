#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
class Game;
	class GameObject :
		public sf::Sprite,
		public std::enable_shared_from_this<GameObject>
	{
	public:
		typedef std::shared_ptr<GameObject> GoPtr;

		//Main rendering function
		void render(sf::RenderTarget& target, sf::RenderStates states, double alpha);

		//Engine methods
		void update_Engine(float delta);


		void addChild(std::shared_ptr<GameObject> gObject);
		void setParent(GameObject::GoPtr parent);
		void setGame(std::shared_ptr<Game> game);
		const std::vector<GoPtr>& getChildren() const;
	protected:
		//Virtual methods that can be overridden
		virtual void initialize();
		virtual void update(float delta);


		std::vector<GoPtr> mChildren;
		std::weak_ptr<GameObject> mParent;
		std::shared_ptr<Game> getGame();
		std::weak_ptr<Game> mTheGame;

		bool isInitialized = false;
	private:
		sf::Vector2f previousPosition;


	};

