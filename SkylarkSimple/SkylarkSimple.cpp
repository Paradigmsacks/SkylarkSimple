// SkylarkSimple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <memory>

int main()
{	
	std::shared_ptr<Game> mGame = std::make_shared<Game>();
	mGame->initialize();
	mGame->mainLoop();
    return 0;
}

