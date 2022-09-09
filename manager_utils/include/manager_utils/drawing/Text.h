#ifndef UTILS_INCLUDE_UTILS_DRAWINGS_TEXT_H_
#define UTILS_INCLUDE_UTILS_DRAWINGS_TEXT_H_

//C system includes

//C++ system includes
#include<string>
//3rd-party includes

//Own includes
#include "manager_utils/drawing/Widget.h"
#include "utils/drawings/Color.h"
//Forward Declaration

class Text : public Widget{	//inheriting Widget cuz we are gonna need the setters, getters and booleans
public:
	~Text();

	void create(const std::string& text, int32_t fontId, const Color& color,
					const Point& pos = Point::ZERO);
	void destroy();
	void setText(const std::string& text);
	void setColor(const Color& color);
	std::string getTextContent() const;
private:
	std::string _textContent;
	Color _color = Colors::BLACK;
	int32_t _fontId = INVALID_RSRC_ID;

};

#endif /* UTILS_INCLUDE_UTILS_DRAWINGS_TEXT_H_ */
