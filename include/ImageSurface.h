#pragma once

#include "SDL_Local.h"

class ImageSurface
{
private:

	// Deallocates whole data
	void free();

protected:

	/**
	 * Pointer to SDL_Surface structure containing pixel data 
	 * and every needed informations to process an image
	 */
	SDL_Surface *surface;

	/// SDL Utility functions for private purposes 
	/// (they do NOT modify the object directly - so they are const)
	/// !!! Thats what you love the most !!!
	//         V     O    T     E
	//  A) Leave it here
	//  B) Move to "namespace SDL_Utils {}"
	//
	//  Marcin [   ]    Marek  [   ]
	//  Konrad [ A ]    Damian [   ]

	/**
	 * Creates an empty SDL_Surface (RGB) with paramters
	 * @param width of the surface
	 * @param height of the surface
	 * @param color depth of the surface (number of bits each pixel takes in memory)
	 * @return pointer to newly allocated SDL_Surface structure
	 * @throws RuntimError when allocation fails
	 */
	SDL_Surface *create(int, int, int) const;

	/**
	 * Creates a copy of existing SDL_Surface strucutre
	 * @return pointer to newly allocated SDL_Surface structure
	 * @throws RuntimError when allocation fails
	 */
	SDL_Surface *copy(const SDL_Surface *) const;

	/**
	 * Gets (8|16|24|32) bits from pixel data
	 * @param pixel pointer to adress where chosen pixel begins in pixel data
	 * @param bpp size of pixel in number of bytes
	 * @return fully qualifed pixel data (32 bit)
	 */
	uint32_t getPixel(uint8_t*, uint8_t) const;

	/**
	 * Gets pixel data from SDL_Surface
	 * @param pointer to structure with pixel data
	 * @param x x-axis
	 * @param y y-axis cordinate of chosen pixel
	 * @param bool turns on debuging when true
	 * @return full pixel data (32 bit)
	 */
	uint32_t getPixel(const SDL_Surface*, unsigned int, unsigned int, bool = false) const;

	/**
	 * Gets pixel data from SDL_Surface
	 * @param pointer to structure with pixel data
	 * @param x x-axis
	 * @param y y-axis cordinate of chosen pixel
	 * @param bool turns on debuging when true
	 * @return pixel data in SDL_Color structure
	 */
	SDL_Color getPixelColor(const SDL_Surface*, unsigned int, unsigned int, bool = false) const;

	/**
	 * Sets pixel's data to SDL_Surface
	 * @param pointer to structure with pixel data
	 * @param x x-axis
	 * @param y y-axis cordinate of chosen pixel
	 * @param pixel data (32 bits)
	 * @param bool turns on debuging when true
	 */
	void setPixel(SDL_Surface *, unsigned int, unsigned int, uint32_t, bool = false) const;

	/**
	 * Sets pixel's color's data to SDL_Surface
	 * @param pointer to structure with pixel data
	 * @param x x-axis
	 * @param y y-axis cordinate of chosen pixel
	 * @param red component color value (8 bit)
	 * @param green component color value (8 bit)
	 * @param blue component color value (8 bit)
	 * @param bool turns on debuging when true
	 */
	void setPixel(SDL_Surface *, unsigned int, unsigned int, uint8_t, uint8_t, uint8_t, bool = false) const;


	/**
	 * Sets pixel's color's data to SDL_Surface
	 * @param pointer to structure with pixel data
	 * @param x x-axis
	 * @param y y-axis cordinate of chosen pixel
	 * @param SDL_Color structure
	 * @param bool turns on debuging when true
	 */
	void setPixel(SDL_Surface *, unsigned int, unsigned int, const SDL_Color &, bool = false) const;

public:

	// Default constructor
	ImageSurface();

	// Attaching surface to this image
	ImageSurface(SDL_Surface *);

	// Copying surface
	ImageSurface(const SDL_Surface *);

	// Copy constructor
	ImageSurface(const ImageSurface &);

	// Move constructor
	ImageSurface(ImageSurface &&);

	// Copy assigment operator overload
	ImageSurface& operator=(const ImageSurface &);

	// Move assigment operator overload
	ImageSurface& operator=(ImageSurface &&);

	// Destructor
	~ImageSurface();

	/**
	 * @return pointer to constant SDL_Structure which
	 * allows to access data, but won't let to modify it
	 */
	const SDL_Surface* img() const;

	/**
	 * @return number of pixels in horizontal line
	 */
	unsigned int width() const;

	/** 
	 * @return number of pixels in vertical line
	 */
	unsigned int height() const;
	
	/**
	 * @return number of bytes each pixel takes in memory
	 */
	unsigned int bpp() const;

	/**
	 * @return color depth of the image
	 */
	unsigned int depth() const;

	/**
	 * @return number of bytes needed to store pixel data in memory
	 */
	size_t size() const;

	/**
	 * Indicates wheter SDL_Surface structure is initialized or not
	 * @return bool true if so | false otherwise
	 */
	bool empty() const;
};
