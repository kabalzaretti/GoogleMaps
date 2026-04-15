#include "houses.h"

// función para obtener la ubicación del archivo de las casas dependiendo del mapa que se haya elegido
char* file_location(char* map){
    if(strcmp(map,"2xl_1") == 0) return "../maps/2xl_1/houses.txt";
    else if(strcmp(map,"lg_1") == 0) return "../maps/lg_1/houses.txt";
    else if(strcmp(map,"md_1") == 0) return "../maps/md_1/houses.txt";
    else if(strcmp(map,"xl_1") == 0) return "../maps/xl_1/houses.txt";
    else if(strcmp(map,"xs_1") == 0) return "../maps/xs_1/houses.txt";
    else if(strcmp(map,"xs_2") == 0) return "../maps/xs_2/houses.txt";
    return NULL;
}
// función para leer las casas del archivo y guardarlas en una linked list
house* read_houses(char* map){
    char* file_path =file_location(map);
    char buffer[ADRESS_MAX_LENGHT];
    FILE* fp=fopen(file_path,"r");
    house* head = NULL; // puntero a la cabeza de la linked list, inicialmente es NULL porque no hay ninguna casa leída todavía
    while(fgets(buffer,sizeof(buffer),fp)!=NULL){
        // creamos arrays para separar cada parte de la casa, la calle, el número, la latitud y la longitud
        char street_name[150];
        char text_number[20];
        char text_latitude[30];
        char text_longitude[30];

        int i = 0; 
        int j = 0;
        // separamos cada parte usando loops y guardamos cada parte en una variable diferente
        while (buffer[i] != ',' && buffer[i] != '\0') {
            street_name[j] = buffer[i]; // guardamos el carácter actual en el array del nombre de la calle 
            i++; 
            j++;
        }
        street_name[j] = '\0'; // añadimos el carácter de fin de cadena al final del nombre de la calle para que sea una cadena de caracteres válida
        i++; // saltamos la coma para empezar a leer el número de la casa 
        j = 0; // reiniciamos j para usarlo en el siguiente array

        // repetimos el mismo proceso para el número de la casa, la latitud y la longitud
        while (buffer[i] != ',' && buffer[i] != '\0') {
            text_number[j] = buffer[i]; 
            i++; 
            j++;
        }
        text_number[j] = '\0';
        i++; // saltamos la coma para empezar a leer la latitud
        j = 0; 

        // repetimos el mismo proceso para la latitud y la longitud
        while (buffer[i] != ',' && buffer[i] != '\0') {
            text_latitude[j] = buffer[i];
            i++; 
            j++;
        }
        text_latitude[j] = '\0';
        i++; // saltamos la coma para empezar a leer la longitud
        j = 0;

        // repetimos el mismo proceso para la longitud, ya no saltamos la coma porque es el último elemento de la línea
        while (buffer[i] != '\n' && buffer[i] != '\0') {
            text_longitude[j] = buffer[i];
            i++; 
            j++;
        }
        text_longitude[j] = '\0'; 

        // convertimos el número de la casa, la latitud y la longitud de texto a sus respectivos tipos de datos para poder almacenarlos en la estructura de la casa
        int final_number = atoi(text_number);
        double final_latitude = atof(text_latitude);
        double final_longitude = atof(text_longitude);

        house* new_house = (house*) malloc(sizeof(house));
        // guardamos cada parte correspondiente en la memoria abierta para esa casa en particular, usando strcpy para copiar el nombre de la calle porque es una cadena de caracteres y asignando directamente el número, la latitud y la longitud porque son tipos de datos primitivos
        strcpy(new_house->street_name, street_name);
        new_house->house_number = final_number;
        new_house->latitude = final_latitude;
        new_house->longitude = final_longitude;
        // creamos una nueva lista enlazada colocando cada nueva casa al frente de la anterior
        // we're going to create the linked list by placing each new house in front of the previous one
        new_house->next = head;
        head = new_house;
    }
    fclose(fp); // cerramos el archivo después de leer todas las casas para liberar recursos
    return head;
}

