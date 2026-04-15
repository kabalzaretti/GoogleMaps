// primer y segundo punto de "notes", lectura y parseo del archivo de las casas para guardarlas en una linked list

#ifndef HOUSES_H
#define HOUSES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADRESS_MAX_LENGHT 150
#define MAX_PATH_NAME 20

// definim la estructura de la casa, con su calle, número, latitud, longitud y un puntero a la siguiente casa para crear la linked list
typedef struct house_node {
    char street_name[100];
    int house_number;
    double latitude;
    double longitude;
    struct house_node* next;
}house;


void free_houses(house* head);
char* file_location(char* map); 
house* read_houses(char* map);

#endif
