/*
 * func.c
 *
 *  Created on: 7 dic. 2022
 *      Author: Santiago
 */

#include "func.h"

int ElegirOpcion(int max, int min)
{
	char opcion[50];
	int validar;
	int opcionElegida;

	validar = getStringNumeros("Ingrese una opción: ", opcion);
	opcionElegida = atoi(opcion);
	while(validar == 0 || (opcionElegida > max || opcionElegida < min))
	{
		validar = getStringNumeros("ERROR, Ingrese una opción valida: ", opcion);
		opcionElegida = atoi(opcion);
	}

	return opcionElegida;
}

int MenuPrincipal()
{
	int opcion;

	printf("=========================================\n"
			"            Menu Principal\n\n"
			" 1. Cargar archivo\n"
			" 2. Imprimir lista\n"
			" 3. Asignar estadisticas\n"
			" 4. Filtrar por mejores posteos\n"
			" 5. Filtrar por haters\n"
			" 6. Ordenar por cantidad de followers\n"
			" 7. Mostrar mas popular\n"
			" 8. Salir\n"
			"=========================================\n");

	opcion = ElegirOpcion(8, 1);

	return opcion;
}

void PedirString(char* mensaje, char* string)
{
	char stringAux[50];

	getString(mensaje, stringAux);
	while(strcmp(stringAux, "")==0)
	{
		getString(mensaje, stringAux);
	}

	strcpy(string, stringAux);
}

int PedirEntero(char* mensaje)
{
	char idStr[50];
	int id;
	int validar;

	validar = getStringNumeros(mensaje, idStr);
	id = atoi(idStr);
	while(validar == 0 || id < 0)
	{
		validar = getStringNumeros(mensaje, idStr);
		id = atoi(idStr);
	}

	return id;
}
