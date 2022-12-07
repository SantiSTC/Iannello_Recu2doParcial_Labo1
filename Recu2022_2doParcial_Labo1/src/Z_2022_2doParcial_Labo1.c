/*
 ============================================================================
 Name        : Z_2022_2doParcial_Labo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "func.h"

int main(void) {
	setbuf(stdout, NULL);

	int option;
	char path[50];
	int retorno;
	int flagCargaArchivo = 0;
	int flagEstadisticas = 0;

	LinkedList* pArrayPosts = ll_newLinkedList();

	do
	{
		option = MenuPrincipal();

		switch(option)
		{
			case 1:
				if(flagCargaArchivo == 0)
				{
					PedirString("Ingrese el nombre del archivo a abrir: ", path);
					while(strcmp(path, "posts.csv")!=0)
					{
						PedirString("ERROR, el archivo no existe, ingrese el nombre del archivo a abrir: ", path);
					}
					retorno = controller_parserUsersFromText(path, pArrayPosts);
					if(retorno == 1)
					{
						printf("Se ha cargado el archivo con exito...\n");
						flagCargaArchivo = 1;
					}
					else
					{
						printf("No se ha podido cargar el archivo...\n");
					}
				}
				else
				{
					printf("ERROR, ya se ha cargado un archivo...");
				}
			break;
			case 2:
				if(flagCargaArchivo == 1)
				{
					retorno = controller_imprimirLista(pArrayPosts);
					if(retorno == 1)
					{
						printf("Se ha mostrado el archivo con exito...\n");
					}
					else
					{
						printf("No se ha podido mostrar el archivo...\n");
					}
				}
				else
				{
					printf("ERROR, se debera cargar un archivo antes de ingresar a esta opcion...\n");
				}
			break;
			case 3:
				if(flagCargaArchivo == 1)
				{
					retorno = controller_asignarEstadisticas(pArrayPosts);
					if(retorno == 1)
					{
						flagEstadisticas = 1;
						printf("Se han asignado las estadisticas con exito...\n");
					}
					else
					{
						printf("No se han podido asignar las estadisticas...\n");
					}
				}
				else
				{
					printf("ERROR, se debera cargar un archivo antes de ingresar a esta opcion...\n");
				}
			break;
			case 4:
				if(flagCargaArchivo == 1)
				{
					if(flagEstadisticas == 1)
					{
						retorno = controller_filtrarPorMejoresPosteos(pArrayPosts);
						if(retorno == 1)
						{
							printf("Se han filtrado con exito...\n");
						}
						else
						{
							printf("No se ha podido filtrar...\n");
						}
					}
					else
					{
						printf("Se debera asignar estadisticas antes de ingresar a esta opcion...\n");
					}

				}
				else
				{
					printf("ERROR, se debera cargar un archivo antes de ingresar a esta opcion...\n");
				}
			break;
			case 5:
				if(flagCargaArchivo == 1)
				{
					if(flagEstadisticas == 1)
					{
						retorno = controller_filtrarPorHaters(pArrayPosts);
						if(retorno == 1)
						{
							printf("Se ha filtrado con exito...\n");
						}
						else
						{
							printf("No se ha podido filtrar...\n");
						}
					}
					else
					{
						printf("Se debera asignar estadisticas antes de ingresar a esta opcion...\n");
					}

				}
				else
				{
					printf("ERROR, se debera cargar un archivo antes de ingresar a esta opcion...\n");
				}
			break;
			case 6:
				if(flagCargaArchivo == 1)
				{
					if(flagEstadisticas == 1)
					{
						retorno = controller_ordenarPorFollowers(pArrayPosts);
						if(retorno == 1)
						{
							printf("Se ha ordenado con exito...\n");
						}
						else
						{
							printf("No se ha podido ordenar...\n");
						}
					}
					else
					{
						printf("Se debera asignar estadisticas antes de ingresar a esta opcion...\n");
					}

				}
				else
				{
					printf("ERROR, se debera cargar un archivo antes de ingresar a esta opcion...\n");
				}
			break;
			case 7:
				if(flagCargaArchivo == 1)
				{
					if(flagEstadisticas == 1)
					{
						retorno = controller_mostrarMasPopular(pArrayPosts);
						if(retorno == 1)
						{
							printf("Se ha mostrado con exito...\n");
						}
						else
						{
							printf("No se ha podido mostrar...\n");
						}
					}
					else
					{
						printf("Se debera asignar estadisticas antes de ingresar a esta opcion...\n");
					}

				}
				else
				{
					printf("ERROR, se debera cargar un archivo antes de ingresar a esta opcion...\n");
				}
			break;
		}
	}while(option != 8);



	return 0;
}
