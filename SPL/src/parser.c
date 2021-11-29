#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "libros.h"
#include "editoriales.h"
#include "parser.h"


int parser_libroFromText(FILE* pFile , LinkedList* pArrayList)
{
	char id[51];
	char titulo[51];
	char autor[51];
	char precio[51];
	char idEditorial[51];
	int retorno;
	retorno = -1;
	eLibro* aux;

	if(pFile!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, titulo, autor, precio, idEditorial);
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, titulo, autor, precio, idEditorial) == 5)
			{
				aux = libro_newParametros(id, titulo, autor, precio, idEditorial);
				if(aux != NULL)
				{
					ll_add(pArrayList, aux);//
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}
/******************************************************************************/
int parser_editorialFromText(FILE* pFile , LinkedList* pArrayList)
{
	char id[51];
	char nombre[51];
	int retorno;
	retorno = -1;
	eEditorial* aux;
	if(pFile!=NULL)
	{
		fscanf(pFile, "%[^,],%[^\n]",id ,nombre);
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,],%[^\n]", id, nombre) == 2)
			{
				aux = editorial_newParametros(id, nombre);
				if(aux != NULL)
				{
					ll_add(pArrayList, aux);//
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}
/******************************************************************************/
