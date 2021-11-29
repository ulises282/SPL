#ifndef LIBROS_H_
#define LIBROS_H_
typedef struct
{
	int id;//PK
	char titulo[51];
	char autor[51];
	float precio;
	int idEditorial;//FK a editoriales.
}eLibro;

/** \brief Crea una variable del tipo eLibro y la guarda en memoria dinamica.
 *
 *  \param void
 *
 *  \return eEditorial*: Retorna la direccion de memoria de la variable creada
 */
eLibro* libro_new();


/** \brief	Crea una variable del tipo eLibro (la guarda en memoria dinamica)
 *  y le asigna los valores pasados como parametro.
 *
 *  \param char* id: id del libro.
 *  \param char* titulo: titulo del libro.
 *  \param char* autor: autro del libro.
 *  \param char* precio: precio del libro.
 *  \param char* idEditorial: id de la editorial del libro.
 *
 *  \return eEditorial*: Retorna la direccion de memoria de la variable creada.
 */
eLibro* libro_newParametros(char* id,char* titulo,char* autor,char* precio,char* idEditorial);


/** \brief	Setea el valor del campo id de eLibro* this por el valor int id
 *
 *  \param eLibro* this: Variable a la cual le setearemos el campo id.
 *  \param int id: valor que tomara this en el campo id.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al setear.
 */
int libro_setId(eLibro* this,int id);


/** \brief	Toma el valor del campo id de la variable this y lo retorna por int* id
 *
 *  \param eLibro* this: Variable de la cual tomaremos el valor del campo id.
 *  \param int* id: Variable por la cual retornaremos el id.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al tomar el valor.
 */
int libro_getId(eLibro* this,int* id);


/** \brief	Setea el valor del campo titulo de eLibro* this por el valor char* titulo
 *
 *  \param eLibro* this: Variable a la cual le setearemos el campo titulo.
 *  \param char* titulo: valor que tomara this en el campo titulo.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al setear.
 */
int libro_setTitulo(eLibro* this,char* titulo);


/** \brief	Toma el valor del campo titulo de la variable this y lo retorna por char* titulo
 *
 *  \param eLibro* this: Variable de la cual tomaremos el valor del campo titulo.
 *  \param char* titulo: Variable por la cual retornaremos el titulo.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al tomar el valor.
 */
int libro_getTitulo(eLibro* this,char* titulo);


/** \brief	Setea el valor del campo autor de eLibro* this por el valor char* autor.
 *
 *  \param eLibro* this: Variable a la cual le setearemos el campo autor.
 *  \param char* autor: valor que tomara this en el campo autor.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al setear.
 */
int libro_setAutor(eLibro* this,char* autor);


/** \brief	Toma el valor del campo autor de la variable this y lo retorna por char* autor
 *
 *  \param eLibro* this: Variable de la cual tomaremos el valor del campo autor.
 *  \param char* autor: Variable por la cual retornaremos el autor.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al tomar el valor.
 */
int libro_getAutor(eLibro* this,char* autor);


/** \brief	Setea el valor del campo precio de eLibro* this por el valor float precio.
 *
 *  \param eLibro* this: Variable a la cual le setearemos el campo precio.
 *  \param float precio: valor que tomara this en el campo precio.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al setear.
 */
int libro_setPrecio(eLibro* this,float precio);


/** \brief	Toma el valor del campo precio de la variable this y lo retorna por float* precio
 *
 *  \param eLibro* this: Variable de la cual tomaremos el valor del campo precio.
 *  \param float* precio: Variable por la cual retornaremos el precio.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al tomar el valor.
 */
int libro_getPrecio(eLibro* this,float* precio);


/** \brief	Setea el valor del campo idEditorial de eLibro* this por el valor int idEditorial.
 *
 *  \param eLibro* this: Variable a la cual le setearemos el campo idEditorial.
 *  \param int idEditorial: valor que tomara this en el campo idEditorial.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al setear.
 */
int libro_setIdEditorial(eLibro* this,int idEditorial);


/** \brief	Toma el valor del campo idEditorial de la variable this y lo retorna por int* idEditorial
 *
 *  \param eLibro* this: Variable de la cual tomaremos el valor del campo idEditorial.
 *  \param int* idEditorial: Variable por la cual retornaremos el idEditorial.
 *
 *  \return int:	Retorna -1 en caso de error o puntero nulo.
 *  				Retorna 0 en caso de exito al tomar el valor.
 */
int libro_getIdEditorial(eLibro* this,int* idEditorial);

/** \brief  Compara dos variables.
 *
 * 	\param void* param1: variable 1.
 * 	\param void* param2: variable 2.
 *
 * 	\return int:	Retorna 0 en caso de valores iguales.
 * 					Retorna diferente de 0 si las variables son distintas.
 */
int libro_CompareByAutor(void* param1, void* param2);

/** \brief Recibe una variable y filtra las que tengan como editorial a Mnotauro.
 *
 * \param void* this: variable a filtrar.
 *
 * \return int:	Retorna 1 en caso de que la variable tenga como editorial a Minotauro.
 * 				Retorna 0 en caso de error o la variable no tiene como editorial a Minotauro.
 */
int libro_filtrarMinotauro(void* this);


/**brief	Aplica un descuento en el precio de 20% a los libros de la editorial planeta y 10% en la editorial
 * Siglo XXI editores.
 *
 *\param void* this: lista de los libros a procesar.
 *
 *\return int:	Retorna 0 en caso de puntero nulo.
 *				Retorna 1 en caso contrario.
 *
 */
int libro_Mapeado(void* this);
#endif /* LIBROS_H_ */
