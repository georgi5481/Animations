//Coresponding Header
#include "include/Game/entities/Hero.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<stdlib.h>
//3rd-party includes

//Own includes
#include "sdl_utils/InputEvent.h"


int32_t Hero::init(int32_t heroRsrcId)
{
	_heroImg.create(heroRsrcId, Point(0,0));

return EXIT_SUCCESS;
}

void Hero::deinit(){	//no need for implementation. It will call the destructor of image

}


void Hero::draw(){
_heroImg.draw();
}
void Hero::handleEvent(const InputEvent& e){

	if(TouchEvent::KEYBOARD_PRESS != e.type){
		return;
	}

	switch(e.key){
	case Keyboard::KEY_NUMPAD_PLUS:
		_heroImg.setNextFrame();
		break;
	case Keyboard::KEY_NUMPAD_MINUS:
		_heroImg.setPrevFrame();
		break;

	default:
		break;
	}
}
