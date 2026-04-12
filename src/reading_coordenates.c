#include <stdio.h>
#include <string.h>
#include <houses.c>

char read_map(){ 
    char map[30];
    printf("Enter map name (e.g. 'xs_2' or 'xl_1'): ");
    scanf("%s",map);
    while(strcmp(map, "xs_1") != 0 && strcmp(map, "xs_2") != 0 && strcmp(map, "md_1") != 0 && strcmp(map, "lg_1") != 0 && strcmp(map, "xl_1") != 0 && strcmp(map, "2xl_1") != 0){   
        printf("Arxive not correct, please repeat");
        scanf("%s",map);
    }
    return map;
}

void posicio_origen(house *head){
    int posicio;
    printf("Where are you? Address (1), Place (2) or Coordinate (3)?");
    scanf("%d",posicio);
    while(posicio != 1 && posicio != 2 && posicio != 3){
        printf("Answer not valid, please repeat");
        scanf("%d",posicio);
    }

    if (posicio == 2 || posicio == 3){
        printf("Not implemented yet\n");
    }
    else if(posicio == 1){
        char street[150];
        int number;
        printf("Enter street name (e.g. 'Carrer de Roc Boronat'): ");
        scanf("%s", street);
        printf("Enter street number (e.g. '138'): ");
        scanf("%d", number);
        
    }
    
    
}