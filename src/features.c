#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"


void first_pixel (char *source-path){
unsigned char *data = NULL;
int width, height, channel-count;

int result = read-image-data(source-path, &data, &width, &height,
&channel-count);

if (result != 0 || data == NULL){
prinf("Erreur : Impossible de lire les données de l'image.\n");
return;
}

int R = data [0];
int G = data [1];
int B = data [2];

printf("first-ouxel: %d, %d, %d\n", R, G, B);

free(data);

}

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("yep!");
}