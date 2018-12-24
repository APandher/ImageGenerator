#include <stdio.h>
#include "a4.h"
#include <stdlib.h>
#include <time.h>

// implemented from https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs?fbclid=IwAR0YYBA3xhJC4noHkllk4037JzYO-luVum__1_vCX70GxKzdYzZyzhRT7A4
static int compare (const void * a, const void * b)
{

  Individual *individualA = (Individual *)a;
  Individual *individualB = (Individual *)b;

  return (individualA->fitness - individualB->fitness);
}


static void freefunction(Individual *individual, int population_size){
int i;
for(i=0; i<population_size; i++){
  free(individual[i].image.data);
}
free(individual);
}



PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
  srand(time(NULL));

  Individual *randomPopulation = generate_population(population_size,image->width,image->height,image->max_color);
  comp_fitness_population(image->data, randomPopulation, population_size);
 //printf("fitness 0 %f \n", randomPopulation[0].fitness);

  qsort(randomPopulation,population_size,sizeof(Individual),compare);
  int i;

  for(i=1; i<num_generations;i++){
    //printf("generation %d fitness 0 %f \n",i, randomPopulation[0].fitness);
    crossover(randomPopulation, population_size);
    mutate_population(randomPopulation, population_size, rate);
    comp_fitness_population(image->data, randomPopulation, population_size);
    qsort(randomPopulation,population_size,sizeof(Individual),compare);
  }

  PPM_IMAGE *p = malloc(sizeof(PPM_IMAGE));
  PIXEL *e = malloc(randomPopulation[0].image.width*randomPopulation[0].image.height* sizeof(PIXEL));
  p->width = randomPopulation[0].image.width;
  p->height = randomPopulation[0].image.height;
  p->max_color = randomPopulation[0].image.max_color;
  int d;
  for (d = 0; d < randomPopulation[0].image.width*randomPopulation[0].image.height; d++){
    e[d] = randomPopulation[0].image.data[d];
  }
  p->data = e;

  freefunction(randomPopulation, population_size);
  return p;

}


void free_image(PPM_IMAGE *p){
  free(p->data);
  free(p);
}
