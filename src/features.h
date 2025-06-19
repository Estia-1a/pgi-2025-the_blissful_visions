#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimensions(char *filename);

void first_pixel (char *source_path);

void tenth_pixel (char *source_path);

void second_line(char *source_path);

void print_pixel(char *source_path, int x, int y);

void color_red(char *source_path); 

void color_green(char *source_path);

void color_blue(char *source_path);

void max_pixel(char *source_path);

void min_pixel(char *source_path);

void min_component(char *source_path, char *component); 

void max_component(char *source_path, char *component);

void mirror_total(const char *input_filename);

void symetrie_verticale(const char *chemin_image);

void symetrie_horizontale(const char *chemin_image);

void conversion_en_niveaux_de_gris(const char *chemin_image);

void conversion_gris_luminance(const char *chemin);

void conversion_desaturee(const char *chemin);

void inversion_couleurs(const char *chemin_image);

void rotation_horaire(const char *chemin);

void rotation_anti_horaire(const char *chemin_image);

void scale_crop(char *source_path, int center_x, int center_y, int crop_width, int crop_height);


#endif
