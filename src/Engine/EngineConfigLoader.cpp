//Corresponding header
#include "include/Engine/EngineConfigLoader.h"
//C++ headers
#include<cstdint>

//3rd-party includes


//Own includes
#include "include/common/commonDefines.h"

//constants
namespace{		//the anonymous namespace will work only on this .cpp file
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 600;
constexpr auto WINDOW_NAME = "Animations";


constexpr auto RUNNING_GIRL_WIDTH = 1536;			//here you can scale manually the pictures
constexpr auto RUNNING_GIRL_HEIGHT = 220;

constexpr auto WHEEL_IMG_WIDTH_HEIGHT = 695;

constexpr auto MAX_FRAMERATE = 30;

constexpr auto ANGELINE_VINTAGE_40_FONTSIZE = 80;	//we can load the same font with a different size аt the same time
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
	imageCfg.location = getFilePath("resources/pictures/sprites/running_girl.png");
	imageCfg.height = RUNNING_GIRL_WIDTH;
	imageCfg.width = RUNNING_GIRL_WIDTH;

	cfg.imageConfigs.emplace(TextureId::RUNNING_GIRL,imageCfg);	//we have to pair them first with the ID


	imageCfg.location = getFilePath("resources/pictures/wheel.png");
	imageCfg.height = WHEEL_IMG_WIDTH_HEIGHT;
	imageCfg.width = WHEEL_IMG_WIDTH_HEIGHT;

	cfg.imageConfigs.emplace(TextureId::WHEEL,imageCfg);	//we have to pair them first with the ID
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
