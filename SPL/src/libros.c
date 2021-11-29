#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "libros.h"
/******************************************************************************/
eLibro* libro_new()
{
	eLibro* pLibro = NULL;
	pLibro = malloc(sizeof(eLibro));

	return pLibro;
}
/******************************************************************************/
eLibro* libro_newParametros(char* id,char* titulo,char* autor,char* precio,char* idEditorial)
{
	eLibro* libro;
	libro = libro_new();

	if(libro!=NULL)
	{
		libro_setId(libro,atoi(id));//
		libro_setTitulo(libro,titulo);
		libro_setAutor(libro,autor);
		libro_setPrecio(libro,atof(precio));
		libro_setIdEditorial(libro,atoi(idEditorial));
	}
	return libro;
}
/******************************************************************************/
int libro_setId(eLibro* this,int id)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && id>=0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int libro_getId(eLibro* this,int* id)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && titulo!=NULL)
	{
		strcpy(this->titulo, titulo);
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		strcpy(titulo, this->titulo);
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int libro_setAutor(eLibro* this,char* autor)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && autor!=NULL)
	{
		strcpy(this->autor, autor);
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int libro_getAutor(eLibro* this,char* autor)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		strcpy(autor, this->autor);
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int libro_setPrecio(eLibro* this,float precio)
{
	int retorno;
	retorno = -1;
	if(this!= NULL && precio>=0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int libro_getPrecio(eLibro* this,float* precio)
{
	int retorno;
	retorno = -1;
	if(this!= NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************/
int libro_setIdEditorial(eLibro* this,int idEditorial)
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
int libro_getIdEditorial(eLibro* this,int* idEditorial)
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
int libro_CompareByAutor(void* param1, void* param2)
{
	int retorno;
	retorno = -1;
	char auxAutor1[51];
	char auxAutor2[51];
	if(param1 != NULL && param2 != NULL)
	{
		libro_getAutor((eLibro*)param1,auxAutor1);
		libro_getAutor((eLibro*)param2,auxAutor2);
		retorno = strcmp(auxAutor1,auxAutor2);
	}
	return retorno;
}
/******************************************************************************/
int libro_filtrarMinotauro(void* this)
{
	int retorno;
	retorno = 0;
	int auxIdEditorial;
	libro_getIdEditorial((eLibro*)this,&auxIdEditorial);
	if(auxIdEditorial == 4)
	{
		retorno = 1;
	}
	return retorno;
}
/******************************************************************************/
int libro_Mapeado(void* this)
{
	int retorno;
	retorno = 0;
	int auxIdEditorial;
	float auxPrecio;
	libro_getIdEditorial((eLibro*)this,&auxIdEditorial);
	if(auxIdEditorial == 1 || auxIdEditorial == 2)
	{
		libro_getPrecio((eLibro*)this,&auxPrecio);
		switch(auxIdEditorial)
		{
		case 1:
			if(auxPrecio>=300)
			{
				auxPrecio = auxPrecio * 0.80;
			}
			break;

		case 2:
			if(auxPrecio>=200)
			{
				auxPrecio = auxPrecio * 0.90;
			}
			break;
		}
		libro_setPrecio((eLibro*)this,auxPrecio);
		retorno = 1;
	}
	return retorno;
}
/******************************************************************************/
