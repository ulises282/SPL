#include "input.h"
/******************************************************************************/
int Get_Int(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno;
    retorno = -1;
    int numero;
    printf("%s",mensaje);
    do{
        if(IngresarNumero(&numero) == 0 && numero<=maximo && numero >= minimo)
        {
            *pResultado = numero;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s",mensajeError);
        }
    }while(retorno!=0);
    return retorno;
}
/******************************************************************************/
int IngresarNumero(int* pResultado)
{
    int retorno;
    retorno = -1;
    char buffer[64];
    if(pResultado!=NULL)
    {
        if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}
/******************************************************************************/
int esNumerica(char* cadena)
{
    int i;
    i = 0;
    int retorno = -1;
    if (cadena != NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i]> '9')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/******************************************************************************/
int myGets(char* cadena, int longitud)
{
    int retorno;
    retorno = -1;
    if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin); // LINUX-> __fpurge o WIN-> fflush
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
            retorno = 0;
        }
    }
    return retorno;
}
/******************************************************************************/
