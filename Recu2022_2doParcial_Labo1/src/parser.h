/*
 * parser.h
 *
 *  Created on: 7 dic. 2022
 *      Author: Santiago
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"

int parser_usersFromText(FILE* pFile, LinkedList* pArrayPosts);
int parser_textFromPosts(FILE* pFile, LinkedList* pArrayPosts);


#endif /* PARSER_H_ */
