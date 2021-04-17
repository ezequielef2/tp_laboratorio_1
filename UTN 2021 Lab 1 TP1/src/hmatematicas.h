#ifndef H_MATEMATICAS_H_INCLUDED
#define H_MATEMATICAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>



#endif // H_MATEMATICAS_H_INCLUDED

/** \brief       sumar dos parametros flotantes "a" y "b"          sumar 2 flot
 *
 * \param a float  parametro flotante "a"
 * \param b float  parametro flotante "b"
 * \return float   resultado flotante "a+b"
 *
 */
float sumar(float a, float b);

/** \brief       restar dos parametros flotantes "a" y "b"          restar 2 flot
 *
 * \param a float  parametro flotante "a"
 * \param b float  parametro flotante "b"
 * \return float   resultado flotante "a-b"
 *
 */
float restar(float a, float b);
/** \brief       multiplicar dos parametros flotantes "a" y "b"          multiplicar 2 flot
 *
 * \param a float  parametro flotante "a"
 * \param b float  parametro flotante "b"
 * \return float   resultado flotante "a*b"
 *
 */
float multiplicar(float a, float b);
/** \brief       dividir dos parametros flotantes "a" y "b"          dividir 2 flot
 *
 * \param a float  dividendo flotante "a"
 * \param b float  divisor flotante "b"
 * \return float   resultado flotante "a/b"
 *
 */
float dividir(float a, float b);
/** \brief                factorial de un entero entre "0" y "12" inclusive          factorial hasta 12
 *
 * \param n int           entero "n"
 * \return long long int  resultado factorial de "n"
 *
 */
long long int factorial(int n);
/** \brief                                    mostrar los resultados de las operaciones solicitadas en opcion 4.
 *
 * \param numA float                          primer operando flotante "a"
 * \param numB float                          segundo operando flotante "b"
 * \param resultadoSuma float                 muestra resultado flotante de funcion sumar
 * \param resultadoResta float                muestra resultado flotante de funcion restar
 * \param resultadoDividir float              muestra resultado flotante de funcion dividir
 * \param resultadoMultiplicar float          muestra resultado flotante de funcion multiplicar
 * \param resultadoFactorialA long longint    muestra resultado entero de funcion factorial de "a"
 * \param resultadoFactorialB long longint    muestra resultado entero de funcion factorial de "b"
 * \return void                               tipo de valor que devuelve esta funcion
 *
 */
void mostrar(float numA, float numB, float resultadoSuma, float resultadoResta,float resultadoDividir, float resultadoMultiplicar, long long int resultadoFactorialA, long long int resultadoFactorialB);



