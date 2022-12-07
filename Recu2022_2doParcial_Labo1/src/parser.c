/*
 * parser.c
 *
 *  Created on: 7 dic. 2022
 *      Author: Santiago
 */

#include "parser.h"
#include "LinkedList.h"

int parser_usersFromText(FILE* pFile, LinkedList* pArrayPosts)
{
	int retorno;
	int cant;
	char idStr[50];
	char userStr[50];
	char likesStr[50];
	char dislikesStr[50];
	char followersStr[50];
	ePost* unPost;

	if(pFile != NULL && pArrayPosts != NULL)
	{
		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, userStr, likesStr, dislikesStr, followersStr);

		if(cant == 5)
		{
			do
			{
				cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, userStr, likesStr, dislikesStr, followersStr);

				if(cant == 5)
				{
					unPost = new_postParametros(idStr, userStr, likesStr, dislikesStr, followersStr);

					if(unPost != NULL)
					{
						ll_add(pArrayPosts, unPost);
						retorno = 1;
					}
					else
					{
						free(unPost);
					}
				}

			}while(!feof(pFile));
		}
	}

	return retorno;
}

int parser_textFromPosts(FILE* pFile, LinkedList* pArrayPosts)
{
	int retorno = 0;
	ePost* unPost;
	int id;
	char user[50];
	int likes;
	int dislikes;
	int followers;

	if(pFile != NULL && pArrayPosts != NULL)
	{
		for(int i=0; i<ll_len(pArrayPosts); i++)
		{
			unPost = (ePost*) ll_get(pArrayPosts, i);

			if(unPost != NULL)
			{
				if(post_getId(unPost, &id) && post_getUser(unPost, user) && post_getLikes(unPost, &likes) && post_getDislikes(unPost, &dislikes) && post_getFollowers(unPost, &followers))
				{
					fprintf(pFile, "%d,%s,%d,%d,%d\n", id, user, likes, dislikes, followers);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}
















