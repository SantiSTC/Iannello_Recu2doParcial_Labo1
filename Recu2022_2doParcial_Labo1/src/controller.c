/*
 * controller.c
 *
 *  Created on: 7 dic. 2022
 *      Author: Santiago
 */

#include "controller.h"
#include "LinkedList.h"

int controller_parserUsersFromText(char* path, LinkedList* pArrayPosts)
{
	int retorno;
	FILE* pFile = fopen(path, "r");

	retorno = parser_usersFromText(pFile, pArrayPosts);

	fclose(pFile);

	return retorno;
}

int controller_imprimirLista(LinkedList* pArrayPosts)
{
	int retorno;

	retorno = MostrarListaPosteos(pArrayPosts);

	return retorno;
}

int controller_asignarEstadisticas(LinkedList* pArrayPost)
{
	int retorno = 0;

	if(ll_map(pArrayPost, ObtenerLikesAleatorios) && ll_map(pArrayPost, ObtenerDislikesAleatorios) && ll_map(pArrayPost, ObtenerFollowersAleatorios))
	{
		retorno = 1;
	}

	return retorno;
}

int controller_filtrarPorMejoresPosteos(LinkedList* pArrayPost)
{
	int retorno = 0;
	LinkedList* pArrayFiltradoPorMejor;
	FILE* pFile;

	pArrayFiltradoPorMejor = ll_filter(pArrayPost, FiltrarPorMejorPosteo);

	if(pArrayFiltradoPorMejor != NULL)
	{
		pFile = fopen("MejoresPosteos.csv", "w");

		parser_textFromPosts(pFile, pArrayFiltradoPorMejor);

		fclose(pFile);
		retorno = 1;
	}

	return retorno;
}

int controller_filtrarPorHaters(LinkedList* pArrayPost)
{
	int retorno = 0;
	LinkedList* pArrayFiltradoPorHaters;
	FILE* pFile;

	pArrayFiltradoPorHaters = ll_filter(pArrayPost, FiltrarPorHaters);

	if(pArrayFiltradoPorHaters != NULL)
	{
		pFile = fopen("MasHateados.csv", "w");

		parser_textFromPosts(pFile, pArrayFiltradoPorHaters);

		fclose(pFile);
		retorno = 1;
	}

	return retorno;
}

int controller_ordenarPorFollowers(LinkedList* pArrayPosts)
{
	int retorno = 0;
	LinkedList* pArrayClonePosts = ll_clone(pArrayPosts);

	if(ll_sort(pArrayClonePosts, CompararFollowers, 0) == 0)
	{
		MostrarListaPosteos(pArrayClonePosts);
		retorno = 1;
	}

	return retorno;
}

int controller_mostrarMasPopular(LinkedList* pArrayPosts)
{
	int retorno;

	retorno = InformarUserMasLikeado(pArrayPosts);

	return retorno;
}














