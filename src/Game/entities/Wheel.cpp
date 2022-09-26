//Coresponding Header
#include "include/Game/entities/Wheel.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<stdlib.h>
//3rd-party includes

//Own includes
#include "sdl_utils/InputEvent.h"


int32_t Wheel::init(int32_t wheelRsrcId){

	_wheelImg.create(wheelRsrcId);

	return EXIT_SUCCESS;

}
void Wheel::draw(){
	_wheelImg.draw();
}
void Wheel::handleEvent(const InputEvent& e){

	if(TouchEvent::KEYBOARD_PRESS != e.type){
		return;
	}

	switch(e.key){		//rotation for the wheel
	case Keyboard::KEY_E:
		_wheelImg.rotateRight(10);
		break;
	case Keyboard::KEY_Q:
		_wheelImg.rotateLeft(10);
		break;

	case Keyboard::KEY_P:
		_wheelImg.setRotationPoint(Point::ZERO);
		break;
	case Keyboard::KEY_O:{
		Point rotCenter(_wheelImg.getWidth(), _wheelImg.getHeight());
		rotCenter.x /=2;
		rotCenter.y /=2;

		_wheelImg.setRotationPoint(rotCenter);


		}
		break;


	default:
		break;
	}
}
