#ifndef MANAGER_UTILS_INCLUDE_MANAGER_UTILS_CONFIG_DRAWMGRCFG_H_
#define MANAGER_UTILS_INCLUDE_MANAGER_UTILS_CONFIG_DRAWMGRCFG_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "sdl_utils/config/MonitorWindowCfg.h"

//Forward Declaration


struct DrawMgrCfg{
	MonitorWindowCfg windowCfg;
	int64_t maxFrameRate;
};

#endif /* MANAGER_UTILS_INCLUDE_MANAGER_UTILS_CONFIG_DRAWMGRCFG_H_ */
