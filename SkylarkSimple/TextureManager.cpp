#include "stdafx.h"
#include "TextureManager.h"



void TextureManager::loadTextures()
{
	bool loaded = loadTexture("skylark_ball", "skylark.png");
	int a = 1;
}

bool TextureManager::loadTexture(std::string name, std::string filename)
{
	TexPtr newTexture = std::make_shared<sf::Texture>();
	bool loadSuccess = newTexture->loadFromFile(filename);
	if (!loadSuccess)
	{
		return false;
	}

	//Loaded successfully
	mTextures.emplace(std::make_pair(name, newTexture));
	return true;

}

TextureManager::TexPtr TextureManager::getTexture(std::string name)
{
	auto it = mTextures.find(name);
	if (it != mTextures.end())
	{
		return it->second;
	}

	//Not found
	return nullptr;
}


