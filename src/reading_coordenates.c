#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reading_coordenates.h"


// primer punto de lo que piden en el lab 2, lectura del mapa que se quiere usar
void read_map(char map[]){ 
    printf("Enter map name (e.g. 'xs_2' or 'xl_1'): ");
    scanf("%s",map);
    while(strcmp(map, "xs_1") != 0 && strcmp(map, "xs_2") != 0 && strcmp(map, "md_1") != 0 && strcmp(map, "lg_1") != 0 && strcmp(map, "xl_1") != 0 && strcmp(map, "2xl_1") != 0){   
        printf("Archive not correct, please repeat");
        scanf("%s",map);
    }
}

void sequential_search(Houses* houeses_list, char street[], int number){
    Adress* current = houeses_list->head;
    int found = 0;
    while(current != NULL){
        if(strcmp(street, current->street) == 0 && number == current->number){
            printf("Found at (%lf, %lf)", current->latitude, current->longitude);
            found = 1;
            break;
        }
        current = current->next;
    }
    if(found == 0){ // si no encontramos la casa, mostramos un mensaje de error al usuario
        printf("ERROR: adress not found in the map/\n");
    }
}

void origin_position(Houses *houses_list){
    int posicio;
    printf("Where are you? Address (1), Place (2) or Coordinate (3)?"); // segundo punto, se pide al usuario su posición de origen, si es dirección, lugar o coordenada
    scanf("%d",&posicio);
    while(posicio != 1 && posicio != 2 && posicio != 3){
        printf("Answer not valid, please repeat");
        scanf("%d",&posicio);
    }

    if (posicio == 2 || posicio == 3){
        printf("Not implemented yet\n"); // tercer punto, si escoge lugar o coordenada, no se implementa nada, solo se muestra un mensaje
    }
    else if(posicio == 1){ // cuarto punto, si escoge dirección, se pide la calle y el número y se busca en la linked list y se muestran las coordenadas
        char street[150];
        int number;
        printf("Enter street name (e.g. 'Carrer de Roc Boronat'): ");
        fgets(street, 150, stdin);
        street[strcspn(street, "\n")] = '\0';

        printf("Enter street number (e.g. '138'): ");
        scanf("%d", &number);
        sequential_search(houses_list->head, street, number);
    }
}