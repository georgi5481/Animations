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
	_heroImg.create(heroRsrcId, Point(400,200));

return EXIT_SUCCESS;
}

void Hero::deinit(){	//no need for implementation. It will call the destructor of image

}


void Hero::draw(){
_heroImg.draw();
}
void Hero::handleEvent([[maybe_unused]]const InputEvent& e){

}
