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
    Houses houses_list = read_houses(map);
    
    // contar cuántas casas se cargaron y mostrarlo al usuario
    int count = 0;
    Adress* current = houses_list.head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("%d houses loaded\n", count);
    
    // pedir posición de origen
    origin_position(&houses_list);
    
    // liberar memoria
    free_houses(&houses_list);
    
    return 0;
}