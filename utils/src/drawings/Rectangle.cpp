//Corresponding header
#include "utils/drawings/Rectangle.h"

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration

Rectangle::Rectangle(int32_t inputX, int32_t inputY, int32_t inputWidth,int32_t inputHeight)
										: x(inputX), y(inputY), w(inputWidth), h(inputHeight){
}

const Rectangle Rectangle::ZERO(0,0,0,0);
const Rectangle Rectangle::UNDEFINED(10000,10000,10000,10000);


bool Rectangle::operator==(const Rectangle& other) const{
	return (x ==other.x) && (y == other.y) && (w == other.w) && (h == other.h);
}

bool Rectangle::operator!=(const Rectangle& other) const{
	return !(*this == other);
}

bool Rectangle::isPointInside(const Point& point) const{
	const bool isInsideX = (x >= point.x) && (x + w < point.x);
	const bool isInsideY = (y >= point.y) && (y + w < point.y);

	return isInsideX && isInsideY;
}
