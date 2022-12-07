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

/// @brief Constructor de ePost.
/// @return Puntero al ePost reservado en memoria.
ePost* new_post();

/// @brief Constructor parametrizado de ePost.
/// @param idStr ID en forma de string.
/// @param userStr User en forma de string.
/// @param likesStr Cantidad de Likes en forma de string.
/// @param dislikesStr Cantidad de Dislikes en forma de string.
/// @param followersStr Cantidad de Followers en forma de string.
/// @return Puntero al ePost creado.
ePost* new_postParametros(char* idStr, char* userStr, char* likesStr, char* dislikesStr, char* followersStr);

/// @brief Setter de ID.
/// @param this Puntero a un elemento de tipo ePost.
/// @param id Numero a setear como ID.
/// @return 1 si funciono correctamente, 0 si no.
int post_setId(ePost* this,int id);

/// @brief Getter de ID.
/// @param this Puntero a un elemento de tipo ePost.
/// @param id Puntero a donde se guardara el numero obtenido.
/// @return 1 si funciono correctamente, 0 si no.
int post_getId(ePost* this,int* id);

/// @brief Setter de User.
/// @param this Puntero a un elemento de tipo ePost.
/// @param user Usuario a setear como User.
/// @return 1 si funciono correctamente, 0 si no.
int post_setUser(ePost* this,char* user);

/// @brief Getter de User.
/// @param this Puntero a un elemento de tipo ePost.
/// @param user Puntero a donde se guardara el user obtenido.
/// @return 1 si funciono correctamente, 0 si no.
int post_getUser(ePost* this,char* user);

/// @brief Setter de Likes.
/// @param this Puntero a un elemento de tipo ePost.
/// @param likes Numero a setear como likes.
/// @return 1 si funciono correctamente, 0 si no.
int post_setLikes(ePost* this,int likes);

/// @brief Getter de Likes.
/// @param this Puntero a un elemento de tipo ePost.
/// @param likes Puntero a donde se guardara el numero obtenido.
/// @return 1 si funciono correctamente, 0 si no.
int post_getLikes(ePost* this,int* likes);

/// @brief Setter de Dislikes.
/// @param this Puntero a un elemento de tipo ePost.
/// @param dislikes Numero a setear como dislikes.
/// @return 1 si funciono correctamente, 0 si no.
int post_setDislikes(ePost* this,int dislikes);

/// @brief Getter de Dislikes.
/// @param this Puntero a un elemento de tipo ePost.
/// @param dislikes Puntero a donde se guardara el numero obtenido.
/// @return 1 si funciono correctamente, 0 si no.
int post_getDislikes(ePost* this,int* dislikes);

/// @brief Setter de Followers.
/// @param this Puntero a un elemento de tipo ePost.
/// @param followers Numero a setear como followers.
/// @return 1 si funciono correctamente, 0 si no.
int post_setFollowers(ePost* this,int followers);

/// @brief Getter de Followers.
/// @param this Puntero a un elemento de tipo ePost.
/// @param followers Puntero a donde se guardara el numero obtenido.
/// @return 1 si funciono correctamente, 0 si no.
int post_getFollowers(ePost* this,int* followers);

/// @brief Muestra los datos de UN posteo.
/// @param unPost Recibe los datos de un post.
/// @return 1 si funciono correctamente, 0 si no.
int MostrarUnPost(ePost* unPost);

/// @brief Muestra una lista de posteos.
/// @param pArrayPosts Recibe un arrray de posteos.
/// @return 1 si funciono correctamente, 0 si no.
int MostrarListaPosteos(LinkedList* pArrayPosts);

/// @brief Obtiene un numero aleatorio entre 600 y 5000.
/// @param pElement puntero a elemento donde setear el numero obtenido.
/// @return 1 si funciono correctamente, 0 si no.
int ObtenerLikesAleatorios(void* pElement);

/// @brief Obtiene un numero aleatorio entre 300 y 3500.
/// @param pElement puntero a elemento donde setear el numero obtenido.
/// @return 1 si funciono correctamente, 0 si no.
int ObtenerDislikesAleatorios(void* pElement);

/// @brief Obtiene un numero aleatorio entre 10000 y 20000.
/// @param pElement puntero a elemento donde setear el numero obtenido.
/// @return 1 si funciono correctamente, 0 si no.
int ObtenerFollowersAleatorios(void* pElement);

/// @brief Corrobora que un post tenga mas de 4000 likes.
/// @param pElement Puntero al elemento a corroborar.
/// @return 1 si el post tiene mas de 4000 likes, 0 si no.
int FiltrarPorMejorPosteo(void* pElement);

/// @brief Corrobora que un post tenga mas dislikes que likes.
/// @param pElement Puntero al elemento a corroborar.
/// @return 1 si el post tiene mas dislikes que likes, 0 si no.
int FiltrarPorHaters(void* pElement);

/// @brief Compara la cantidad de followers de 2 elementos.
/// @param pElem1 Puntero al primer elemento a comparar.
/// @param pElem2 Puntero al segundo elemento a comparar.
/// @return 1 si el 1ero es MAYOR al 2do, -1 si el 1ero es MENOR al 2do, 0 si son iguales.
int CompararFollowers(void* pElem1, void* pElem2);

/// @brief Informa el usuario con el post mas likeado.
/// @param pArrayPosts Recibe una lista de posteos.
/// @return 1 si funciono correctamente, 0 si no.
int InformarUserMasLikeado(LinkedList* pArrayPosts);

#endif /* POST_H_ */
