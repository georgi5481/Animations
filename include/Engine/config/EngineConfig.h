#ifndef ENGINE_CONFIG_ENGINECONFIG_H_populateTextContainerConfig
#define ENGINE_CONFIG_ENGINECONFIG_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "manager_utils/config/ManagerHandlerCfg.h"
#include "include/Game/config/GameCfg.h"

//Forward Declaration

struct EngineConfig{
	ManagerHandlerCfg managerHandlerCfg;
	GameCfg gameCfg;
};



#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
