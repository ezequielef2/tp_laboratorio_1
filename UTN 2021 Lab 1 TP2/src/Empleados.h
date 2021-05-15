/*
 * Empleados.h
 *
 *  Created on: 15 may. 2021
 *      Author: Ezequiel
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int dia;
int mes;
int anio;
}eFecha;

typedef struct{
int legajo;
char nombre[20];
int edad;
char sexo;
float sueldo;
eFecha fechaIngreso;
int isEmpty;
}eEmpleado;

/** \brief
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return int
 *
 */
int mostrarEmpleados(eEmpleado lista[],int tam);
/** \brief
 *
 * \param unEmpleado eEmpleado
 * \return void
 *
 */
void mostrarEmpleado(eEmpleado unEmpleado);
/** \brief
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void ordenarEmpleados(eEmpleado lista[], int tam);
/** \brief
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado lista[], int tam);
/** \brief
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \param pId int*
 * \return int
 *
 */
int eEmpleado_Alta(eEmpleado lista[], int tam, int* pId);
/** \brief
 *
 * \return int
 *
 */
int menu();
/** \brief
 *
 * \param eEmpleado[]
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eEmpleado[], int tam);
/** \brief
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \param legajo int
 * \return int
 *
 */
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
/** \brief
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return int
 *
 */
int bajaEmpleado(eEmpleado lista[], int tam);


#endif /* EMPLEADOS_H_ */
