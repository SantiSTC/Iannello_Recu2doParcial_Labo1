/*
 * func.h
 *
 *  Created on: 7 dic. 2022
 *      Author: Santiago
 */

#ifndef FUNC_H_
#define FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int ElegirOpcion(int max, int min);
int MenuPrincipal();
void PedirString(char* mensaje, char* string);
int PedirEntero(char* mensaje);

#endif /* FUNC_H_ */
