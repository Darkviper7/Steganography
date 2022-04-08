#ifndef STEGO_H_FILE

#include <stdio.h>
#define STEGO_H_FILE

void die(char* reason);
int read_ppm_type(FILE *);

void skip_comments(FILE *);
int get_width(FILE *);
int get_height(FILE *);
int read_color_depth(FILE *);

#endif