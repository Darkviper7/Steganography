#include <stdio.h> 
#include <stdlib.h>

#include "stego.h"

//kill the program
void die(char* reason){
  fprintf(stderr, "ERROR: %s\n", reason);
  exit(1);
}

//Check if the file is in P6 format
int read_ppm_type(FILE *fp) {
  char t = fgetc(fp); 
  if(t == 'P' && fgetc(fp) == '6') {
    fgetc(fp);
    return 1;
  }
  return 0;
}

void skip_comments(FILE *fp) {
  char t;
  while((t = fgetc(fp)) == '#') {
    while(fgetc(fp) != '\n') {}
  }
  ungetc(t, fp); 
  return;
}

//Returns the width of the image
int get_width(FILE *fp) {
  int width;
  fscanf(fp, "%d", &width);
  return width;
}

//Returns the height of the image
int get_height(FILE *fp) {
  int height;
  fscanf(fp, "%d", &height);
  return height;
}
//read the color depth
int read_color_depth(FILE *fp) {
  int cd;
  fscanf(fp, "%d", &cd);
  if(cd == 255) {
    fgetc(fp);   
    return 1;
  }
  return 0;
}
