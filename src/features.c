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
    int width, height, channel_count, positionR, positionG, positionB;
    unsigned char val_R, val_G, val_B;

    read_image_data(filename, &data, &width, &height, &channel_count);

    positionR = 3 * width;
    positionG = 3 * width +1;
    positionB = 3 * width +2;

    val_R = data[positionR];
    val_G = data[positionG];
    val_B = data[positionB];

    printf("second_line : %d, %d, %d", val_R, val_G, val_B);
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

void min_component(char *source_path, char *component) {
    unsigned char *data;
    int width, height, channel_count;
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    
    int max_val_RGB = 255; 
    int min_x = 0, min_y = 0;
    
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            
            pixelRGB *min_RGB = get_pixel(data, width, height, x, y);
            
            int val_RGB;
            
            
            if (strcmp(component, "R") == 0) {
                val_RGB = min_RGB->R;  
            }
            else if (strcmp(component, "G") == 0) {
                val_RGB = min_RGB ->G;
            }
            else if (strcmp(component, "B") == 0) {
                val_RGB = min_RGB ->B;
            }
            else {
                printf("Erreur: composante invalide\n");
                free(data);
                return;
            }
            
            
            if (val_RGB < max_val_RGB) {
                max_val_RGB = val_RGB;
                min_x = x;
                min_y = y;
            }
        }
    }
    
    
    printf("min_component %s (%d, %d): %d\n", component, min_x, min_y, max_val_RGB);
    
    free(data);
}

void max_component(char *source_path, char *component) {
    unsigned char *data;
    int width, height, channel_count;
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    
    int min_val_RGB = -1; 
    int max_x = 0, max_y = 0;
    
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            
            pixelRGB *max_RGB = get_pixel(data, width, height, x, y);
            
            int val_RGB;
            
            
            if (strcmp(component, "R") == 0) {
                val_RGB = max_RGB->R;  
            }
            else if (strcmp(component, "G") == 0) {
                val_RGB = max_RGB ->G;
            }
            else if (strcmp(component, "B") == 0) {
                val_RGB = max_RGB ->B;
            }
            else {
                printf("Erreur: composante invalide\n");
                free(data);
                return;
            }
            
            
            if (val_RGB > min_val_RGB) {
                min_val_RGB = val_RGB;
                max_x = x;
                max_y = y;
            }
        }
    }
    
    
    printf("max_component %s (%d, %d): %d\n", component, max_x, max_y, min_val_RGB);
    
    free(data);
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

void retourner_lignes_verticalement(unsigned char *entree, unsigned char *sortie, int largeur, int hauteur, int canaux) {
    int taille_ligne = largeur * canaux;
    for (int ligne = 0; ligne < hauteur; ++ligne) {
        unsigned char *src = entree + ligne * taille_ligne;
        unsigned char *dest = sortie + (hauteur - ligne - 1) * taille_ligne;
        memcpy(dest, src, taille_ligne);  
    }
}

void symetrie_verticale(const char *chemin_image) {
    int l, h, c;
    unsigned char *donnees = NULL;
    unsigned char *symetrie = NULL;

    if (!read_image_data(chemin_image, &donnees, &l, &h, &c)) {
        fprintf(stderr, "Erreur : lecture de l'image impossible (%s)\n", chemin_image);
        return;
    }

    int taille_totale = l * h * c;
    symetrie = malloc(taille_totale);
    if (!symetrie) {
        fprintf(stderr, "Erreur : mémoire insuffisante.\n");
        free(donnees);
        return;
    }

    retourner_lignes_verticalement(donnees, symetrie, l, h, c);

    write_image_data("image_out.bmp", symetrie, l, h);

    free(donnees);
    free(symetrie);
}



void inverser_colonnes(unsigned char *ligne_src, unsigned char *ligne_dest, int largeur, int canaux) {
    for (int col = 0; col < largeur; ++col) {
        for (int c = 0; c < canaux; ++c) {
            int source_idx = col * canaux + c;
            int dest_idx = (largeur - 1 - col) * canaux + c;
            ligne_dest[dest_idx] = ligne_src[source_idx];
        }
    }
}

void retourner_colonnes_horizontalement(unsigned char *entree, unsigned char *sortie, int largeur, int hauteur, int canaux) {
    int ligne_taille = largeur * canaux;

    for (int ligne = 0; ligne < hauteur; ++ligne) {
        unsigned char *src = entree + ligne * ligne_taille;
        unsigned char *dst = sortie + ligne * ligne_taille;
        inverser_colonnes(src, dst, largeur, canaux);
    }
}

void symetrie_horizontale(const char *chemin_image) {
    unsigned char *donnees = NULL;
    unsigned char *resultat = NULL;
    int l, h, c;

    if (!read_image_data(chemin_image, &donnees, &l, &h, &c)) {
        fprintf(stderr, "Erreur de lecture : %s\n", chemin_image);
        return;
    }

    int taille = l * h * c;
    resultat = malloc(taille);
    if (!resultat) {
        fprintf(stderr, "Erreur mémoire.\n");
        free(donnees);
        return;
    }

    retourner_colonnes_horizontalement(donnees, resultat, l, h, c);
    write_image_data("image_out.bmp", resultat, l, h);

    free(donnees);
    free(resultat);
}





static unsigned char niveau_gris(unsigned char r, unsigned char g, unsigned char b) {
    
    return (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
}

static void remplir_image_grise(unsigned char *source, unsigned char *grise, int largeur, int hauteur, int canaux) {
    int total_pixels = largeur * hauteur;
    for (int p = 0; p < total_pixels; ++p) {
        int idx = p * canaux;
        unsigned char gris = niveau_gris(source[idx], source[idx + 1], source[idx + 2]);

        for (int c = 0; c < 3; ++c) {
            grise[idx + c] = gris;
        }
    }
}

void conversion_en_niveaux_de_gris(const char *chemin_image) {
    unsigned char *originale = NULL;
    int w, h, ch;

    if (!read_image_data(chemin_image, &originale, &w, &h, &ch)) {
        fprintf(stderr, "Échec lecture image : %s\n", chemin_image);
        return;
    }

    unsigned char *grayscale = malloc(w * h * ch);
    if (!grayscale) {
        fprintf(stderr, "Erreur mémoire\n");
        free(originale);
        return;
    }

    remplir_image_grise(originale, grayscale, w, h, ch);
    write_image_data("image_out.bmp", grayscale, w, h);

    free(originale);
    free(grayscale);
}


static unsigned char composante_luminance(unsigned char rouge, unsigned char vert, unsigned char bleu) {
    
    return (unsigned char)(0.21 * rouge + 0.72 * vert + 0.07 * bleu);
}

static void generer_image_luminance(unsigned char *entree, unsigned char *grise, int largeur, int hauteur, int canaux) {
    int total = largeur * hauteur;
    for (int p = 0; p < total; ++p) {
        int i = p * canaux;
        unsigned char l = composante_luminance(entree[i], entree[i + 1], entree[i + 2]);
        for (int c = 0; c < 3; ++c) {
            grise[i + c] = l;
        }
    }
}

void conversion_gris_luminance(const char *chemin) {
    unsigned char *originale = NULL;
    int w, h, ch;

    if (!read_image_data(chemin, &originale, &w, &h, &ch)) {
        fprintf(stderr, "Erreur lecture fichier : %s\n", chemin);
        return;
    }

    unsigned char *lumiere = malloc(w * h * ch);
    if (!lumiere) {
        fprintf(stderr, "Erreur allocation mémoire.\n");
        free(originale);
        return;
    }

    generer_image_luminance(originale, lumiere, w, h, ch);
    write_image_data("image_out.bmp", lumiere, w, h);

    free(originale);
    free(lumiere);
}



static unsigned char valeur_desaturee(unsigned char r, unsigned char g, unsigned char b) {
    unsigned char mini = r;
    if (g < mini) mini = g;
    if (b < mini) mini = b;

    unsigned char maxi = r;
    if (g > maxi) maxi = g;
    if (b > maxi) maxi = b;

    return (mini + maxi) / 2;
}

static void appliquer_desaturation(unsigned char *src, unsigned char *dst, int largeur, int hauteur, int canaux) {
    for (int ligne = 0; ligne < hauteur; ++ligne) {
        for (int col = 0; col < largeur; ++col) {
            int idx = (ligne * largeur + col) * canaux;
            unsigned char r = src[idx];
            unsigned char g = src[idx + 1];
            unsigned char b = src[idx + 2];

            unsigned char gris = valeur_desaturee(r, g, b);
            for (int c = 0; c < 3; ++c) {
                dst[idx + c] = gris;
            }
        }
    }
}

void conversion_desaturee(const char *chemin) {
    int w, h, ch;
    unsigned char *img = NULL;

    if (!read_image_data(chemin, &img, &w, &h, &ch)) {
        fprintf(stderr, "Erreur lecture image : %s\n", chemin);
        return;
    }

    unsigned char *resultat = malloc(w * h * ch);
    if (!resultat) {
        fprintf(stderr, "Erreur mémoire\n");
        free(img);
        return;
    }

    appliquer_desaturation(img, resultat, w, h, ch);
    write_image_data("image_out.bmp", resultat, w, h);

    free(img);
    free(resultat);
}




static void inverser_pixels(unsigned char *src, unsigned char *dst, int largeur, int hauteur, int canaux) {
    int total_pixels = largeur * hauteur;

    for (int i = 0; i < total_pixels; ++i) {
        int index = i * canaux;

        dst[index]     = 255 - src[index];     
        dst[index + 1] = 255 - src[index + 1]; 
        dst[index + 2] = 255 - src[index + 2]; 

       
        if (canaux == 4) {
            dst[index + 3] = src[index + 3];
        }
    }
}

void inversion_couleurs(const char *chemin_image) {
    unsigned char *originale = NULL;
    int w, h, ch;

    if (!read_image_data(chemin_image, &originale, &w, &h, &ch)) {
        fprintf(stderr, "Erreur lecture image : %s\n", chemin_image);
        return;
    }

    unsigned char *inverse = malloc(w * h * ch);
    if (!inverse) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        free(originale);
        return;
    }

    inverser_pixels(originale, inverse, w, h, ch);
    write_image_data("image_out.bmp", inverse, w, h);

    free(originale);
    free(inverse);
}




static void rotation_90_droite(unsigned char *src, unsigned char *dst, int largeur, int hauteur, int canaux) {
    for (int ligne = 0; ligne < hauteur; ++ligne) {
        for (int col = 0; col < largeur; ++col) {
            int source_idx = (ligne * largeur + col) * canaux;
            int cible_idx = (col * hauteur + (hauteur - 1 - ligne)) * canaux;

            for (int c = 0; c < canaux; ++c) {
                dst[cible_idx + c] = src[source_idx + c];
            }
        }
    }
}

void rotation_horaire(const char *chemin) {
    unsigned char *origine = NULL;
    int l, h, ch;

    if (!read_image_data(chemin, &origine, &l, &h, &ch)) {
        fprintf(stderr, "Impossible de lire l'image : %s\n", chemin);
        return;
    }

    
    unsigned char *tourne = malloc(l * h * ch);
    if (!tourne) {
        fprintf(stderr, "Erreur mémoire\n");
        free(origine);
        return;
    }

    rotation_90_droite(origine, tourne, l, h, ch);
    write_image_data("image_out.bmp", tourne, h, l); 

    free(origine);
    free(tourne);
}






static void rotation_90_gauche(unsigned char *source, unsigned char *destination, int largeur, int hauteur, int canaux) {
    for (int ligne = 0; ligne < hauteur; ++ligne) {
        for (int colonne = 0; colonne < largeur; ++colonne) {
            int idx_src = (ligne * largeur + colonne) * canaux;
            int idx_dst = ((largeur - 1 - colonne) * hauteur + ligne) * canaux;

            for (int c = 0; c < canaux; ++c) {
                destination[idx_dst + c] = source[idx_src + c];
            }
        }
    }
}

void rotation_anti_horaire(const char *chemin_image) {
    unsigned char *original = NULL;
    int w, h, ch;

    if (!read_image_data(chemin_image, &original, &w, &h, &ch)) {
        fprintf(stderr, "Erreur de lecture : %s\n", chemin_image);
        return;
    }

    unsigned char *sortie = malloc(w * h * ch);
    if (!sortie) {
        fprintf(stderr, "Échec mémoire\n");
        free(original);
        return;
    }

    rotation_90_gauche(original, sortie, w, h, ch);
    write_image_data("image_out.bmp", sortie, h, w); 

    free(original);
    free(sortie);
}

void scale_crop(char *source_path, int center_x, int center_y, int crop_width, int crop_height) {
    unsigned char *data, *nouveau_data;
    int width, height, channel_count;
    int x,y, c;
    int src_width, src_height;
    int start_x, start_y, end_x, end_y;
    
    if (read_image_data(source_path, &data, &width, &height, &channel_count)!= 1) {
        fprintf(stderr, "Error: Unable to read image data from %s\n", source_path);
        return;
    }

    start_x = center_x-crop_width / 2; 
    start_y = center_y-crop_height / 2;
    end_x = start_x + crop_width;
    end_y = start_y + crop_height; 
       
    if (start_x < 0){
        start_x = 0 ;
    }
    if (start_y < 0){
        start_y = 0; 
    }

    if(end_x > width){
        end_x = width;
    }
    
    if(end_y > height){
        end_y = height;
    }
    src_width = end_x - start_x;
    src_height = end_y - start_y; 
        
    nouveau_data = (unsigned char*)malloc(src_width * src_height*channel_count ); 
    
    
    for (y=0;y <src_height; y++ ){
        for(x=0; x<src_width; x++){
         for (c = 0; c < channel_count; c++){

                nouveau_data [(y * src_width + x) * channel_count + c] = data [((start_y + y) * width + (start_x + x)) * channel_count +c];
            }
        }
    }

char output_filename [100];
        snprintf(output_filename, sizeof(output_filename), "image_out.bmp");

if (write_image_data ( output_filename, nouveau_data, src_width, src_height) != 1){

     fprintf(stderr, "Error: Unable to write image data to %s\n", output_filename);
    } else {

    printf("scale_crop %d %d %d %d\n", center_x, center_y, crop_width, crop_height);

    }       

    free (data);
    free (nouveau_data);

}

void scale_nearest(char *filename, float scale_factor) {
    unsigned char *data_entree;
    int ancien_w, ancien_h, channel_count;

    if (read_image_data(filename, &data_entree, &ancien_w, &ancien_h, &channel_count) != 1) {
        fprintf(stderr, "Error: Unable to read image data from %s\n", filename);
        return;
    }

    int nouvelle_w = (int)round(ancien_w * scale_factor);
    int nouvelle_h = (int)round(ancien_h * scale_factor);

    unsigned char *nouvelle_data = (unsigned char *)malloc(nouvelle_w * nouvelle_h * channel_count);
    if (!nouvelle_data) {
        fprintf(stderr, "Error: Unable to allocate memory for new image data\n");
        free(data_entree);
        return;
    }

    
    for (int y = 0; y < nouvelle_h; y++) {
        for (int x = 0; x < nouvelle_w; x++) {
            int original_x = (int)(x / scale_factor);
            int original_y = (int)(y / scale_factor);

            original_x = (original_x < 0) ? 0 : (original_x >= ancien_w) ? ancien_w - 1 : original_x;
            original_y = (original_y < 0) ? 0 : (original_y >= ancien_h) ? ancien_h - 1 : original_y;

            for (int c = 0; c < channel_count; ++c) {
                nouvelle_data[(y * nouvelle_w + x) * channel_count + c] = data_entree[(original_y * ancien_w + original_x) * channel_count + c];
            }
        }
    }


    if (write_image_data("image_out.bmp", nouvelle_data, nouvelle_w, nouvelle_h) != 1) {
        fprintf(stderr, "Error: Unable to write image data to image_out.bmp\n");
    }

    printf("scale_nearest %.1f\n", scale_factor);

    free(data_entree);
    free(nouvelle_data);


}
