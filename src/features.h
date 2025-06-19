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

#endif
