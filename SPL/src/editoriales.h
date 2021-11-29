#ifndef EDITORIALES_H_
#define EDITORIALES_H_

typedef struct
{
	int idEditorial;//PK
	char nombre[51];
}eEditorial;

/** \brief Crea una variable del tipo eEditorial y la guarda en memoria dinamica.
 *
 *  \param void
 *
 *  \return eEditorial*: Retorna la direccion de memoria de la variable creada
 */
eEditorial* editorial_new();


/** \brief	Crea una variable del tipo eEditorial (la guarda en memoria dinamica)
 *  y le asigna los valores pasados como parametro.
 *
 *  \param char* idEditorial: id de la editorial.
 *  \param char* nombre: nombre de la editorial.
 *
 *  \return eEditorial*: Retorna la direccion de memoria de la variable creada.
 */
eEditorial* editorial_newParametros(char* idEditorial,char* nombre);


/** \brief	Setea el valor del campo idEditorial de eEditorial* this por el valor int idEditorial
 *
 *  \param eEditorial* this: Variable a la cual le setearemos el campo idEditorial.
 *  \param int idEditorial: valor que tomara this en el campo idEditorial.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al setear.
 */
int editorial_setIdEditorial(eEditorial* this,int idEditorial);


/** \brief	Toma el valor del campo idEditorial de la variable this y lo retorna por int* idEditorial
 *
 *  \param eEditorial* this: Variable de la cual tomaremos el valor del campo idEditorial.
 *  \param int* idEditorial: Variable por la cual retornaremos el idEditorial.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al tomar el valor.
 */
int editorial_getIdEditorial(eEditorial* this,int* idEditorial);


/** \brief	Setea el valor del campo nombre de eEditorial* this por el valor char* nombre
 *
 *  \param eEditorial* this: Variable a la cual le setearemos el campo nombre.
 *  \param int char* nombre: valor que tomara this en el campo nombre.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al setear.
 */
int editorial_setNombre(eEditorial* this,char* nombre);


/** \brief	Toma el valor del campo nombre de la variable this y lo retorna por char* nombre.
 *
 *  \param eEditorial* this: Variable de la cual tomaremos el valor del campo nombre.
 *  \param char* nombre: Variable por la cual retornaremos el nombre.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al tomar el valor.
 */
int editorial_getNombre(eEditorial* this,char* nombre);


/** \brief	Busca en la lista pasada como parametro un idEditorial que coincida con el parametro int idEditorial.
 *
 *  \param LinkedList* pArrayList: lista en la cual se realizara la busqueda.
 *  \param int idEditorial: idEditorial a buscar en la lista.
 *
 *  \return int:	Retorna el indice de la editorial buscada.
 */
int editorial_buscarPorId(LinkedList* pArrayList, int idEditorial);

#endif /* EDITORIALES_H_ */
