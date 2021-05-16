/*
 * Employee.h
 *
 *  Created on: 15 may. 2021
 *      Author: Ezequiel
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

//#ifndef EMPLEADOS_H_INCLUDED
//#define EMPLEADOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}eEmployee;

/** \brief
 *
 * \param lista[] eEmployee
 * \param tam int
 * \return int
 *
 */
int mostrarEmpleados(eEmployee lista[],int tam);
/** \brief
 *
 * \param unEmpleado eEmployee
 * \return void
 *
 */
void mostrarEmpleado(eEmployee unEmpleado);
/** \brief
 *
 * \param lista[] eEmployee
 * \param tam int
 * \return void
 *
 */
void ordenarEmpleados(eEmployee lista[], int tam);
/** \brief
 *
 * \param lista[] eEmployee
 * \param tam int
 * \return void
 *
 */
void inicializarEmpleados(eEmployee lista[], int tam);
/** \brief
 *
 * \param lista[] eEmployee
 * \param tam int
 * \param pId int*
 * \return int
 *
 */
int eEmpleado_Alta(eEmployee lista[], int tam, int* pId);
/** \brief
 *
 * \return int
 *
 */
int menu();
/** \brief
 *
 * \param eEmployee[]
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eEmployee[], int tam);
/** \brief
 *
 * \param lista[] eEmployee
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarEmpleado(eEmployee lista[], int tam, int id);
/** \brief
 *
 * \param lista[] eEmployee
 * \param tam int
 * \return int
 *
 */
int bajaEmpleado(eEmployee lista[], int tam);

//#endif

#endif /* EMPLOYEE_H_ */
