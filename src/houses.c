#include "houses.h"


// función para obtener la ruta del archivo de las houses según el mapa elegido por el usuario
char* file_location_house(char* map){
    if(strcmp(map,"2xl_1") == 0) return "../maps/2xl_1/houses.txt";
    else if(strcmp(map,"lg_1") == 0) return "../maps/lg_1/houses.txt";
    else if(strcmp(map,"md_1") == 0) return "../maps/md_1/houses.txt";
    else if(strcmp(map,"xl_1") == 0) return "../maps/xl_1/houses.txt";
    else if(strcmp(map,"xs_1") == 0) return "../maps/xs_1/houses.txt";
    else if(strcmp(map,"xs_2") == 0) return "../maps/xs_2/houses.txt";
    return NULL;
}

Houses read_houses(char* map){
    // variables para almacenar temporalmente los datos de cada casa mientras se leen del archivo
    double latitude,longitude;
    int number;
    char street[ADRESS_MAX_LENGHT];
    // obtenemos la ruta del archivo de las casas según el mapa elegido por el usuario
    char* file_path=file_location_house(map);
    
    // abrimos el archivo de las casas para lectura
    FILE* fp=fopen(file_path,"r");
    
    // creamos la linked list de casas, inicializando el head y tail a NULL, y counter a 0
    Houses houses_list;
    houses_list.head=NULL;
    houses_list.tail=NULL;
    houses_list.counter = 0; //ponemos el contador en el struct para poder ir sumando 1 cada vez que añadimos una casa
    // y así es mucho mas eficiente acceder en el main solo al counter (O(1)) que en el main recorrer toda la linked
    // list que seria una complejidad O(n) de muchos parametros

    // creamos un nodo temporal para almacenar la información de cada casa mientras se lee del archivo, y luego lo añadimos a la linked list
    Adress* actual=malloc(sizeof(Adress));

    // leyendo y almacenando el primer nodo de la lista
    fscanf(fp,"%[^,],%d,%lf,%lf",street,&number,&latitude,&longitude);
    strcpy(actual->street,street);
    actual->number=number;
    actual->latitude=latitude;
    actual->longitude=longitude;
    actual->next=NULL;

    // inicializamos el head y tail de la linked list con el primer nodo leído del archivo y sumamos 1 a counter
    houses_list.head=actual;
    houses_list.tail=actual;
    houses_list.counter++;

    // leemos el resto de nodos del archivo, creando un nuevo nodo para cada casa y añadiéndolo al final de la linked list
    while(fscanf(fp," %[^,],%d,%lf,%lf",street,&number,&latitude,&longitude)==4){
        // creamos un nuevo nodo para la casa leída del archivo
        Adress* next=malloc(sizeof(Adress));
        strcpy(next->street,street);
        next->number=number;
        next->latitude=latitude;
        next->longitude=longitude;
        next->next=NULL;

        // añadimos el nuevo nodo al final de la linked list, actualizando el puntero next del nodo actual y el tail de la lista
        actual->next=next;

        // actualizamos el nodo actual al nuevo nodo añadido, para seguir añadiendo nodos al final de la lista
        actual=next;

        // actualizamos el tail de la linked list al nuevo nodo añadido, para mantener el tail apuntando al último nodo de la lista
        houses_list.tail=actual;
        houses_list.counter++;
        
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