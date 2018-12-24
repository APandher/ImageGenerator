#include <stdio.h>
#include "a4.h"
#include <stdlib.h>
#include <time.h>


void mutate(Individual *individual, double(rate)){
  int numPixels = (int)(rate/100*(individual->image.width*individual->image.height));
  int i;

  for(i = 0; i < numPixels; i++){
    int pixelIndex = rand()%(individual->image.width*individual->image.height);
    individual->image.data[pixelIndex].r = rand()%255;
    individual->image.data[pixelIndex].g = rand()%255;
    individual->image.data[pixelIndex].b = rand()%255;
  }
}



void mutate_population(Individual *individual, int population_size, double rate){
  int iterations = population_size - (population_size/4);
  int i;

  for(i=0; i<iterations; i++){
    mutate(&individual[(population_size/4) + i], rate);
  }
}
