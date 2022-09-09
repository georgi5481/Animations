//Coresponding Header
#include "utils/drawings/DrawParams.h"

//C system includes


//C++ system includes


//3rd-party includes


//Own includes



void DrawParams::reset(){	//setting the variables to their original state

	 pos = Point::UNDEFINED;

	 width = 0;
	 height = 0;

	 opacity = FULL_OPACITY;


	 rsrcId = INVALID_RSRC_ID;


	 widgetType = WidgetType::UNKNOWN;
}
