#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**\brief	Ingresa un valor lo valida y lo retorna.
 *
 * \param int* pResultado: puntero por el cual se retorna el valor.
 * \param char* mensaje: mensaje para ingresar valor.
 * \param char* mensajeError: mensaje de error para reingresar valor.
 * \param int minimo: valor minimo que debe tener el valor ingresado.
 * \param int maximo: valor maximo que debe tener el valor ingresado.
 *
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 0 en caso de exito al ingresar valor.
 */
int Get_Int(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);


/**\brief	Ingresa una cadena valida que sean numeros lo transforma a entero y lo retorna
 *
 * \param int* pResultado: puntero por el cual se retorna el valor ingresado
 *
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 0 en caso de exito al ingresar y validar el numero.
 */
int IngresarNumero(int* pResultado);


/**\brief	Toma una cadena y valida que sea numerica
 *
 * \param char* cadena: cadena a validar
 *
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 0 en caso de que la cadena sea numerica.
 */
int esNumerica(char* cadena);


/**\brief	Pide una cadena y la retorna por char* cadena
 *
 * \param char* cadena: puntero para retornar la cadena ingresada
 * \param int longitud: longitud que debe tener como maximo la cadena
 *
 * \return int:	Retorna -1 en caso de error o puntero nulo.
 * 				Retorna 0 en caso de exito al ingresar valor.
 */
int myGets(char* cadena, int longitud);

#endif /* INPUT_H_ */
