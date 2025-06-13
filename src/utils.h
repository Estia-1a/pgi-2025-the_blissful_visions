#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Here, you have to define pixelRGB struct and its functions:
 * - pixel* getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
 * - void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);
 *
*/


typedef struct pixelRGB {

  unsigned char R ; 
  unsigned char G ; 
  unsigned char B ; 
} pixelRGB ;


pixelRGB* get_pixel( const unsigned char* data, unsigned int width, unsigned int height, unsigned int n, unsigned int x, unsigned int y );
#endif
