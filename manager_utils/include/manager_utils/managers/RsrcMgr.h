#ifndef MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_RSRCMGR_H_
#define MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_RSRCMGR_H_

//C system includes

//C++ system includes

//3rd-party includes

//Own includes
#include "manager_utils/managers/MgrBase.h"
#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/TextContainer.h"
struct RsrcMgrCfg;

//Forward Declaration


class RsrcMgr : public MgrBase ,
				public ImageContainer,
				public TextContainer {
public:
	RsrcMgr() = default;

	RsrcMgr(const RsrcMgr& other) = delete;	//copy constructor
	RsrcMgr(RsrcMgr&& other) = delete;		//move constructor

	RsrcMgr& operator=(const RsrcMgr& other) = delete;	//copy-assignment operator
	RsrcMgr& operator=(RsrcMgr&& other) = delete;	//move-assignment operator

	int32_t init(const RsrcMgrCfg& cfg);	//we dont need polymorfism

	void deinit() final; 	//final keyword means that this is the last overloading place in the inheritance chain
	void process() final;


};

extern RsrcMgr* gRsrcMgr;
#endif /* MANAGER_UTILS_INCLUDE_MANAGER_UTILS_MANAGERS_RSRCMGR_H_ */
