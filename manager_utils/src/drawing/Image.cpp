//Coresponding Headerrectangle
#include "manager_utils/drawing/Image.h"

//C system includes

//C++ system includes
#include<iostream>
//3rd-party includes

//Own includes
#include "manager_utils/managers/RsrcMgr.h"

Image::~Image(){
	if(_isCreated && !_isDestroyed) {
		destroy();
	}
}

void Image::create(int32_t rsrcId, const Point& pos){	//parsing default parameter Point can be done only in the header file
	if(_isCreated){
		std::cerr << "Error, image with rsrcId: " << rsrcId
				<< " was already created. Will not create twice. " << std::endl;
	}
	const Frames& frames = gRsrcMgr->getImageFrame(rsrcId);
	const auto& firstFrame = frames.front();	//taking a const reference of the first element of the vector
	_drawParams.frameRect = firstFrame;

	_drawParams.rsrcId = rsrcId;
	_drawParams.width = _drawParams.frameRect.w;
	_drawParams.height = _drawParams.frameRect.h;
	_drawParams.pos = pos;
	_drawParams.widgetType = WidgetType::IMAGE;

	_isCreated = true;
	_isDestroyed = false;
}

void Image::destroy(){
	if(!_isCreated){
		std::cerr << "Error, image was already destroyed" << std::endl;
		return;
	}

	_isCreated = false;
	_isDestroyed = false;
	Widget::reset();
}


