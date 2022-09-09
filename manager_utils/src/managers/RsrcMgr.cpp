//Coresponding Header
#include "manager_utils/managers/RsrcMgr.h"
//C system includes

//C++ system includes
#include <iostream>
//3rd-party includes

//Own includes
#include "manager_utils/config/RsrcMgrCfg.h"

RsrcMgr* gRsrcMgr = nullptr;

int32_t RsrcMgr::init(const RsrcMgrCfg& cfg){

	//since the object is already in the class we call the contructor method by defining the NameClass::NameOfFunction()
	if (EXIT_SUCCESS != ImageContainer::init(cfg.imageContainerCfg)){
			std::cerr << "imgContainer init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != TextContainer::init(cfg.textContainerCfg)){		//initialising the image container logic (a simple map  with int as ID and string as the path)
			std::cerr << "textContainer init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}
return EXIT_SUCCESS;
}


void RsrcMgr::deinit() {

	ImageContainer::deinit();
	TextContainer::deinit();

}
void RsrcMgr::process() {

}
