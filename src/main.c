#include "houses.h"
#include "places.h"
#include "reading_coordenates.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // mensaje de bienvenida
  printf("*****************\nWelcome to Google Maps!\n*****************\n");

  // pedir al usuario el mapa que quiere usar
  char map[20];
  read_map(map);

  // leer las casas del mapa elegido y guardarlas en una linked list, luego
  // contar cuántas casas se cargaron y mostrarlo al usuario
  Houses houses_list = read_houses(map);
  Places places_list = read_places(map);

  // imprimir cuántas casas se cargaron simplemente accediendo dentro del struct
  // a counter y mostrarlo al usuario
  printf("%d houses loaded\n", houses_list.counter);

  // imprimir cuántos places se cargaron simplemente accediendo dentro del
  // struct a counter y mostrarlo al usuario
  printf("%d places loaded\n", places_list.counter);

  // pedir posición de origen
  origin_position(&houses_list, &places_list);

  // liberar memoria
  free_houses(&houses_list);
  free_places(&places_list);

  return 0;
}