/*
 ============================================================================
 Name        : TP4_2Cuatri_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char continente[50];
	int poblacion;
}Pais;

Pais* pais_new();
Pais* pais_newPar(int id, char nombre[], char contienente[], int poblacion);
int FuncCriterio(void* elem1, void* elem2);
int ObtenerPoblacion(Pais* unPais, int* poblacion);

Pais listaPaises[5] = {{1,"Argentina","America",45000000},{2,"España","Europa",55000000},{3,"Uruguay","America",5000000},{4,"Sudafrica","Africa",60000000},{5,"China","Asia",1000000000}};

int main(void){
	setbuf(stdout, NULL);

	LinkedList* nuevaLista;
	LinkedList* listaClon;
	LinkedList* listaFromTo;
	Pais* unPais;
	Pais* pNodo;
	Pais* pNodoNew;

	nuevaLista = ll_newLinkedList();
	listaClon = ll_newLinkedList();
	listaFromTo = ll_newLinkedList();

	printf("==============================================\n"
			"Usado: ll_add\n"
			"	ll_isEmpty\n"
			"	ll_get\n"
			"	ll_len\n\n");

	for(int i=0; i<5; i++)
	{
		unPais = pais_newPar(listaPaises[i].id, listaPaises[i].nombre, listaPaises[i].continente, listaPaises[i].poblacion);

		ll_add(nuevaLista, unPais);
	}

	if(ll_isEmpty(nuevaLista) == 0)
	{
		for(int i=0; i<ll_len(nuevaLista); i++)
		{
			pNodo = (Pais*) ll_get(nuevaLista, i);

			printf("%d - %s - %s - %d\n", pNodo->id, pNodo->nombre, pNodo->continente, pNodo->poblacion);
		}
	}

	printf("==============================================\n"
			"Usado: ll_set\n"
			"	ll_isEmpty\n"
			"	ll_get\n"
			"	ll_len\n\n");

	pNodoNew = pais_newPar(5, "Japon", "Asia", 150000000);
	ll_set(nuevaLista, ll_len(nuevaLista)-1, pNodoNew);

	if(ll_isEmpty(nuevaLista) == 0)
	{
		for(int i=0; i<ll_len(nuevaLista); i++)
		{
			pNodo = (Pais*) ll_get(nuevaLista, i);

			printf("%d - %s - %s - %d\n", pNodo->id, pNodo->nombre, pNodo->continente, pNodo->poblacion);
		}
	}

	printf("==============================================\n"
			"Usado: ll_remove\n"
			"	ll_isEmpty\n"
			"	ll_get\n"
			"	ll_len\n\n");

	ll_remove(nuevaLista, ll_len(nuevaLista)-1);

	if(ll_isEmpty(nuevaLista) == 0)
	{
		for(int i=0; i<ll_len(nuevaLista); i++)
		{
			pNodo = (Pais*) ll_get(nuevaLista, i);

			printf("%d - %s - %s - %d\n", pNodo->id, pNodo->nombre, pNodo->continente, pNodo->poblacion);
		}
	}

	printf("==============================================\n"
			"Usado: ll_indexOf\n"
			"	ll_get\n"
			"	ll_len\n\n");

	for(int i=0; i<ll_len(nuevaLista); i++)
	{
		pNodo = (Pais*) ll_get(nuevaLista, i);

		printf("%d\n", ll_indexOf(nuevaLista, pNodo));
	}

	printf("==============================================\n"
			"Usado: ll_push\n"
			"	ll_isEmpty\n"
			"	ll_get\n"
			"	ll_len\n\n");

	pNodoNew = pais_newPar(5, "Japon", "Asia", 150000000);
	ll_push(nuevaLista, ll_len(nuevaLista), pNodoNew);

	if(ll_isEmpty(nuevaLista) == 0)
	{
		for(int i=0; i<ll_len(nuevaLista); i++)
		{
			pNodo = (Pais*) ll_get(nuevaLista, i);

			printf("%d - %s - %s - %d\n", pNodo->id, pNodo->nombre, pNodo->continente, pNodo->poblacion);
		}
	}

	printf("==============================================\n"
			"Usado: ll_pop\n"
			"	ll_len\n\n");

	pNodoNew = ll_pop(nuevaLista, ll_len(nuevaLista)-1);
	printf("%d - %s - %s - %d\n", pNodoNew->id, pNodoNew->nombre, pNodoNew->continente, pNodoNew->poblacion);

	printf("==============================================\n"
			"Usado: ll_contains\n\n");

	if(ll_contains(nuevaLista, pNodoNew))
	{
		printf("La lista contiene el elemento\n");
	}
	else
	{
		printf("La lista no contiene este elemento\n");
	}

	printf("==============================================\n"
			"Usado: ll_clone\n"
			"	ll_containsAll\n\n");

	listaClon = ll_clone(nuevaLista);

	if(ll_containsAll(listaClon, nuevaLista))
	{
		printf("Todos los elementos de la lista están en el clon\n");
	}
	else
	{
		printf("No todos los elementos de la lista esta contenidos en el clon\n");
	}

	printf("==============================================\n"
			"Usado: ll_subList\n"
			"	ll_isEmpty\n"
			"	ll_get\n"
			"	ll_len\n\n");

	listaFromTo = ll_subList(nuevaLista, 1, ll_len(nuevaLista)-1);

	if(ll_isEmpty(listaFromTo) == 0)
	{
		for(int i=0; i<ll_len(listaFromTo); i++)
		{
			pNodo = (Pais*) ll_get(listaFromTo, i);

			printf("%d - %s - %s - %d\n", pNodo->id, pNodo->nombre, pNodo->continente, pNodo->poblacion);
		}
	}

	printf("==============================================\n"
			"Usado: ll_sort\n"
			"	ll_isEmpty\n"
			"	ll_get\n"
			"	ll_len\n\n");

	ll_sort(nuevaLista, FuncCriterio, 0);

	if(ll_isEmpty(nuevaLista) == 0)
	{
		for(int i=0; i<ll_len(nuevaLista); i++)
		{
			pNodo = (Pais*) ll_get(nuevaLista, i);

			printf("%d - %s - %s - %d\n", pNodo->id, pNodo->nombre, pNodo->continente, pNodo->poblacion);
		}
	}
	printf("==============================================\n"
			"\n"
			"Vacio las listas con ´ll_clear´\n"
			"Elimino las listas con ´ll_deleteLinkedList´\n");

	ll_clear(nuevaLista);
	ll_clear(listaClon);
	ll_clear(listaFromTo);

	ll_deleteLinkedList(nuevaLista);
	ll_deleteLinkedList(listaClon);
	ll_deleteLinkedList(listaFromTo);


    return 0;
}

Pais* pais_new()
{
	Pais* unPais;

	unPais = (Pais*) malloc(sizeof(Pais));

	if(unPais != NULL)
	{
		unPais->id = 0;
		strcpy(unPais->nombre, " ");
		strcpy(unPais->continente, " ");
		unPais->poblacion = 0;
	}

	return unPais;
}

Pais* pais_newPar(int id, char nombre[], char contienente[], int poblacion)
{
	Pais* unPais = pais_new();

	if(unPais != NULL)
	{
		unPais->id = id;
		strcpy(unPais->nombre, nombre);
		strcpy(unPais->continente, contienente);
		unPais->poblacion = poblacion;
	}

	return unPais;
}

int FuncCriterio(void* elem1, void* elem2)
{
	int retorno = 0;
	int poblacion1;
	int poblacion2 ;

	ObtenerPoblacion(elem1, &poblacion1);
	ObtenerPoblacion(elem2, &poblacion2);

	if(poblacion1 > poblacion2)
	{
		retorno = 1;
	}
	else
	{
		if(poblacion1 < poblacion2)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int ObtenerPoblacion(Pais* unPais, int* poblacion)
{
	int retorno;

	if(unPais != NULL)
	{
		*poblacion = unPais->poblacion;
		retorno = 1;
	}

	return retorno;
}

