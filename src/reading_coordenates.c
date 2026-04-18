#include "reading_coordenates.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// axuliar function that transform letter from a string from uppercase to lower
// case
void lowercase_transform(char *str) {
  for (size_t i = 0; i < strlen(str); i++) {
    // Si el caracter esta en mayuscula entre 65 y 90 en la tabla ascii la
    // cambiamos a minusculas
    if (str[i] >= 'A' && str[i] <= 'Z') {
      // We add 32 to transform in to lowercase
      str[i] = str[i] + 32;
    }
  }
}

// primer punto de lo que piden en el lab 2, lectura del mapa que se quiere usar
void read_map(char map[]) {
  printf("Enter map name (e.g. 'xs_2' or 'xl_1'): ");
  scanf("%s", map);
  while (strcmp(map, "xs_1") != 0 && strcmp(map, "xs_2") != 0 &&
         strcmp(map, "md_1") != 0 && strcmp(map, "lg_1") != 0 &&
         strcmp(map, "xl_1") != 0 && strcmp(map, "2xl_1") != 0) {
    printf("Archive not correct, please repeat");
    scanf("%s", map);
  }
}

void sequential_search_houses(Houses *houeses_list, char street[], int number) {
  Adress *current = houeses_list->head;
  char temp_adress[150];
  int found = 0;
  // Transforming street name in to lowercase
  lowercase_transform(street);
  while (current != NULL) {

    strcpy(temp_adress, current->street);
    lowercase_transform(temp_adress);

    if (strcmp(street, temp_adress) == 0 && number == current->number) {
      printf("Found at (%lf, %lf)\n", current->latitude, current->longitude);
      found = 1;
      break;
    }
    current = current->next;
  }
  if (found == 0) { // si no encontramos la casa, mostramos un mensaje de error
                    // al usuario
    printf("ERROR: adress not found in the map\n");
  }
}

void sequential_search_places(Places *places_list, char place[]) {
  Direction *current = places_list->head;
  char temp_direction[150];
  int found = 0;
  // Transforming place name in to lowercase
  lowercase_transform(place);

  while (current != NULL) {

    strcpy(temp_direction, current->name);
    lowercase_transform(temp_direction);

    if (strcmp(place, temp_direction) == 0) {
      printf("Found at (%lf, %lf)\n", current->latitude, current->longitude);
      found = 1;
      break;
    }
    current = current->next;
  }
  if (found == 0) { // si no encontramos la casa, mostramos un mensaje de error
                    // al usuario
    printf("ERROR: adress not found in the map\n");
  }
}

void origin_position(Houses *houses_list, Places *places_list) {
  int posicio;
  printf(
      "Where are you? Address (1), Place (2) or Coordinate (3)?"); // segundo
                                                                   // punto, se
                                                                   // pide al
                                                                   // usuario su
                                                                   // posición
                                                                   // de origen,
                                                                   // si es
                                                                   // dirección,
                                                                   // lugar o
                                                                   // coordenada
  scanf("%d", &posicio);
  while (posicio != 1 && posicio != 2 && posicio != 3) {
    printf("Answer not valid, please repeat");
    scanf("%d", &posicio);
  }

  if (posicio == 2) {
    char place[ADRESS_MAX_LENGHT];
    printf("Enter place name (e.g. 'Universitat Pompeu Fabra–Campus del "
           "Poblenou' or 'L'Illa Diagonal'): ");
    scanf(" %[^\n]", place);
    sequential_search_places(places_list, place);

  }

  else if (posicio == 3) {
    printf(
        "Not implemented yet\n"); // tercer punto,coordenada, no se implementa
                                  // nada, solo se muestra un mensaje
  } else if (posicio == 1) { // cuarto punto, si escoge dirección, se pide la
                             // calle y el número y se busca en la linked list y
                             // se muestran las coordenadas
    char street[ADRESS_MAX_LENGHT];
    int number;
    printf("Enter street name (e.g. 'Carrer de Roc Boronat'): ");
    scanf(" %[^\n]", street);

    printf("Enter street number (e.g. '138'): ");
    scanf("%d", &number);
    sequential_search_houses(houses_list, street, number);
  }
}
