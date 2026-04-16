#ifndef PLACES_H
#define PLACES_H

#include <stdio.h>

#define ADRESS_MAX_LENGHT 200
#define MAX_PATH_NAME 40
#define MAX_LENGTH_ID 50

// definimos la estructura de la casa, con su calle, número, latitud, longitud y un puntero a la siguiente casa para crear la linked list
typedef struct Direction {
    char id[MAX_LENGTH_ID];
    int nom[ADRESS_MAX_LENGHT];
    double latitude;
    double longitude;
    struct Adress* next;
}Direction;

typedef struct{
    Adress* head;
    Adress* tail;
}Places;


char* file_location_house(char* map);

#endif