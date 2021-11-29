/*
 ============================================================================
 Nombre        : SPL.c
 Autor         : Gomez, Alejandro Ulises.
 Materia       : Laboratorio 1.
 ============================================================================
 */
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "libros.h"
#include "editoriales.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();
	LinkedList* listaEditorialMinotauro;
	LinkedList* listaMapeada;
	int estadoMenu;
	estadoMenu = 0;
	do
	{
		controller_menu();
		Get_Int(&opcion,"Ingrese una opcion: ","ERROR, ",1,7);
		switch(opcion)
		{
		case 1:
			if(controller_loadFromText("libros.csv",listaLibros,1)==1)
			{
				printf("Los datos se cargaron con exito\n");
				estadoMenu = 1;
			}
			else
			{
				printf("Error al cargar los datos\n");
			}
			break;

		case 2:
			if(controller_loadFromText("editoriales.csv",listaEditoriales,2)==1)
			{
				printf("Los datos se cargaron con exito\n");
				estadoMenu = 2;
			}
			else
			{
				printf("Error al cargar los datos\n");
			}
			break;

		case 3:
			if(estadoMenu == 2)
			{
				if(controller_sortLibros(listaLibros) == 0)
				{
					printf("Ordenamiento exitoso\n");
				}
				else
				{
					printf("Error al ordenar\n");
				}
			}
			else
			{
				printf("primero cargue los datos de libros y editoriales\n");
			}

			break;

		case 4:
			if(estadoMenu == 2)
			{
				controller_ListLibroConEditorial(listaLibros,listaEditoriales);
			}
			else
			{
				printf("primero cargue los datos de libros y editoriales\n");
			}
			break;

		case 5:
			if(estadoMenu == 2)
			{
				listaEditorialMinotauro = controller_ListadoMinotauro(listaLibros);
				controller_ListLibroConEditorial(listaEditorialMinotauro,listaEditoriales);
				controller_saveAsText("EditorialMinotauro.csv",listaEditorialMinotauro);
			}
			else
			{
				printf("primero cargue los datos de libros y editoriales\n");
			}

			break;

		case 6:
			if(estadoMenu == 2)
			{
				listaMapeada = controller_ListadoMapeado(listaLibros);
				controller_ListLibroConEditorial(listaMapeada,listaEditoriales);
				controller_saveAsText("mapeado.csv",listaMapeada);
			}
			else
			{
				printf("primero cargue los datos de libros y editoriales\n");
			}
			break;

		case 7:
			break;
		}
	}while(opcion!=7);

	return EXIT_SUCCESS;
}
