#include <stdio.h>
#include "a4.h"
#include <stdlib.h>



// code implemented and changed from https://stackoverflow.com/questions/2693631/read-ppm-file-and-store-it-in-an-array-coded-with-c

PPM_IMAGE *read_ppm(const char *file_name){

// We want to read the image file and return a pointer to the PPM_IMAGE structure
//this structure contains the pixels of the image, width, height, and max_color

char buffer[3];
int duff;

PPM_IMAGE *image; //pointer to the image


FILE *filepointer;  //pointer to the file

filepointer = fopen(file_name, "r");  //open the file

image = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));  //allocate memory for the structure

// code to skip line : https://stackoverflow.com/questions/16107976/skip-a-line-while-reading-a-file-in-c
fgets(buffer, 3, filepointer); //using this to skip the first line of input

fscanf(filepointer, "%d %d", &image->width, &image->height); //store the width and the height
fscanf(filepointer, "%d", &image->max_color); //store the max color

image->data = (PIXEL*)malloc(image->width * image->height * sizeof(PIXEL)); //allocate an array of type PIXEL and have image->data point to it
int i;
for(i=0;i<(image->width * image->height);i++){
  fscanf(filepointer, "%d", &duff);
  image->data[i].r = duff;
  fscanf(filepointer, "%d", &duff);
  image->data[i].g = duff;
  fscanf(filepointer, "%d", &duff);
  image->data[i].b = duff;
}

fclose(filepointer);
return image;

}

void write_ppm(const char *file_name, const PPM_IMAGE *image){

  FILE *filepointer;

  filepointer = fopen(file_name,"w");

  fprintf(filepointer,"P3\n");
  fprintf(filepointer, "%d %d\n",image->width, image->height);
  fprintf(filepointer, "%d\n", image->max_color);
  int i;

  for(i=0;i<(image->width * image->height);i++){
    fprintf(filepointer,"%hhu ",image->data[i].r);
    fprintf(filepointer,"%hhu ",image->data[i].g);
    fprintf(filepointer,"%hhu ",image->data[i].b);
}

fclose(filepointer);

}
