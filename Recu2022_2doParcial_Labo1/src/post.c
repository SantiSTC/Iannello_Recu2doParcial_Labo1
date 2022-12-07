/*
 * post.c
 *
 *  Created on: 7 dic. 2022
 *      Author: Santiago
 */

#include "post.h"

ePost* new_post()
{
	ePost* unPost = NULL;

	unPost = (ePost*) malloc(sizeof(ePost));

	if(unPost != NULL)
	{
		unPost->id = 0;
		strcpy(unPost->user, " ");
		unPost->likes = 0;
		unPost->dislikes = 0;
		unPost->followers = 0;
	}

	return unPost;
}

ePost* new_postParametros(char* idStr, char* userStr, char* likesStr, char* dislikesStr, char* followersStr)
{
	ePost* unPost = NULL;
	int id;
	int likes;
	int dislikes;
	int followers;

	if(idStr != NULL && userStr != NULL && likesStr != NULL && dislikesStr != NULL && followersStr != NULL)
	{
		unPost = new_post();

		id = atoi(idStr);
		likes = atoi(likesStr);
		dislikes = atoi(dislikesStr);
		followers = atoi(followersStr);

		if(unPost != NULL)
		{
			post_setId(unPost, id);
			post_setUser(unPost, userStr);
			post_setLikes(unPost, likes);
			post_setDislikes(unPost, dislikes);
			post_setFollowers(unPost, followers);
		}

	}

	return unPost;
}

int post_setId(ePost* this,int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int post_getId(ePost* this,int* id)
{
	int retorno = 0;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int post_setUser(ePost* this,char* user)
{
	int retorno = 0;

	if(this != NULL && user != NULL)
	{
		strcpy(this->user, user);
		retorno = 1;
	}

	return retorno;
}

int post_getUser(ePost* this,char* user)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(user, this->user);
		retorno = 1;
	}

	return retorno;
}

int post_setLikes(ePost* this,int likes)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->likes = likes;
		retorno = 1;
	}

	return retorno;
}

int post_getLikes(ePost* this,int* likes)
{
	int retorno = 0;

	if(this != NULL)
	{
		*likes = this->likes;
		retorno = 1;
	}

	return retorno;
}

int post_setDislikes(ePost* this,int dislikes)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->dislikes = dislikes;
		retorno = 1;
	}

	return retorno;
}

int post_getDislikes(ePost* this,int* dislikes)
{
	int retorno = 0;

	if(this != NULL)
	{
		*dislikes = this->dislikes;
		retorno = 1;
	}

	return retorno;
}

int post_setFollowers(ePost* this,int followers)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->followers = followers;
		retorno = 1;
	}

	return retorno;
}

int post_getFollowers(ePost* this,int* followers)
{
	int retorno = 0;

	if(this != NULL)
	{
		*followers = this->followers;
		retorno = 1;
	}

	return retorno;
}

int MostrarUnPost(ePost* unPost)
{
	int retorno = 0;
	int id;
	char user[50];
	int likes;
	int dislikes;
	int followers;

	if(unPost != NULL)
	{
		post_getId(unPost, &id);
		post_getUser(unPost, user);
		post_getLikes(unPost, &likes);
		post_getDislikes(unPost, &dislikes);
		post_getFollowers(unPost, &followers);

		printf("| %-3d | %-15s | %-7d | %-10d | %-10d|\n", id, user, likes, dislikes, followers);
		retorno = 1;
	}

	return retorno;
}

int MostrarListaPosteos(LinkedList* pArrayPosts)
{
	int retorno;
	ePost* unPost;

	if(pArrayPosts != NULL)
	{
		printf("============================================================\n"
				"| ID  |      User       | Likes   | Dislikes   | Followers |\n"
				"============================================================\n");

		for(int i=0; i<ll_len(pArrayPosts); i++)
		{
			unPost = (ePost*) ll_get(pArrayPosts, i);

			if(unPost != NULL)
			{
				retorno = MostrarUnPost(unPost);
			}
		}

		printf("============================================================\n");
	}

	return retorno;
}

int ObtenerLikesAleatorios(void* pElement)
{
	int likes;
	int retorno;
	ePost* unPost;

	unPost = (ePost*) pElement;

	likes = rand() % (5000-600+1) + 600;

	retorno = post_setLikes(unPost, likes);

	return retorno;
}

int ObtenerDislikesAleatorios(void* pElement)
{
	int dislikes;
	int retorno;
	ePost* unPost;

	unPost = (ePost*) pElement;

	dislikes = rand() % (3500-300+1) + 300;

	retorno = post_setDislikes(unPost, dislikes);

	return retorno;
}

int ObtenerFollowersAleatorios(void* pElement)
{
	int followers;
	int retorno;
	ePost* unPost;

	unPost = (ePost*) pElement;

	followers = rand() % (20000-10000+1) + 10000;

	retorno = post_setFollowers(unPost, followers);

	return retorno;
}

int FiltrarPorMejorPosteo(void* pElement)
{
	int retorno = 0;
	ePost* unPost;
	int cantLikes;

	unPost = (ePost*) pElement;

	post_getLikes(unPost, &cantLikes);

	if(cantLikes > 4000)
	{
		retorno = 1;
	}

	return retorno;
}

int FiltrarPorHaters(void* pElement)
{
	int retorno = 0;
	ePost* unPost;
	int cantLikes;
	int cantDislikes;

	unPost = (ePost*) pElement;

	post_getLikes(unPost, &cantLikes);
	post_getDislikes(unPost, &cantDislikes);

	if(cantDislikes > cantLikes)
	{
		retorno = 1;
	}

	return retorno;
}

int CompararFollowers(void* pElem1, void* pElem2)
{
	int retorno = 0;
	int followers1;
	int followers2;

	post_getFollowers(pElem1, &followers1);
	post_getFollowers(pElem2, &followers2);

	if(followers1 > followers2)
	{
		retorno = 1;
	}
	else
	{
		if(followers1 < followers2)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int InformarUserMasLikeado(LinkedList* pArrayPosts)
{
	int retorno = 0;
	int likes;
	int mayorCantLikes = 0;
	char userMasLikes[50];
	ePost* unPost;

	for(int i=0; i<ll_len(pArrayPosts); i++)
	{
		unPost = (ePost*) ll_get(pArrayPosts, i);

		if(unPost != NULL)
		{
			post_getLikes(unPost, &likes);

			if(likes > mayorCantLikes)
			{
				mayorCantLikes = likes;
				retorno = post_getUser(unPost, userMasLikes);
			}
		}
	}

	printf("El usuario con mas likes es %s, con %d likes.\n", userMasLikes, mayorCantLikes);

	return retorno;
}





































