#ifndef UTILS_INCLUDE_UTILS_DRAWINGS_IMAGE_H_
#define UTILS_INCLUDE_UTILS_DRAWINGS_IMAGE_H_

//C system includes
#include <cstdint>
//C++ system includes

//3rd-party includes

//Own includes
#include "manager_utils/drawing/Widget.h"
//Forward Declaration

class Image : public Widget{
public:
	~Image();

	void create(int32_t rsrcId, const Point& pos = Point::ZERO);	//we can set the default parameter only in the header file
	void destroy();
};

#endif /* UTILS_INCLUDE_UTILS_DRAWINGS_IMAGE_H_ */
