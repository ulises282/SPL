#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "editoriales.h"
#include "libros.h"
#include "input.h"
/******************************************************************************/
void controller_menu()
{
	printf("\t\t\tMENU\n"
	 "1. Leer archivo de libros.csv y guardarlo.\n"
     "2. Leer archivo de editoriales.csv. y guardarlo\n"
     "3. Ordenar lista de libros por autor.\n"
     "4. Imprimir lista de libros.\n"
     "5. Lista de libros de editorial MINOTAURO.\n"
	 "6. Lista de libros con descuento(editoriales Planeta y Siglo XXI editores)\n"
     "7. Salir.\n");
}

/******************************************************************************/
int controller_loadFromText(char* path , LinkedList* pArrayList,int estado)
{
	FILE* archivo;
	int retorno;
	retorno = -1;
	archivo = fopen(path, "r");
	if(archivo!=NULL)
	{
		if(estado == 1)
		{
			if(parser_libroFromText(archivo, pArrayList)==1)
			{
				retorno = 1;
			}
		}
		else
		{
			if(parser_editorialFromText(archivo, pArrayList)==1)
			{
				retorno = 1;
			}
		}
	}
	fclose(archivo);
	return retorno;
}
/******************************************************************************/
int controller_ListLibroConEditorial(LinkedList* pArrayList,LinkedList* pArrayListEditorial)
{
	int i;
	int retorno = -1;
	eLibro* aux;
	eEditorial* auxE;
	int auxId;
	char auxTitulo[51];
	char auxAutor[51];
	float auxPrecio;
	int auxIdEditorial;
	char auxNombre[51];

	int indexEditorial;
	if(pArrayList!=NULL && pArrayListEditorial != NULL)
	{
		retorno = 1;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("|%-6s |%-20s |%-20s |%10s| %25s|\n","ID","Titulo","Autor","Precio","Editorial");
		printf("-------------------------------------------------------------------------------------------\n");
		for (i = 0; i <  ll_len(pArrayList); i++)
		{
			aux =(eLibro*) ll_get(pArrayList, i);
			libro_getId(aux,&auxId);
			libro_getTitulo(aux,auxTitulo);
			libro_getAutor(aux,auxAutor);
			libro_getPrecio(aux,&auxPrecio);
			libro_getIdEditorial(aux,&auxIdEditorial);
			indexEditorial = editorial_buscarPorId(pArrayListEditorial,auxIdEditorial);
			auxE = (eEditorial*) ll_get(pArrayListEditorial,indexEditorial);
			editorial_getNombre(auxE,auxNombre);
			printf("|%-6d |%-20s |%-20s |%10.2f| %25s|\n", auxId, auxTitulo, auxAutor, auxPrecio, auxNombre);
		}
		printf("-------------------------------------------------------------------------------------------\n");
	}
	return retorno;
}
/******************************************************************************/
int controller_ListEditoriales(LinkedList* pArrayList)
{
	int i;
	int retorno = -1;
	eEditorial* aux;
	int auxIdEditorial;
	char auxNombre[51];
	if(pArrayList!=NULL)
	{
		retorno = 1;
		printf("%-6s %-20s\n","ID","Nombre");
		for (i = 0; i <  ll_len(pArrayList); i++)
		{
			aux =(eEditorial*) ll_get(pArrayList, i);
			editorial_getIdEditorial(aux,&auxIdEditorial);
			editorial_getNombre(aux,auxNombre);
			printf("%-6d %-20s\n", auxIdEditorial, auxNombre);
		}
	}
	return retorno;
}
/******************************************************************************/
int controller_sortLibros(LinkedList* pArrayList)
{
	int retorno;
	retorno = -1;
	if(ll_sort(pArrayList,libro_CompareByAutor,1) == 0)
	{
		retorno = 0;
	}
    return retorno;
}
/******************************************************************************/
LinkedList* controller_ListadoMinotauro(LinkedList* pArrayList)
{
	LinkedList* nuevaLista;
	nuevaLista = ll_filter(pArrayList,libro_filtrarMinotauro);
	return nuevaLista;
}
/******************************************************************************/
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int retorno;
	retorno = -1;
	FILE* archivo;
	eLibro* aux;
	int i;
	int auxId;
	char auxTitulo[51];
	char auxAutor[51];
	float auxPrecio;
	int auxIdEditorial;
	archivo = fopen(path,"w");
	if(archivo!=NULL)
	{
		fprintf(archivo,"id,titulo,autor,precio,idEditorial\n");
		for(i=0;i<ll_len(pArrayList);i++)
		{
			aux =(eLibro*) ll_get(pArrayList, i);
			libro_getId(aux,&auxId);
			libro_getTitulo(aux,auxTitulo);
			libro_getAutor(aux,auxAutor);
			libro_getPrecio(aux,&auxPrecio);
			libro_getIdEditorial(aux,&auxIdEditorial);
			fprintf(archivo,"%d,%s,%s,%f,%d\n",auxId,auxTitulo,auxAutor,auxPrecio,auxIdEditorial);
		}
		fclose(archivo);
		retorno = 0;
	}
	fclose(archivo);
    return retorno;
}
/******************************************************************************/
LinkedList* controller_ListadoMapeado(LinkedList* pArrayList)
{
	LinkedList* nuevaLista;
	nuevaLista = ll_map(pArrayList,libro_Mapeado);
	return nuevaLista;
}
/******************************************************************************/
