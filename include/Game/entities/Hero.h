#ifndef INCLUDE_GAME_ENTITIES_HERO_H_
#define INCLUDE_GAME_ENTITIES_HERO_H_

//C system includes

//C++ system includes

//3rd-party includes

//Own includes
#include"manager_utils/drawing/Image.h"
//Forward Declaration
struct InputEvent;

class Hero{
public:
	int32_t init(int32_t heroRsrcId);
	void deinit();
	void draw();
	void handleEvent(const InputEvent& e);

private:
	Image _heroImg;

};




#endif /* INCLUDE_GAME_ENTITIES_HERO_H_ */
