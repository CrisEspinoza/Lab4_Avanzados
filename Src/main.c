#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/struct.h"

/*
Entrada: Recibe como entrada los nombres de los archivos de entrada y salida, los cuales son ingresados por consola al compilar.
Procedimiento: Se encarga de llamar a cada una de las funciones y mostrar un menu para el usuario, que le permite ir escogiendo que 
    funcionanalidad ir realizando.
Salida: Entrega un valor booleano que indica que el proceso fue terminado con exito.
*/

int main(int argc, char *argv[])
{    
	// Se declaran las variables que se van a utilizar
    int option,flag = 0;
    Matriz* list;
    list = NULL; // Se inicializa la lista como nula

    if (argc == 3)
    {

        do
        {
            printf( "\n   1. Leer archivo");
            printf( "\n   2. Buscar cantidad de cortes");
            printf( "\n   3. Reiniciar Programa (Liberar memoria) ");
            printf( "\n   4. Creditos" );
            printf( "\n   5. Salir" );
            printf( "\n\n   Introduzca opcion (1-5): ");

            scanf( "%d", &option );

            /* Inicio del anidamiento */

            switch ( option )
            {
                case 1: system("clear");
                        if (flag == 0)
                        {
                            //printf("Ingrese nombre del archivo a leer (Sin extension) \n");
                            //scanf("%s",nameEntrada); // Se carga el nombre del archivo
                            list = loadMatriz (argv[1]); // Se lee el archivo y se almacena en memoria el grafo
                            //printf("sale");
                            //printf("%c", list->matriz[0][3].element);
                            if (list != NULL)
                            {
                                flag = 1;
                                printListMatriz(list, 0);
                                break;
                            }
                            printf("Reinicie el programa, archivo no existente \n");
                            return 0;
                        }
                        printf("Ya abrio un archivo reinicie el programa antes de cargar un nuevo archivo\n");
                        break;              

                case 2: system("clear");
                        if (list != NULL && flag == 1)
                        {
                            list = dinamica(list);
                            saveTablero(list);
                            flag = 2;
                            break;
                        }
                        printf("Primero debe cargar alguna matriz, elegir opcion 1 \n");
                        break;     

                case 3: system("clear");
                        freeMemory(list);
                        flag = 0 ;
                        break;

                case 4: system("clear");
                        printf(" * Autor: CRISTIAN EDUARDO ESPINOZA SILVA \n ");
                        printf(" * Universidad santiago de chile \n");
                        break;
            }

        }while(option != 5);
        
        return 0;
    }
    else
    {
        printf("La cantidad de parametros no es la indicada para poder ejecutar el programa \n");
        return 0;
    }
}