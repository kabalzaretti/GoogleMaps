#ifndef PLACES_H
#define PLACES_H

#include <stdio.h>

#define ADRESS_MAX_LENGHT 200
#define MAX_PATH_NAME 40
#define MAX_LENGTH_ID 50
#define MAX_LENGTH_CATEGORY 100

// definimos la estructura de la casa, con su calle, número, latitud, longitud y
// un puntero a la siguiente casa para crear la linked list
typedef struct Direction {
  char id[MAX_LENGTH_ID];
  char name[ADRESS_MAX_LENGHT];
  char category[MAX_LENGTH_CATEGORY];
  double latitude;
  double longitude;
  struct Direction *next;
} Direction;

typedef struct {
  Direction *head;
  Direction *tail;
  int counter;
} Places;

char *file_location_house(char *map);
Places read_places(char *map);
void free_places(Places *places_list);

#endif