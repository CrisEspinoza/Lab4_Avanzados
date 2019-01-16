#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"


// ****************** Funcion principal ******************//

/*
Entrada: Entra la lista de nodos y el nombre del archivo de salida.
Procedimiento: Se encarga de ir revisando los costos de traslado que tiene cada centro y esto se realiza hasta que se tiene una cantidad total de centros
            sin toneladas de basura, tal que, la cantidad de centros disponibles menos la cantidad de centros que no contiene toneladas de basura, es igual
            a la cantidad de centros que estan disponibles, segun el dato leido desde el archivo de texto.
Salida: -
*/

Matriz* dinamica( Matriz* list) 
{
    int i , j, put = 0;

    if (list->row != 1)
    {
        for (i = 1 ; i < list->row; i++)
        {
            //printf("Cortando filas \n");
            put = 1 + auxDinamica(list->matriz, 0, (list->row - i), 0, list->col) + auxDinamica(list->matriz, (list->row - i), list->row, 0, list->col) ;
            printf("Primera matriz: (Fila) inicio: %d - final: %d *****-***** (Columna) inicio: %d - final: %d ||||| %d x %d  \n",0, (list->row - i), 0, list->col, (list->row-i),list->col);
            printf("Segunda matriz: (Fila) inicio: %d - final: %d *****-***** (Columna) inicio: %d - final: %d ||||| %d x %d  \n",(list->row - i), list->row, 0, list->col, list->row,list->col);
            //printf("\n");
            //printf("\n");
            //printf("Cantidad de cortes es : %d \n", put);
            //printf("\n");
            //printf("\n");
            list->matriz[list->row - i][0].put = put;
        }
    }
    else{
        //printf("No necesitas corte mediante filas \n ");
    }

    //return 0;

    printf("\n");
    printf(" ****************************** ******************************************************************\n ");
    printf(" ****************************** ******************************************************************\n ");
    printf(" ****************************** Cortando la primera parte dle programan**********0*****************\n");
    printf(" ********************** ******** *****************************************************************\n ");
    printf(" ****************************** ******************************************************************\n ");
    printf("\n");

    if (list->col != 1)
    {
        //printf("Entre aca: Numero de columnas %d \n", list->col);
        for (i = 1 ; i < list->col; i++)
        {
            //printf("Cortando columnas \n");
            put = 1 + auxDinamica(list->matriz, 0, list->row, 0, (list->col - i ) )  + auxDinamica(list->matriz, 0 ,list->row, (list->col - i ) , list->col) ;
            printf("Primera matriz: (Fila) inicio: %d - final: %d *****-***** (Columna) inicio: %d - final: %d ||||| %d x %d  \n",0, list->row, 0, (list->col-i), list->row,(list->col-i) );
            printf("Segunda matriz: (Fila) inicio: %d - final: %d *****-***** (Columna) inicio: %d - final: %d ||||| %d x %d  \n",0,list->row, (list->col -i), list->col, list->row,list->col);
            //printf("\n");    if ( row == 5 && col == 5 )
            //printf("\n");    {
            //printf("Canti        return 0;
            //printf("\n");    }
            //printf("\n");
            list->matriz[0][list->col - i].put = put;
        }
    }
    else{   
        //printf("No necesitas corte mediante columnas \n ");
    }

    printListMatriz(list,1);
    return list;
}

int auxDinamica(Box** matriz, int initialRow, int row , int initialCol, int col)
{
    /*
    printf("Entrando a otro llamado recursivo ................ \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Filas: %d , columnas: %d \n" , row, col);
    printf("inicial en Filas: %d , inicial en columnas: %d \n", initialRow, initialCol);
    printf("Matriz real es de %d x %d " , (row - initialRow) , (col- initialCol) );
    printf("Entramos aca ... \n");
    printf("\n");
    printf("\n");
    printf("\n");
    */
    int i,j,put = 0;

    if (checkMatriz(matriz,row,col,initialRow,initialCol,'#') == 0 || checkMatriz(matriz,row,col,initialRow,initialCol,'.') == 0)
    {
        printf("Entre aca 0 \n");
        return 0;
    }
        
    else{
        //printf("\n");    
        //printf("\n");
        //printf(" Preparando corte de filas \n");
        //printf("\n");
        //printf("\n");
        if (abs(row - initialRow) != 1)
        {
            for (i = initialRow + 1 ; i < row; i++)
            {
                printf("Aqui \n");
                
                printf("Cortando filas \n");
                printf("\n");
                printf("\n");
                printf(" Tenemos que los cortes son: inicial fila: %d - fila : %d ******** incial columna: %d - col = %d  \n", 0,(row-1),0,col);
                printf(" Tenemos que los cortes son: inicial fila: %d - fila : %d ******** incial columna: %d - col = %d  \n", (row-i),row,0,col);
                printf("\n");
                printf("\n");
                
                printf("ROw: %d , Col : %d \n" , row,col);
                printf("inicial row: %d , inicial col: %d \n" , initialRow, initialCol);
                return 1 + auxDinamica(matriz, 0, (row - i), initialCol, col) + auxDinamica(matriz, (row - i), (row - initialRow), initialCol, col) ;
                
            }
        }
        else{
            printf("No necesitas corte mediante filas \n");
        }

        //printf("\n");    
        //printf("\n");
        //printf(" Preparando corte de columnas \n");
        //printf("\n");
        //printf("\n");

        printf("%d - %d ", col,initialCol);

        if (abs(col - initialCol) != 1)
        {
            for (i = initialCol + 1 ; i < col; i++)
            {
                printf("Aqui 1\n");
                /*
                printf("Cortando columnas \n");
                printf("\n");
                printf("\n");
                printf(" Tenemos que los cortes son: inicial fila: %d - fila : %d ******** incial columna: %d - col = %d  \n", 0,row,0,(col-i));
                printf(" Tenemos que los cortes son: inicial fila: %d - fila : %d ******** incial columna: %d - col = %d  \n", 0,row,(col-i),col);
                printf("\n");
                printf("\n");
                */
                printf("ROw: %d , Col : %d " , (row-initialRow),(col-initialCol));
                return 1 + auxDinamica(matriz, initialRow, row , 0, (col - i ))+ auxDinamica(matriz, initialRow ,row , (col - i ) , (col - initialCol)) ;
                
            }
        }
        else{   
            printf("No necesitas corte mediante columnas");
        }
    }
    return 0 ;
}

int checkMatriz(Box** matriz, int row , int col , int initialRow, int initialCol, char element)
{
    int i,j;
    /*printf("\n");
    printf("\n");
    printf(" Comparando simbolos \n");
    printf("\n");
    printf("\n");
    */
    for(i = initialRow; i < row; i++)
    {
        for(j = initialCol; j < col ; j++)
        {
            //printf("Elemento %c - %c \n", element,matriz[i][j].element);
            if ( element != matriz[i][j].element )
                return 1;
        }
    }

    return 0;

}