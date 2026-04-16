
// primer y segundo punto de "notes", lectura y parseo del archivo de las casas para guardarlas en una linked list

#ifndef HOUSES_H
#define HOUSES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADRESS_MAX_LENGHT 200
#define MAX_PATH_NAME 40

// definimos la estructura de la casa, con su calle, número, latitud, longitud y un puntero a la siguiente casa para crear la linked list
typedef struct Adress {
    char street[ADRESS_MAX_LENGHT];
    int number;
    double latitude;
    double longitude;
    struct Adress* next;
}Adress;

typedef struct{
    Adress* head;
    Adress* tail;
}Houses;

void free_houses(Houses* head);
char* file_location_houses(char* map); 
Houses read_houses(char* map);

#endif
