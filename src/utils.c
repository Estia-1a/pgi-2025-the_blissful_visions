#include <estia-image.h>

#include "utils.h"

pixelRGB* get_pixel(unsigned char*data, const unsigned int width, const unsigned int x, =const unsigned int y)
{
    return (pixelRGB*) &data [(y* widht + x)*3]
}
if (data == NULL || x >=width || y >= height){
    return NULL;
}

unsigned int index = (y * width + x)* n;
return (pixelRGB) &data[index];
/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

