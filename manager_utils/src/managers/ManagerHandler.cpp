//Coresponding Header
#include "manager_utils/managers/ManagerHandler.h"

//C system includes
#include <cstdint>
#include<iostream>
//C++ system includes

//3rd-party includes

//Own includes
#include "manager_utils/config/ManagerHandlerCfg.h"
#include "manager_utils/managers/DrawMgr.h"
#include "manager_utils/managers/RsrcMgr.h"



int32_t ManagerHandler::init(const ManagerHandlerCfg& cfg){

	gDrawMgr = new DrawMgr();

	if(gDrawMgr == nullptr) {
		std::cerr << "Error, bad alloc for DrawMgr" << std::endl;
			return EXIT_FAILURE;
	}
	if (EXIT_SUCCESS != gDrawMgr->init(cfg.drawMgrCfg)){
			std::cerr << "gDrawMgr init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}



	gRsrcMgr = new RsrcMgr();

	if(gRsrcMgr == nullptr) {
		std::cerr << "Error, bad alloc for gRsrcMgr" << std::endl;
			return EXIT_FAILURE;
	}
	if (EXIT_SUCCESS != gRsrcMgr->init(cfg.rsrcMgrCfg)){
			std::cerr << "gRsrcMgr init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

		//downcasting pointers to MgrBase cuz the deinit method isn't pure virtual
	_managers[DRAW_MGR_IDX] = static_cast<MgrBase*>(gDrawMgr);
	_managers[RSRC_MGR_IDX] = static_cast<MgrBase*>(gRsrcMgr);
	return EXIT_SUCCESS;
}


void ManagerHandler::deinit(){
	for(int32_t i = MANAGERS_COUNT -1; i >= 0 ; i--){		//we have to deinitialise backwards
		_managers[i]->deinit();
		_managers[i] = nullptr;
	}
}

void ManagerHandler::process(){
	for(int32_t i = 0; i < MANAGERS_COUNT; ++i){		//caling the proces vitual function
		_managers[i]->process();						//that will override with the correct process method
	}

}

void ManagerHandler::nullifyGlobalMgr(int32_t mgrIdx){
	switch(mgrIdx){
	case DRAW_MGR_IDX:
		delete gDrawMgr;
		gDrawMgr = nullptr;
		break;
	case RSRC_MGR_IDX:
		delete gRsrcMgr;
		gRsrcMgr = nullptr;
		break;
	default:
		std::cerr << "Received invalid mgrIdx: " << mgrIdx << std::endl;
		break;
	}
}
