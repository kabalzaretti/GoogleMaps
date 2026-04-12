#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADRESS_MAX_LENGHT 150
#define MAX_PATH_NAME 20

//Definin houses linked list
typedef struct house_node {
    char street_name[100];
    int house_number;
    double latitude;
    double longitude;
    struct house_node* next;
}house;

//This function find the correct location of the file houses.txt depending on the selected map
char* file_location(char* map){
    if(strcmp(map,"2xl_1") == 0) return "../maps/2xl_1/houses.txt";
    else if(strcmp(map,"lg_1") == 0) return "../maps/lg_1/houses.txt";
    else if(strcmp(map,"md_1") == 0) return "../maps/md_1/houses.txt";
    else if(strcmp(map,"xl_1") == 0) return "../maps/xl_1/houses.txt";
    else if(strcmp(map,"xs_1") == 0) return "../maps/xs_1/houses.txt";
    else if(strcmp(map,"xs_2") == 0) return "../maps/xs_2/houses.txt";
}

house* read_houses(char* map){
    char* file_path =file_location(map);
    char buffer[ADRESS_MAX_LENGHT];
    FILE* fp=fopen(file_path,"r");
    house* head = NULL; // we initialize the head of the linked list to null
 while(fgets(buffer,sizeof(buffer),fp)!=NULL){
        //we create arrays to separate every part of the house
        char street_name[150];
        char text_number[20];
        char text_latitude[30];
        char text_longitude[30];

        int i = 0; 
        int j = 0;
        //we use loops to separate each part of the house that is together in the buffer
        while (buffer[i] != ',' && buffer[i] != '\0') {
            street_name[j] = buffer[i];
            i++; 
            j++;
        }
        street_name[j] = '\0'; // close word
        i++; // jump to the number
        j = 0; // restart j

        
        while (buffer[i] != ',' && buffer[i] != '\0') {
            text_number[j] = buffer[i];
            i++; 
            j++;
        }
        text_number[j] = '\0';
        i++; // jump to the latitude
        j = 0;

        
        while (buffer[i] != ',' && buffer[i] != '\0') {
            text_latitude[j] = buffer[i];
            i++; 
            j++;
        }
        text_latitude[j] = '\0';
        i++; // jump to the longitude
        j = 0;


        while (buffer[i] != '\n' && buffer[i] != '\0') {
            text_longitude[j] = buffer[i];
            i++; 
            j++;
        }
        text_longitude[j] = '\0';

        // once we have the parts separated, we convert the characters to numbers (int and lf)
        int final_number = atoi(text_number);
        double final_latitude = atof(text_latitude);
        double final_longitude = atof(text_longitude);

        house* new_house = (house*) malloc(sizeof(house));
        //we store each corresponding part in the open memory for that particular house
        strcpy(new_house->street_name, street_name);
        new_house->house_number = final_number;
        new_house->latitude = final_latitude;
        new_house->longitude = final_longitude;
        // we're going to create the linked list by placing each new house in front of the previous one
        new_house->next = head;
        head = new_house;
    }

}

