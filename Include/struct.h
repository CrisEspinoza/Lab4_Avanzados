# ifndef STRUCT_H
# define STRUCT_H

// Definimos las estructuras a ocupar dentro de la aplicacion

typedef struct List
{
	int numberCollectionCenter;
	int numberCollectionAvailable;
	float govermentMoney;
	float cost;
}List;

// Definimos las funciones que se van a utilizar dentro del codigo 

List* loadListNodo (char nombre[]);
void dinamica();
void printListNodo ();
void freeMemory();
void printCurrent();

# endif