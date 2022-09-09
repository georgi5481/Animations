#ifndef MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_DRAWMGR_H_
#define MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_DRAWMGR_H_		//first singleton object
//C system includes

//C++ system includes


//3rd-party includes

//Own includes
#include "manager_utils/managers/MgrBase.h"
#include "sdl_utils/MonitorWindow.h"
#include "sdl_utils/Renderer.h"

//Forward Declaration
struct DrawMgrCfg;

class DrawMgr : public MgrBase {
public:
	DrawMgr() = default;

	DrawMgr(const DrawMgr& other) = delete;	//copy constructor
	DrawMgr(DrawMgr&& other) = delete;		//move constructor

	DrawMgr& operator=(const DrawMgr& other) = delete;	//copy-assignment operator
	DrawMgr& operator=(DrawMgr&& other) = delete;	//move-assignment operator

	int32_t init(const DrawMgrCfg& cfg);	//we dont make the init methor virtual cuz every singleton will take configuration that is different

	void deinit() final; 	//removing the virtual keyword cuz we place it on the top of the chain
	void process() final; 	//and placing the 'final' keyword (instead of override) cuz this means that this is gonna be the last overriding in the chain
							//this will give the compiler a chance to devirtualise the functions in some cases

	void clearScreen();
	void finishFrame();
	void addDrawCmd(const DrawParams& drawParams);

	void setWidgetBledMode(const DrawParams &drawParams, BlendMode blendMode);
	void setWidgetOpacity(const DrawParams &drawParams, int32_t opacity);

private:
	SDL_Texture* getTextureInternal(const DrawParams& drawParams) const;
	MonitorWindow _window;
	Renderer _renderer;

	//hold maximum frame rate cap
	uint32_t _maxFrames{0};
};

extern DrawMgr *gDrawMgr;	//declared in the corresponding .cpp file, but set/initialised somewhere else in other .cpp file

#endif /* MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_DRAWMGR_H_ */
