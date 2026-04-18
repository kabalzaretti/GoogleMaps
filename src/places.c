#include "places.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// función para obtener la ruta del archivo de los places según el mapa elegido
// por el usuario
char *file_location_place(char *map) {
  if (strcmp(map, "2xl_1") == 0)
    return "../maps/2xl_1/places.txt";
  else if (strcmp(map, "lg_1") == 0)
    return "../maps/lg_1/places.txt";
  else if (strcmp(map, "md_1") == 0)
    return "../maps/md_1/places.txt";
  else if (strcmp(map, "xl_1") == 0)
    return "../maps/xl_1/places.txt";
  else if (strcmp(map, "xs_1") == 0)
    return "../maps/xs_1/places.txt";
  else if (strcmp(map, "xs_2") == 0)
    return "../maps/xs_2/places.txt";
  return NULL;
}

Places read_places(char *map) {
  // variables para almacenar temporalmente los datos de cada casa mientras se
  // leen del archivo
  double latitude, longitude;
  char name[ADRESS_MAX_LENGHT];
  char id[MAX_LENGTH_ID];
  char category[MAX_LENGTH_CATEGORY];
  // obtenemos la ruta del archivo de las casas según el mapa elegido por el
  // usuario
  char *file_path = file_location_place(map);

  // abrimos el archivo de las casas para lectura
  FILE *fp = fopen(file_path, "r");

  // creamos la linked list de casas, inicializando el head y tail a NULL, y
  // counter a 0
  Places place_list;
  place_list.head = NULL;
  place_list.tail = NULL;
  place_list.counter = 0; // el mismo metodo de contador para places que para
                          // houses para omptimizar el código

  // creamos un nodo temporal para almacenar la información de cada casa
  // mientras se lee del archivo, y luego lo añadimos a la linked list
  Direction *actual = malloc(sizeof(Direction));

  // leyendo y almacenando el primer nodo de la lista
  fscanf(fp, " %[^,],%[^,],%[^,],%lf,%lf", id, name, category, &latitude,
         &longitude);
  strcpy(actual->name, name);
  strcpy(actual->id, id);
  strcpy(actual->category, category);
  actual->latitude = latitude;
  actual->longitude = longitude;
  actual->next = NULL;

  // inicializamos el head y tail de la linked list con el primer nodo leído del
  // archivo y sumamos 1 a counter
  place_list.head = actual;
  place_list.tail = actual;
  place_list.counter++;

  // leemos el resto de nodos del archivo, creando un nuevo nodo para cada casa
  // y añadiéndolo al final de la linked list
  while (fscanf(fp, " %[^,],%[^,],%[^,],%lf,%lf", id, name, category, &latitude,
                &longitude) == 5) {
    // creamos un nuevo nodo para la casa leída del archivo
    Direction *next = malloc(sizeof(Direction));
    strcpy(next->name, name);
    strcpy(next->id, id);
    strcpy(next->category, category);
    next->latitude = latitude;
    next->longitude = longitude;
    next->next = NULL;

    // añadimos el nuevo nodo al final de la linked list, actualizando el
    // puntero next del nodo actual y el tail de la lista
    actual->next = next;

    // actualizamos el nodo actual al nuevo nodo añadido, para seguir añadiendo
    // nodos al final de la lista
    actual = next;

    // actualizamos el tail de la linked list al nuevo nodo añadido, para
    // mantener el tail apuntando al último nodo de la lista
    place_list.tail = actual;
    place_list.counter++;
  }
  fclose(fp);
  return place_list;
}

// función para liberar la memoria de la linked list de places, recorriendo la
// lista y liberando cada nodo uno por uno
void free_places(Places *places_list) {
  Direction *current = places_list->head;
  while (current != NULL) { // mientras no lleguemos al final de la lista,
                            // seguimos liberando memoria
    Direction *temp = current;
    current = current->next;
    free(temp);
  }
}