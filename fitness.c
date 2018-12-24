#include <stdio.h>
#include "a4.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>




double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  double distance;
  double sum = 0;
  int i;

  for(i=0; i<image_size; i++){
    distance = ((A[i].r - B[i].r) * (A[i].r - B[i].r)) + ((A[i].g - B[i].g ) * (A[i].g - B[i].g)) + ((A[i].b - B[i].b)* (A[i].b - B[i].b));
    sum += distance;
  }
  sum = sqrt(sum);
return sum;
}




void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
  int i;
  for(i=0;i<population_size;i++){
    individual[i].fitness = comp_distance(image, individual[i].image.data,(individual[i].image.width * individual[i].image.height));
  }

}

