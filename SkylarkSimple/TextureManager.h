#pragma once
#include <memory>
#include <map>
#include "SFML\Graphics.hpp"
class TextureManager
{
public:
	TextureManager() {};
	~TextureManager() {};
	void loadTextures();
	typedef std::shared_ptr<sf::Texture> TexPtr;
	bool loadTexture(std::string name, std::string filename);
	TexPtr getTexture(std::string name);
private:
	std::map<std::string,TexPtr> mTextures;
};

