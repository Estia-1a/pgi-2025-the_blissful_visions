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
void max_pixel(char *source_path){
    unsigned char *data;
    int x,y,height,width,channel_count,prof,sum, R,G,B, max_rgb_sum,maximum0,maximum1;

    max_rgb_sum =0 ;
    maximum0 = 0;
    maximum1= 0 ;
    prof= read_image_data(source_path, &data, &width, &height, &channel_count);

    if (prof!=0){

            for (y= 0; y< height; y++) {
                for (x= 0; x < width; x++) {
                    R = (y*width+x)*channel_count;
                    G = (y*width+x)*channel_count + 1;
                    B = (y*width+x)*channel_count + 2;

                    sum = data[R] + data[G] + data[B];
                    if (sum > max_rgb_sum) {
                        max_rgb_sum = sum;
                        maximum0 = x;
                        maximum1= y;
                    }
                }
            }

            R = (maximum1*width+maximum0)*channel_count;
            G = (maximum1*width+maximum0)*channel_count + 1;
            B = (maximum1*width+maximum0)*channel_count + 2;

            printf("max_pixel (%d, %d): %d, %d, %d\n", maximum0,maximum1, data[R], data[G], data[B]);
    }
    else{
        printf("An error occured");
    }
}

void min_pixel(char *source_path){
    unsigned char *data;
    int x,y,height,width,channel_count,prof1,sum, R,G,B, min_rgb_sum,minimum0,minimum1;

    min_rgb_sum =256 ;
    minimum0 = 0;
    minimum1= 0 ;
    prof1= read_image_data(source_path, &data, &width, &height, &channel_count);

    if (prof1 !=0 && channel_count==3){

            for (y= 0; y< height; y++) {
                for (x= 0; x < width; x++) {
                    R = (y*width+x)*channel_count;
                    G = (y*width+x)*channel_count + 1;
                    B = (y*width+x)*channel_count + 2;

                    sum = data[R] + data[G] + data[B];
                    if (sum <min_rgb_sum) {
                        min_rgb_sum = sum;
                        minimum0=x;
                        minimum1=y;
                    }
                }
            }

            R = (minimum1*width+minimum0)*channel_count;
            G = (minimum1*width+minimum0)*channel_count + 1;
            B = (minimum1*width+minimum0)*channel_count + 2;

            printf("min_pixel (%d, %d): %d, %d, %d\n", minimum0, minimum1, data[R], data[G], data[B]);
    }
    else{
        printf("An error occured");
    }
}



void flip_image(unsigned char *src, unsigned char *dst, int width, int height, int channels) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int src_idx = (y * width + x) * channels;
            int dst_idx = ((height - 1 - y) * width + (width - 1 - x)) * channels;

            for (int c = 0; c < channels; ++c) {
                dst[dst_idx + c] = src[src_idx + c];
            }
        }
    }
}

void mirror_total(const char *input_filename) {
    unsigned char *data = NULL;
    int width, height, channels;

    if (!read_image_data(input_filename, &data, &width, &height, &channels)) {
        fprintf(stderr, "Failed to read image.\n");
        return;
    }

    unsigned char *result = malloc(width * height * channels);
    if (!result) {
        fprintf(stderr, "Memory allocation error.\n");
        free(data);
        return;
    }

    flip_image(data, result, width, height, channels);
    write_image_data("image_out.bmp", result, width, height);

    printf("Image enregistrée sous : image_out.bmp\n");

    
    system("start image_out.bmp");

    free(data);
    free(result);
}
