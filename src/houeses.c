#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADRESS_MAX_LENGHT 150
#define MAX_PATH_NAME 20

//Definin houses linked list
typedef struct {
    char* address;
    house* next;

}house;

//THis function find the correct location of the file houses.txt depending on the selected map
char* file_location(char* map){
    if(strcmp(map,"2xl_1")) return "../maps/2xl_1/houses.txt";
    else if(strcmp(map,"lg_1")) return "../maps/lg_1/houses.txt";
    else if(strcmp(map,"md_1")) return "../maps/md_1/houses.txt";
    else if(strcmp(map,"xl_1")) return "../maps/xl_1/houses.txt";
    else if(strcmp(map,"xs_1")) return "../maps/xs_1/houses.txt";
    else if(strcmp(map,"xs_2")) return "../maps/xs_2/houses.txt";
}

house* read_houses(char* map){
    char* file_path[MAX_PATH_NAME]=file_location(map);
    char buffer[ADRESS_MAX_LENGHT];
    FILE* fp=fopen(file_path,"r");
    while(fgets(buffer,sizeof(buffer),fp)!=NULL){
        
    }
}

