#ifndef GAME_GAME_H_
#define GAME_GAME_H_		//the game class should be the one that holds the game specific logic

//C system includes

//C++ system includes
#include <cstdint>
#include <string>

//3rd-party includes

//Own includes
#include "Game/config/GameCfg.h"
#include "manager_utils/drawing/Image.h"
#include "manager_utils/drawing/Text.h"

//Forward Declaration
struct InputEvent;

class Game {
public:

	int32_t init(const GameCfg& cfg);
	void deinit();
	void draw();
	void handleEvent(const InputEvent& e);

private:
	void setMousePosText(const Point& mousePos);
	Text _mousePosText;
};

#endif /* GAME_GAME_H_ */
