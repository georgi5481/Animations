//Corresponding header
#include "Engine/EngineConfigLoader.h"

#include<cstdint>

//3rd-party includes


//Own includes
#include "common/commonDefines.h"

//constants
namespace{		//the anonymous namespace will work only on this .cpp file
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 600;
constexpr auto WINDOW_NAME = "Texts";


constexpr auto PRESS_KEYS_WIDTH = 640;			//here you can scale manually the pictures
constexpr auto PRESS_KEYS_HEIGHT = 480;

constexpr auto LAYER_2_IMG_WIDTH = 160;
constexpr auto LAER_2_IMG_HEIGHT = 120;

constexpr auto MAX_FRAMERATE = 30;

constexpr auto ANGELINE_VINTAGE_40_FONTSIZE = 120;	//we can load the same font with a different size аt the same time
}

static std::string getFilePath(const std::string& relativePath){
#ifdef RELEASE_BUILD
	return relativePath;
#else
	return "../" + relativePath;
#endif
}

static void populateImageContainerConfig(ImageContainerCfg& cfg){

	ImageCfg imageCfg;
	imageCfg.location = getFilePath("resources/pictures/press_keys.png");
	imageCfg.height = PRESS_KEYS_WIDTH;
	imageCfg.width = PRESS_KEYS_HEIGHT;

	cfg.imageConfigs.insert(std::make_pair(TextureId::PRESS_KEYS,imageCfg));	//we have to pair them first with the ID


	imageCfg.location = getFilePath("resources/pictures/layer_2.png");
	imageCfg.height = LAYER_2_IMG_WIDTH;
	imageCfg.width = LAER_2_IMG_HEIGHT;

	cfg.imageConfigs.insert(std::make_pair(TextureId::LAYER_2,imageCfg));	//we have to pair them first with the ID
}


static void populateTextContainerConfig(TextContainerCfg& cfg){
	FontCfg fontCfg;
	fontCfg.location = getFilePath("resources/fonts/AngelineVintage.ttf");
	fontCfg.fontSize = ANGELINE_VINTAGE_40_FONTSIZE;

	cfg.fontConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE_40,fontCfg));	//we have to pair them first with the ID

}


static void populateMonitorConfig(MonitorWindowCfg& cfg){
	cfg.windowName = WINDOW_NAME;
	cfg.windowWidth = WINDOW_WIDTH;
	cfg.windowHeight = WINDOW_HEIGHT;
	cfg.windowFlags = WINDOW_SHOWN;
}

static void populateRsrcMgrConfig(RsrcMgrCfg& cfg){		//for better reading when configuring cown bellow

	populateImageContainerConfig(cfg.imageContainerCfg);
	populateTextContainerConfig(cfg.textContainerCfg);
}


static void populateDrawMgrConfig(DrawMgrCfg& cfg){		//for better reading when configuring cown bellow

	populateMonitorConfig(cfg.windowCfg);

	cfg.maxFrameRate = MAX_FRAMERATE;
}


void populateManagerHandlerCfg(ManagerHandlerCfg& cfg){
	populateDrawMgrConfig(cfg.drawMgrCfg);
	populateRsrcMgrConfig(cfg.rsrcMgrCfg);
}

static void populateGameConfig(GameCfg& cfg){
	cfg.layer2RsrcId = TextureId::LAYER_2;
	cfg.pressKeysRsrcId = TextureId::PRESS_KEYS;
	cfg.textFontId = FontId::ANGELINE_VINTAGE_40;	//place unique key for our flyweight design pattern
}






EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;
	populateManagerHandlerCfg(cfg.managerHandlerCfg);

	populateGameConfig(cfg.gameCfg);

	return cfg;
}
