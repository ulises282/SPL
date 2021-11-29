#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "editoriales.h"
/******************************************************************************/
eEditorial* editorial_new()
{
	eEditorial* pEditorial = NULL;
	pEditorial = malloc(sizeof(eEditorial));

	return pEditorial;
}
/******************************************************************************/
eEditorial* editorial_newParametros(char* idEditorial,char* nombre)
{
	eEditorial* editorial;
	editorial = editorial_new();

	if(editorial!=NULL)
	{
		editorial_setIdEditorial(editorial,atoi(idEditorial));//
		editorial_setNombre(editorial,nombre);
	}
	return editorial;
}
/******************************************************************************/
int editorial_setIdEditorial(eEditorial* this,int idEditorial)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && idEditorial>=0)
	{
		this->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int editorial_getIdEditorial(eEditorial* this,int* idEditorial)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int editorial_setNombre(eEditorial* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int editorial_getNombre(eEditorial* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int editorial_buscarPorId(LinkedList* pArrayList, int idEditorial)
{
	int retorno;
	retorno = -1;
	int len;
	int auxIdEditorial;
	eEditorial* auxEditorial;
	len = ll_len(pArrayList);
	if(pArrayList != NULL)
	{
		for(int i=0;i<len;i++)
		{
			auxEditorial = ll_get(pArrayList,i);
			editorial_getIdEditorial(auxEditorial,&auxIdEditorial);
			if(idEditorial == auxIdEditorial)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/******************************************************************************/
