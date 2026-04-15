// creamos un header file para la lectura de las coordenadas, con las funciones necesarias para leer el mapa, buscar la posición de origen del usuario y hacer la búsqueda secuencial de las coordenadas de las casas

#ifndef READING_COORDENATES_H
#define READING_COORDENATES_H

#include "houses.h"

void read_map(char map[]);
struct house* sequential_search(struct house* head, char street[], int number);
void origin_position(struct house *head);

#endif