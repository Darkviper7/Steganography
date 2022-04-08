#include <stdio.h>
#include "stego.h"

int get_msg_length(FILE *);
void decode_message(int, FILE *);

int main(int argc, char **argv) {
  FILE *fp;

  if((fp = fopen(argv[1], "rb")) == NULL) {
    printf("\nError: Please provide a file to scan.\n\n");
    return 1;
  }

  if(read_ppm_type(fp)) {
    skip_comments(fp);
    get_width(fp);
    get_height(fp);
    if(read_color_depth(fp)) { 
      int length = get_msg_length(fp);
     
      printf("\nHoly secret message batman! We cracked the code: \n");
      decode_message(length, fp);

      fclose(fp);
     
    } else {
      printf("Error: Invalid Color Depth.");
      return 1;
    }
  } else {
    printf("Error: Wrong PPM File Format. Terminating.");
    return 1;
  }

  return 0;
}

int get_msg_length(FILE *fp) {
  char t = 0;
  int length = 0;
  int i;

  for(i=0; i < 8; i++) {
    t = fgetc(fp);
    if(i > 0) length <<= 1;
    length |= (t & 1);
  }

    return length;
}

void decode_message(int length, FILE *fp) {
  int readTo = length * 8, numRead = 0, i;
  unsigned char charBuffer = 0;
  char temp;
  char secret_message[length + 1];
  int idx = 0;
  
  while(numRead <= readTo) {
    temp = fgetc(fp); 
    if(numRead % 8 == 0) {
      secret_message[idx] = charBuffer;
      idx++;
      charBuffer = 0;
    } else {
      charBuffer <<= 1;
    }
    charBuffer |= (temp & 1);
    numRead++;
  }
  
  //0th char is junk, printing from 1
  for(i = 1; i < idx; i++) {
    printf("%c", secret_message[i]);
  }

  printf("\n\n");

  return;
}
