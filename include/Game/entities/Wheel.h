#ifndef INCLUDE_GAME_ENTITIES_WHEEL_H_
#define INCLUDE_GAME_ENTITIES_WHEEL_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include"manager_utils/drawing/Image.h"
//Forward Declaration
struct InputEvent;

class Wheel{
public:
	int32_t init(int32_t wheelRsrcId);
	//void deinit(); //no need to deinit cuz it will call the destructor of Image
	void draw();
	void handleEvent(const InputEvent& e);
private:

	Image _wheelImg;
};


#endif /* INCLUDE_GAME_ENTITIES_WHEEL_H_ */


