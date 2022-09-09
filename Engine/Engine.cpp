//Corresponding header
#include "Engine/Engine.h"

//C headers

//C++ headers
#include<iostream>

//own includes
#include "Engine/config/EngineConfig.h"
#include "manager_utils/managers/DrawMgr.h"


#include "utils/thread/ThreadUtils.h"
#include "utils/Time/Time.h"

#include "sdl_utils/Texture.h"
#include "utils/drawings/Color.h"



int32_t Engine::init(const EngineConfig& cfg){

	if (EXIT_SUCCESS != _managerHandler.init(cfg.managerHandlerCfg)){			//scan what event occurred
			std::cerr << "ManagerHandler.init() failed." << std::endl;
			return EXIT_FAILURE;
	}


	if (EXIT_SUCCESS != _event.init()){			//scan what event occurred
			std::cerr << "InputEvent.init() failed." << std::endl;
			return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _game.init(cfg.gameCfg)){	//load the resources in the window
			std::cerr << "_game.init() failed." << std::endl;
			return EXIT_FAILURE;
	}


return EXIT_SUCCESS;
}




void Engine::deinit(){	//always deinitialise backwards according to initialisings
	_game.deinit();
	_event.deinit();


}

void Engine::start(){
	mainLoop();
}

void Engine::mainLoop(){
	Time time;

while(true){
	time.getElapsed().toMicroseconds();

	const bool shouldExit = processFrame();

		if(shouldExit){
			break;
		}

		limitFPS(time.getElapsed().toMicroseconds());
	}
}

void Engine::drawFrame(){

	gDrawMgr->clearScreen();	//first clear the screen


	_game.draw();


	gDrawMgr->finishFrame();
}



bool Engine::processFrame(){
	while(_event.pollEvent()){
		if(_event.checkForExitRequiest()){
			return true;
		}

		handleEvent();
	}

	drawFrame();

	return false;
}

void Engine::handleEvent(){
_game.handleEvent(_event);
}

void Engine::limitFPS(int64_t elapsedTimeMicroSeconds){
	constexpr auto maxFrames = 30;
	constexpr auto microSecondsInASecond = 1000000;
	constexpr auto microSecondsPerFrame = microSecondsInASecond / maxFrames;
	const int64_t sleepDurationMicroSeconds = microSecondsPerFrame - elapsedTimeMicroSeconds;

	if(sleepDurationMicroSeconds > 0){
	ThreadUtils::sleepFor(sleepDurationMicroSeconds);
	}
}






