//Coresponding Header
#include "manager_utils/managers/DrawMgr.h"
//C system includes

//C++ system includes
#include<iostream>
#include<cstdint>
//3rd-party includes

//Own includes
#include "manager_utils/config/DrawMgrCfg.h"
#include "manager_utils/managers/RsrcMgr.h"

//#include "sdl_utils/Renderer.h"

DrawMgr *gDrawMgr = nullptr;

int32_t DrawMgr::init(const DrawMgrCfg& cfg){
	if (EXIT_SUCCESS != _window.init(cfg.windowCfg)){		//load the size of the window
			std::cerr << "loadResources() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _renderer.init(_window.getWindow())){		//get the render algorithm
			std::cerr << "render init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

return EXIT_SUCCESS;
}


void DrawMgr::deinit() {

	_renderer.deinit();
	_window.deinit();

}

void DrawMgr::process(){
//empty
}



void DrawMgr::clearScreen(){
	_renderer.clearScreen();	//always start drawing the frame with clearing the screen
}

void DrawMgr::finishFrame(){
	_renderer.finishFrame();
}

void DrawMgr::addDrawCmd(const DrawParams& drawParams){
	SDL_Texture* texture = getTextureInternal(drawParams);
	_renderer.renderTexture(texture,drawParams);
}

void DrawMgr::setWidgetBledMode(const DrawParams &drawParams, BlendMode blendMode){
	SDL_Texture* texture = getTextureInternal(drawParams);
	_renderer.setWidgetBledMode(texture, blendMode);
}

void DrawMgr::setWidgetOpacity(const DrawParams &drawParams, int32_t opacity){
	SDL_Texture* texture = getTextureInternal(drawParams);
	_renderer.setWidgetOpacity(texture, opacity);
}

SDL_Texture* DrawMgr::getTextureInternal(const DrawParams& drawParams) const{

	if(WidgetType::IMAGE == drawParams.widgetType){
		return gRsrcMgr->getImageTexture(drawParams.rsrcId);
	}
	else if(WidgetType::TEXT == drawParams.widgetType){
		return gRsrcMgr->getTextTexture(drawParams.textId);
	}
	else{
		std::cerr << "Error, received unsupported widgetType : " << static_cast<int32_t>(drawParams.widgetType)
								<< " for rsrcId : " << drawParams.rsrcId << std::endl;
	}
	return nullptr;
}

