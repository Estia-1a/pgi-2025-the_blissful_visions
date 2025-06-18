#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "features.h"
#include "utils.h"
#include  <math.h>
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
void print_pixel( char *filename, int x, int y){
    unsigned char *data;
    int width, height, channel_count;
    pixelRGB print_pixel;
   
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    print_pixel.R = data[channel_count*(y*width+x)];
    print_pixel.G = data[channel_count*(y*width+x)+1];
    print_pixel.B = data[channel_count*(y*width+x)+2];
 
    printf("print_pixel (%d, %d) : %d, %d, %d", x, y, print_pixel.R, print_pixel.G, print_pixel.B);
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
/*void min_component ( char *source_path, char *component){

    unsigned char *data;
    int width, height, channel_count; 
    
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    int x, y;
    
    pixelRGB min_RGB[x][y];
   
    int R=255, G=255, B=255; 
    int minx=0, miny=0;
   
    for(y=0; y<height; y++){
        for(x=0; x<width; x++){
            
            min_RGB = get_pixel(data, width, height, channel_count, x, y);
        
            if(((strcmp(R, data[x][y]))==0) && (component == 'R') ){
                R = min_RGB->R;
                minx=x;
                miny=y;
            }
            if(((strcmp(G, data[x][y]))==0) && (component == 'G')){
                G= min_RGB->G;
                minx=x;
                miny=y;
            }
            if(((strcmp(B, data[x][y]))==0) && (component == 'B')){
                B=min_RGB->B;
                minx=x;
                miny=y;
            }
        }
    }
    int minimum=fmin(fmin(R,G),B);

    printf("min_component %s (%d, %d): %d ", component, minx, miny, minimum);
    free(data);
}*/

void min_component(char *source_path, char *component) {
    unsigned char *data;
    int width, height, channel_count;
    
    // Lire les données de l'image
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    // Variables pour stocker le minimum trouvé
    int min_value = 255;  // Valeur max possible
    int min_x = 0, min_y = 0;
    
    // Parcourir tous les pixels
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Obtenir le pixel actuel (get_pixel retourne un pointeur)
            pixelRGB *current_pixel = get_pixel(data, width, height, x, y);
            
            int current_value;
            
            // Extraire la bonne composante selon le paramètre
            if (strcmp(component, "R") == 0) {
                current_value = current_pixel->R;  // Utilisation de -> car c'est un pointeur
            }
            else if (strcmp(component, "G") == 0) {
                current_value = current_pixel->G;
            }
            else if (strcmp(component, "B") == 0) {
                current_value = current_pixel->B;
            }
            else {
                printf("Erreur: composante invalide\n");
                free(data);
                return;
            }
            
            // Comparer avec le minimum actuel
            if (current_value < min_value) {
                min_value = current_value;
                min_x = x;
                min_y = y;
            }
        }
    }
    
    // Afficher le résultat
    printf("min_component %s (%d, %d): %d\n", component, min_x, min_y, min_value);
    
    free(data);
}