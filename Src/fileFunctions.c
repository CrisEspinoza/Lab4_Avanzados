#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/struct.h"

// ******************   Funciones para realizar escritura y lectura de archivos  ******************//

/*
Entrada: Entra el nombre del archivo.
Procedimiento: Realiza la asignación de los datos para cada uno de los valores de los nodos que son leidos desde el archivo de texto.
Salida: Entrega la lista con los datos leidos desde el archivo de texto.
*/

Matriz* loadMatriz (char nombre[])
{
	FILE *file; // Declaramos un puntero File para poder leer el file de entrada.
	char* route = (char*)calloc(100, sizeof(char));
	strcat(route, "../Documents/");
	strcat(route, nombre);
    strcat(route, ".in");
    file = fopen (route, "r"); // Estamos abriendo el file en modo lectura

    Matriz* list = (Matriz*)malloc(sizeof(Matriz));; // Se declara una variable de tipo matriz
    int numberCol,numberRow,i,j; 
    char element;
    //Verificamos si el file se encuentra nulo
    if( file == NULL)
    {
        printf("Error al abrir archivo \n");
        return NULL;
    }

    // Leemos las primeras lineas del file para un mejor manejo de este
    fscanf(file, "%d %d", &numberRow, &numberCol );

    //printf("%d %d ", numberCol, numberRow);

    list = createListMatriz(list, numberRow,numberCol);

    //printf("Sali");

    while(getc(file) != '\n'); // Que lea el file siempre y cuando no sea un salto de linea
    while (!feof(file)) 
    {
        //printf("ENtre");

        for (i = 0 ; i < numberRow; i++)
        {
            for(j = 0 ; j < numberCol; j++)
            {          
                fscanf(file, "%c ", &element);
                list->matriz[i][j].element = element;
                //list->matrizInv[][].element = element;
                list->matriz[i][j].put = 0;
                //printf("%c" , list->matriz[i][j].element);
            }
        }
    }
    
    fclose(file); // Cerramos el file
 
    return list; //Retornamo la variable matriz, con el tablero contenido, el cual se leyó desde el file ingresado

}
