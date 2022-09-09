//Corresponding header3
#include "Game/Game.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>
//3rd-party includes


//Own components includes
//#include "sdl_utils/config/MonitorWindowCfg.h"
#include "sdl_utils/InputEvent.h"

int32_t Game::init(const GameCfg& cfg){
	_mousePosText.create("_", cfg.textFontId, Colors::GREEN);
	_mousePosText.hide();
	return EXIT_SUCCESS;
}

void Game::deinit(){

}

void Game::draw(){
	_mousePosText.draw();
}

void Game::handleEvent([[maybe_unused]]const InputEvent& e){
	if(TouchEvent::TOUCH_PRESS != e.type){	//if we dont touch with the mouse - do nothing
		return;
	}

	setMousePosText(e.pos);
}

void Game::setMousePosText(const Point& mousePos){
	_mousePosText.show();
	_mousePosText.setPosition(mousePos);
	std::string textContent = "X";
		textContent.append(std::to_string(mousePos.x))
					.append(" , Y: ")
					.append(std::to_string(mousePos.y));

		_mousePosText.setText(textContent);
}
