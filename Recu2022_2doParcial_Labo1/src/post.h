/*
 * post.h
 *
 *  Created on: 7 dic. 2022
 *      Author: Santiago
 */

#ifndef POST_H_
#define POST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct
{
	int id;
	char user[50];
	int likes;
	int dislikes;
	int followers;
}ePost;

ePost* new_post();
ePost* new_postParametros(char* idStr, char* userStr, char* likesStr, char* dislikesStr, char* followersStr);
int post_setId(ePost* this,int id);
int post_getId(ePost* this,int* id);
int post_setUser(ePost* this,char* user);
int post_getUser(ePost* this,char* user);
int post_setLikes(ePost* this,int likes);
int post_getLikes(ePost* this,int* likes);
int post_setDislikes(ePost* this,int dislikes);
int post_getDislikes(ePost* this,int* dislikes);
int post_setFollowers(ePost* this,int followers);
int post_getFollowers(ePost* this,int* followers);
int MostrarUnPost(ePost* unPost);
int MostrarListaPosteos(LinkedList* pArrayPosts);
int ObtenerLikesAleatorios(void* pElement);
int ObtenerDislikesAleatorios(void* pElement);
int ObtenerFollowersAleatorios(void* pElement);
int FiltrarPorMejorPosteo(void* pElement);
int FiltrarPorHaters(void* pElement);
int CompararFollowers(void* pElem1, void* pElem2);
int InformarUserMasLikeado(LinkedList* pArrayPosts);

#endif /* POST_H_ */
