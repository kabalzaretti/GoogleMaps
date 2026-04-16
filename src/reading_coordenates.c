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
    char temp_adress[150];
    int found = 0;
    while(current != NULL){

        //Transforming street name in to lowercase
        lowercase_transform(street);

        strcpy(temp_adress,current->street);
        lowercase_transform(temp_adress);

        //Transformin avrebiatiom into normal words
        transform_abbreviations(temp_adress);


        if(strcmp(street, temp_adress) == 0 && number == current->number){
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

// segundo, tercer y cuarto punto del lab 2
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
        scanf("%s",street);
        

        printf("Enter street number (e.g. '138'): ");
        scanf("%d", &number);
        sequential_search(houses_list, street, number);
    }
}


//axuliar function that transform letter from a string from uppercase to lower case
void lowercase_transform(char* str){
    for(int i=0; i<strlen(str);i++){
        //Si el caracter esta en mayuscula entre 65 y 90 en la tabla ascii la cambiamos a minusculas
        if (str[i]>='A' && str[i]<='Z'){
            //We add 32 to transform in to lowercase
            str[i]=str[i]+32;
        }
    }
}

void transform_abbreviations (char* str){
    //we do a temporal copy de entring string 
    char temp_copy[150];
    strcpy(temp_copy,str);

    //Cutting the string untile de first space
    char avrebiation[10];
    int j=0;
    while (str[j]!=' ' && str[j] != '\0'){
        avrebiation[j]=str[j];
        j++;
    };
    //Adding the null caracter at the end of the array
    avrebiation[j]='\0';

    if(strcmp(avrebiation,"c.")==0){
        //Desplazamos el array 4 posiciones hacia adelante paraa poder subtitutir la avrebiatura por el nombre completo
        for(int i=0;i<strlen(str);i++){
            str[i+4]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='c'; str[1]='a'; str[2]='r'; str[3]='r'; str[4]='e'; str[5]='r';
    }
    else if(strcmp(avrebiation,"av.")==0){
        for(int i=0;i<strlen(str);i++){
            str[i+5]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='a'; str[1]='v'; str[2]='i'; str[3]='n'; str[4]='g'; str[5]='u'; str[6]='d'; str[7]='a';
    }
    else if(strcmp(avrebiation,"pg.")==0){
        for(int i=0;i<strlen(str);i++){
            str[i+4]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='p'; str[1]='a'; str[2]='s'; str[3]='s'; str[4]='e'; str[5]='i'; str[6]='g';
    }
    else if(strcmp(avrebiation,"ptge.")==0){
        for(int i=0;i<strlen(str);i++){
            str[i+3]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='p'; str[1]='a'; str[2]='s'; str[3]='s'; str[4]='a'; str[5]='t'; str[6]='g'; str[6]='e';
    }

    else if(strcmp(avrebiation,"rda.")==0){
        for(int i=0;i<strlen(str);i++){
            str[i+1]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='r'; str[1]='o'; str[2]='n'; str[3]='d'; str[4]='a'; 
    }
    else if(strcmp(avrebiation,"ctra.")==0){
        for(int i=0;i<strlen(str);i++){
            str[i+4]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='c'; str[1]='a'; str[2]='r'; str[3]='r'; str[4]='e'; str[5]='t'; str[6]='e'; str[7]='r';
        str[8]='a';     
    }
    else if(strcmp(avrebiation,"g.")==0){
        for(int i=0;i<strlen(str);i++){
            str[i+2]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='g'; str[1]='r'; str[2]='a'; str[3]='n'; 
    }
    else if(strcmp(avrebiation,"trav.")==0){
        for(int i=0;i<strlen(str);i++){
            str[i+5]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='T'; str[1]='r'; str[2]='a'; str[3]='v'; str[4]='e'; str[5]='s'; str[6]='s'; str[7]='e';
        str[8]='r';  str[9]='a';   
    }
    else if(strcmp(avrebiation,"pl.")==0){
        for(int i=0;i<strlen(str);i++){
            str[i+4]=temp_copy[i];
        }

        //Substituimos la abrevacion
        str[0]='p'; str[1]='l'; str[2]='a'; str[3]='ç'; str[4]='a';     
    }
    

}