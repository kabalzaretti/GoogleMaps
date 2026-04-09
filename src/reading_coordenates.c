#include <stdio.h>
#include <string.h>
#include

char* read_map(){ 
    char* map;
    printf("Enter map name (e.g. 'xs_2' or 'xl_1'): ");
    scanf("%s",map);
    while(map != "xs_1" || map != "xs_2" || map != "md_1" || map != "lg_1" || map != "xl_1" || map != "2xl_1"){   
        printf("Arxive not correct, please repeat");
        scanf("%s",map);
    }
    return map;
}

void posicio_origen(){
    char* posicio;
    printf("Where are you? Address (1), Place (2) or Coordinate (3)?");
    scanf("%s",posicio);
    while(posicio != 1 || posicio != 2 || posicio != 3){
        printf("Answer not valid, please repeat");
        scanf("%s",posicio);
    }

    if (posicio == 2 || posicio == 3){
        printf("Not implemented yet")
    }
    else if(posicio == 1){
        char coordenades[2][150];
        printf("Enter your adress and house number");
        scanf("%s %s",coordenades);
        printf("")
    }
    
    
}