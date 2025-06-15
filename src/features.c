#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("yep!");
}

void dimensions(char *filename) {
    unsigned char *data; 
    int width, height, channel_count;
   

    read_image_data(filename, &data, &width, &height, &channel_count);

    printf ("dimension : %d, %d", width, height);

}

void first_pixel (char *filename){
    unsigned char *data; 
    int width, height, channel_count;

    pixelRGB first_pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    first_pixel.R = data[0];
    first_pixel.G = data[1];
    first_pixel.B = data[2];

    printf("first_pixel : %d, %d, %d", first_pixel.R, first_pixel.G, first_pixel.B);
}   


void tenth_pixel (char *filename){
    unsigned char *data; 
    int width, height, channel_count;

    pixelRGB tenth_pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    tenth_pixel.R = data[27];
    tenth_pixel.G = data[28];
    tenth_pixel.B = data[29];

    printf("tenth_pixel : %d, %d, %d", tenth_pixel.R, tenth_pixel.G, tenth_pixel.B);
}   

void second_line (char *filename){
    unsigned char *data; 
    int width, height, channel_count;

    pixelRGB second_line;

    read_image_data(filename, &data, &width, &height, &channel_count);

    second_line.R = data[4464];
    second_line.G = data[4465];
    second_line.B = data[4466];

    printf("second_line : %d, %d, %d", second_line.R, second_line.G, second_line.B);
}

void color_red(char *source_path){
    int vision ;
    unsigned char *data;
    int width ,height , channel_count ;
    int a,i,j ;
    vision= read_image_data(source_path,&data, &width,&height,&channel_count);
    if(vision !=0){

       for (j = 0; j < height;j++) {
        for (i = 0; i< width; i++) {
            a = (j * width + i) * channel_count;
            data[a + 1] = 0; 
            data[a + 2] = 0;  
        }
       }
       write_image_data("image_out.bmp",data, width,height);
       free(data) ;
    }
}
void color_green(char *source_path){
    int post ;
    unsigned char *data;
    int width ,height , channel_count ;
    int a,i,j ;
    post= read_image_data(source_path,&data, &width,&height,&channel_count);
    if(post !=0){

       for (j = 0; j < height;j++) {
        for (i = 0; i< width; i++) {
            a = (j * width + i) * channel_count;
            data[a] = 0; 
            data[a + 2] = 0;  
        }
       }
       write_image_data("image_out.bmp",data, width,height);
       free(data) ;
    }
}
void color_blue(char *source_path){
    int post1;
    unsigned char *data;
    int width ,height , channel_count ;
    int a,i,j ;
    post1= read_image_data(source_path,&data, &width,&height,&channel_count);
    if(post1 !=0){

       for (j = 0; j < height;j++) {
        for (i = 0; i< width; i++) {
            a = (j * width + i) * channel_count;
            data[a] = 0; 
            data[a+1] = 0;  
        }
       }
       write_image_data("image_out.bmp",data, width,height);
       free(data) ;
    }
}