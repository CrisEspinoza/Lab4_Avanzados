#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"

#define DEBUG

// **************** Funciones auxiliares ******************

/* 
Entrada: Recibe la matriz que se utiliza actualmente.
Procedimiento: Se encarga de ir imprimiendo cada uno de los caminos generados y su respectivo costo de viaje.
Salida: -.
*/
void printCurrent()
{
    #ifdef DEBUG

    while(getchar() != '\n')
    {
        printf("Tecla errónea...\n");
    }
    #endif
}

/* 
Entrada: Recibe la variable matriz.
Procedimiento: Se encarga de liberar la memoria de la variable matriz que se ocupa a lo largo del programa, que ayuda a reiniciar el programa 
sin necesidad que se tenga que volver a ejecutar.
Salida: -.
*/

void freeMemory()
{

}

/*
Entrada: Recibe la lista de nodos.
Procedimiento: Imprime cada una de los valores del nodo.
Salida: - 
*/

void printListNodo ()
{

}
