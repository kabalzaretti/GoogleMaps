#include <stdio.h>
#include <stdlib.h>
#include "houses.h"
#include "reading_coordenates.h"

int main() {
    // mensaje de bienvenida
    printf("*****************\nWelcome to Google Maps!\n*****************\n");
    
    // pedir al usuario el mapa que quiere usar
    char map[20];
    read_map(map);
    
    // leer las casas del mapa elegido y guardarlas en una linked list, luego contar cuántas casas se cargaron y mostrarlo al usuario
    house* houses_list = read_houses(map);
    
    // contar cuántas casas se cargaron y mostrarlo al usuario
    int count = 0;
    house* current = houses_list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("%d houses loaded\n", count);
    
    // pedir posición de origen
    origin_position(houses_list);
    
    // liberar memoria (TODO: crear función free_houses)
    free_houses(houses_list);
    
    return 0;
}