#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"



int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }

  if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) 
  {
    int x = atoi (configuration.arg1);
    int y = atoi (configuration.arg2);
    pixelRGB* pixel = get_pixel(configuration.image.data, configuration.image.width, x, y);
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
  }

  if (strncmp( configuration.command, "first-pixel",11)== 0){
    first-pixel(configuration.input-file);
  }
  /*
   * TO COMPLETE
   */
  
  return 0;
}
