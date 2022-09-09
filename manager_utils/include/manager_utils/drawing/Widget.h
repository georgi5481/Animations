#ifndef MANAGER_UTILS_INCLUDE_MANAGER_UTILS_DRAWING_WIDGET_H_
#define MANAGER_UTILS_INCLUDE_MANAGER_UTILS_DRAWING_WIDGET_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "utils/drawings/DrawParams.h"

//Forward Declaration


class Widget {		//picking a class(not a structure)  only cuz we  need that private hiding effect
public:
	void draw();
	//setter & getters
	void reset();

	void setWidth(int32_t width);
	void setHeight(int32_t height);

	int32_t getWidth() const;
	int32_t getHeight() const;

	void setPosition(const Point& pos);
	void setPosition(int32_t x, int32_t y);
	void setOpacity(int32_t opacity);

	int32_t getOpacity() const;
	Point getPosition() const;

	void activateAlphaModulation();
	void deactivateAlphaModulation();

	void show();
	void hide();

	void moveRight(int32_t delta);
	void moveLeft(int32_t delta);
	void moveUp(int32_t delta);
	void moveDown(int32_t delta);

	//move methods could be added for convenience
	//show & hide methods could alse be implemented for convenience
protected:
	DrawParams _drawParams;

	bool _isCreated = false;
	bool _isDestroyed = true;
	bool _isVisible = true;
	bool _isAlphaModulationEnabled = false;


};


#endif /* MANAGER_UTILS_INCLUDE_MANAGER_UTILS_DRAWING_WIDGET_H_ */
