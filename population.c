#include <stdio.h>
#include "a4.h"
#include <stdlib.h>
#include <time.h>



PIXEL *generate_random_image(int width, int height, int max_color){

PIXEL *randomPixel = malloc(width * height * sizeof(PIXEL));

  int i;
  for(i=0; i<(width*height); i++){
    randomPixel[i].r = rand()%max_color;
    randomPixel[i].g = rand()%max_color;
    randomPixel[i].b = rand()%max_color;
  }



return randomPixel;

}



Individual *generate_population(int population_size, int width, int height, int max_color){

  Individual *individualArray = malloc(population_size * sizeof(Individual));
  int i;

    for(i=0;i<population_size;i++){
    individualArray[i].image.width = width;
    individualArray[i].image.height = height;
    individualArray[i].image.max_color = max_color;
    individualArray[i].image.data = generate_random_image(width,height,max_color);
  }


  return individualArray;
}

