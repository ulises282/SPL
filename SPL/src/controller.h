#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief  Muestra el menu de opciones
 *
 *  \param void
 *  \return void
 */
void controller_menu();


/** \brief Carga los datos desde el archivo pasado como parametro para luego parsearlo (modo texto).
 *
 * \param char* path: direccion en donde se encuentra el archivo.
 * \param LinkedList* pArrayList: Lista donde se guardara los datos del archivo.
 * \param int estado: estado para saber si los datos son de libros o de editoriales.
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 1 en caso de exito al cargar los datos.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList,int estado);


/** \brief Muestra la Lista de libros con el nombre de la editorial.
 *
 * \param LinkedList* pArrayList:	lista de libros.
 * \param LinkedList* pArrayListEditorial:	lista de editoriales.
 *
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 1 en caso de exito al mostrar los datos.
 */
int controller_ListLibroConEditorial(LinkedList* pArrayList,LinkedList* pArrayListEditorial);


/** \brief Muestra la Lista de editoriales.
 *
 * \param LinkedList* pArrayList:	lista de editoriales.
 *
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 1 en caso de exito al mostrar los datos.
 */
int controller_ListEditoriales(LinkedList* pArrayList);


/** \brief Ordena los libros por autor.
 *
 * LinkedList* pArrayList: lista de libros, que se va a ordenar por autor.
 *
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 0 en caso de exito al ordenar.
 *
 */
int controller_sortLibros(LinkedList* pArrayList);


/** \brief Muestra la Lista de libros con la editorial minotauro y los guarda en una nueva LinkedList.
 *
 * \param LinkedList* pArrayList:	lista de libros.
 *
 * \return LinkedList:	Retorna NULL en caso de error.
 * 						Retorna Una nueva lista formada por los libros con editorial Minotauro.
 */
LinkedList* controller_ListadoMinotauro(LinkedList* pArrayList);


/** \brief Guarda los datos en el archivo pasado como parametro (modo texto).
 *
 * \param char* path: direccion donde se guardaran los datos.
 * \param LinkedList* pArrayList: lista donde se encuentran los datos a guardar.
 *
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 0 en caso de exito al guardar los datos.
 */
int controller_saveAsText(char* path , LinkedList* pArrayList);


/**brief	Crea una nueva LinkedList con los precios con descuento (editorial planeta 20% y
 * siglo XXI editores 10%)
 *
 * \param LinkedList* pArrayList:	Lista de libros para aplicar el descuento.
 *
 * \return LinkedList*:	Retorna NULL en caso de error.
 * 						Retorna Una nueva lista formada por los libros con editorial planeta y siglo XXI editores
 * 						con el descuento aplicado.
 */
LinkedList* controller_ListadoMapeado(LinkedList* pArrayList);
#endif /* CONTROLLER_H_ */
