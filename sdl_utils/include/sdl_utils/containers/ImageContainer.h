#ifndef SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<unordered_map>
//3rd-party includes

//Own includes
#include "utils/drawings/Rectangle.h"
#include "sdl_utils/config/ImageContainerCfg.h"

using Frames = std::vector<Rectangle>;	//places Frames instead of std::vector<Rectangle>

//Forward Declaration

struct SDL_Texture;

class ImageContainer {
public:

	SDL_Texture* getImageTexture(int32_t rsrcId) const;	//will basically search in the map below ( _textures )

	const Frames& getImageFrame(int32_t rsrcId) const;		//this one will search in the other map below for the pixel frame ( _textureFrames )


protected:	//we can't create objects if not inherited and used by the other class
	int32_t init(const ImageContainerCfg& cfg);
	int32_t deinit();

private:

	int32_t loadSingleResource(const ImageCfg& resCfg, int32_t rsrcId);

	std::unordered_map<int32_t, SDL_Texture*> _textures;	//in the first vector we are saving the ID and the texture

	std::unordered_map<int32_t, Frames> _textureFrames;		//in the second vector we are saving the ID and the rectangle dimensions


};

#endif /* SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_ */
