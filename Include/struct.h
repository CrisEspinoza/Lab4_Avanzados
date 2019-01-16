# ifndef STRUCT_H
# define STRUCT_H

// Definimos las estructuras a ocupar dentro de la aplicacion


typedef struct Box
{
	char element;
	int put;
}Box;

typedef struct Matriz
{
	Box** matriz;
	Box** matrizInv;
	int col;
	int row;
}Matriz;

// Definimos las funciones que se van a utilizar dentro del codigo 

Matriz* loadMatriz (char nombre[]);
Matriz* createListMatriz (Matriz* list, int numberRow, int numberCol);
Matriz* dinamica( Matriz* list);
int checkMatriz(Box** matriz, int row , int col , int initialRow, int initialCol, char element);
int auxDinamica(Box** matriz, int initialRow, int row , int initialCol, int col);
void printListMatriz (Matriz* list, int aux);
void freeMemory();
void printCurrent();

# endif