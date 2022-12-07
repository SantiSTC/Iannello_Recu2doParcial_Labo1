/*
 * controller.h
 *
 *  Created on: 7 dic. 2022
 *      Author: Santiago
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "post.h"

int controller_parserUsersFromText(char* path, LinkedList* pArrayPosts);
int controller_imprimirLista(LinkedList* pArrayPosts);
int controller_asignarEstadisticas(LinkedList* pArrayPost);
int controller_filtrarPorMejoresPosteos(LinkedList* pArrayPost);
int controller_filtrarPorHaters(LinkedList* pArrayPost);
int controller_ordenarPorFollowers(LinkedList* pArrayPosts);
int controller_mostrarMasPopular(LinkedList* pArrayPosts);

#endif /* CONTROLLER_H_ */
