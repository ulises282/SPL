#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los libros desde el archivo libros.csv (modo texto).
 *
 * \param FILE* pFile:  Direccion donde se tomaran los datos.
 * \param LinkedList* pArrayList:  Lista donde se guardaran los datos.
 *
 * \return int:  Retorno -1 en caso de error o puntero nulo.
 * 				 Retorno 1 en caso de parseo exitoso.
 */
int parser_libroFromText(FILE* pFile , LinkedList* pArrayList);


/** \brief Parsea los datos los datos de las editoriales desde el archivo editoriales.csv (modo texto).
 *
 * \param FILE* pFile:  Direccion donde se tomaran los datos.
 * \param LinkedList* pArrayList:  Lista donde se guardaran los datos.
 *
 * \return int:  Retorno -1 en caso de error o puntero nulo.
 * 				 Retorno 1 en caso de parseo exitoso.
 */
int parser_editorialFromText(FILE* pFile , LinkedList* pArrayList);

#endif /* PARSER_H_ */
