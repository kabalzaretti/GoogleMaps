#include "houses.h"


//This function find the correct location of the file houses.txt depending on the selected map
char* file_location(char* map){
    if(strcmp(map,"2xl_1") == 0) return "maps/2xl_1/houses.txt";
    else if(strcmp(map,"lg_1") == 0) return "maps/lg_1/houses.txt";
    else if(strcmp(map,"md_1") == 0) return "maps/md_1/houses.txt";
    else if(strcmp(map,"xl_1") == 0) return "maps/xl_1/houses.txt";
    else if(strcmp(map,"xs_1") == 0) return "maps/xs_1/houses.txt";
    else if(strcmp(map,"xs_2") == 0) return "maps/xs_2/houses.txt";
    return NULL;
}

Houses read_houses(char* map){
    //Creating temporal variables
    double latitude,longitude;
    int number;
    char street[ADRESS_MAX_LENGHT];
    //We obtain the corresponding path of houses.txt
    char* file_path=file_location(map);
    
    //We open the file
    FILE* fp=fopen(file_path,"r");
    
    // we initialize the head of the linked and tail of list to null
    Houses houses_list;
    houses_list.head=NULL;
    houses_list.tail=NULL;

    //creating first node of the list
    Adress* actual=malloc(sizeof(Adress));

    //Readind and storing de first node of the list
    fscanf(fp,"%[^,],%d,%lf,%lf",street,&number,&latitude,&longitude);
    strcpy(actual->street,street);
    actual->number=number;
    actual->latitude=latitude;
    actual->longitude=longitude;
    actual->next=NULL;

    //Head and tail point to first node
    houses_list.head=actual;
    houses_list.tail=actual;

    //Adding all adresses
    while(fscanf(fp," %[^,],%d,%lf,%lf",street,&number,&latitude,&longitude)==4){
        //Creating next node
        Adress* next=malloc(sizeof(Adress));
        strcpy(next->street,street);
        next->number=number;
        next->latitude=latitude;
        next->longitude=longitude;
        next->next=NULL;

        //Conecting acutal to next
        actual->next=next;

        //Changing next to actual and changing tail
        actual=next;

        //Tail must point to last node
        houses_list.tail=actual;
        
    }
    fclose(fp);
    return houses_list;
}
// función para liberar la memoria de la linked list de casas, recorriendo la lista y liberando cada nodo uno por uno
void free_houses(Houses* houses_list) {
    Adress* current = houses_list->head; 
    while (current != NULL) { // mientras no lleguemos al final de la lista, seguimos liberando memoria
        Adress* temp = current;
        current = current->next;
        free(temp);
    }
}