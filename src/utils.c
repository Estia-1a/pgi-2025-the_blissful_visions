#include <estia-image.h>

#include "utils.h"
#include <stddef.h>
/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

 pixelRGB *getpixel (const unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y){
    
    if (data == NULL || x>= width || y >= height){
        return NULL; 
    }
    else{
    return ((pixelRGB*)&data[y * 3 * width + x * 3]);
    }
 }
  

