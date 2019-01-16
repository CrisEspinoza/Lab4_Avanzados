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

void printListMatriz (Matriz* list, int aux)
{
    printf("\n");
    printf("\n");
    printf("************** Mostrando matriz *****************");
    printf("\n");
    printf("\n");

    int i,j;
    for(i = 0 ; i < list->row ; i++)
    {
        for (j = 0 ; j < list->col; j++)
        {
            if (aux == 0)
                printf("%c ", list->matriz[i][j].element);
            else
                printf("%d ", list->matriz[i][j].put);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
    printf("************** Finalizado *****************");
    printf("\n");
    printf("\n");
}


Matriz* createListMatriz (Matriz* list, int numberRow, int numberCol)
{
    list->row = numberRow;
    list->col = numberCol;
    
    list->matriz = (Box**)malloc(sizeof(Box*)*numberRow); 
    list->matrizInv = (Box**)malloc(sizeof(Box*)*numberRow); 

    int i;
    for (i = 0 ; i < numberRow ; i++)
    {
        list->matriz[i] = (Box*)malloc(sizeof(Box)*numberCol);
        list->matrizInv[i] = (Box*)malloc(sizeof(Box)*numberCol); 
    }
    return list;
}