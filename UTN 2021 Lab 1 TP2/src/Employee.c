/*
 * Employee.c
 *
 *  Created on: 15 may. 2021
 *      Author: Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

void mostrarEmpleado(eEmployee unEmpleado){

   printf("%0004d       %10s        %10s        %9.2f      %d\n",
            unEmpleado.id,
            unEmpleado.name,
            unEmpleado.lastName,
            unEmpleado.salary,
            unEmpleado.sector);
}

int mostrarEmpleados(eEmployee lista[],int tam){

    int flag = 1;
    printf("\nLIST OF EMPLOYEES:\n");
    printf("\n");
    printf("ID Number        Name        Surname        Salary        Sector\n");
    printf("\n");

    for(int i=0; i<tam; i++){
            if( !lista[i].isEmpty ){

                mostrarEmpleado(lista[i]);
                flag = 0;
            }
    }
    if(flag){
        printf("\n No hay empleados en la lista\n");
    }
    printf("\n\n");
}

void ordenarEmpleados(eEmployee lista[], int tam){

    eEmployee auxEmpleado;
    //ordenar por edad descendente
    for(int i=0; i < tam-1; i++){
        for(int j= i+1; j < tam; j++){
                //  ordena por sexo descendente y legajo ascendente:
            if(lista[i].sector < lista[j].sector || (lista[i].sector == lista[j].sector && lista[i].lastName > lista[j].lastName)){    // ordenar por nombre: if(strcmp(lista[i].nombre, lista[j].nombre)>0)   //  ordenar por edad: if(lista[i].edad < lista[j].edad)
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }
}

void inicializarEmpleados(eEmployee lista[], int tam){

    for(int i=0; i < tam; i++){
            lista[i].isEmpty = 1;
        }
}

int eEmpleado_Alta(eEmployee lista[], int tam, int* pId){

    int todoOk = 0;
    int indice;
    eEmployee nuevoEmpleado;

    if( lista != NULL && tam > 0 && pId != NULL ){

        system("cls");
        printf("* ALTA EMPLEADO *\n");
        printf("\nAsignando ID: %0004d\n", *pId);

        indice = buscarLibre(lista, tam);
        if (indice == -1){
            printf("\nNo hay espacio en el sistema\n");
        }
        else{
             nuevoEmpleado.id = *pId;

             printf("Ingrese NOMBRE: ");
             fflush(stdin);
             gets(nuevoEmpleado.name);

             printf("Ingrese APELLIDO: ");
             fflush(stdin);
             gets(nuevoEmpleado.lastName);

             printf("Ingrese SUELDO: ");
             scanf("%f", &nuevoEmpleado.salary);

             printf("Ingrese SECTOR: ");
             scanf("%d", &nuevoEmpleado.sector);

             nuevoEmpleado.isEmpty = 0;

             lista[indice] = nuevoEmpleado;
             // actualizamos el proximo Id:
             (*pId)++;

             todoOk = 1;
        }
    }

    return todoOk;
}

int menu(){

    int opc;
    system("cls");
    printf("\n*****     ABM: Menu de Inicio     *****\n");
    printf("\n\n");
    printf("OPCIONES:\n");
    printf("\n");
    printf("1.ALTA EMPLEADO\n");
    printf("2.BAJA EMPLEADO\n");
    printf("3.MODIFICAR EMPLEADO\n");
    printf("4.MOSTRAR LISTA EMPLEADOS\n");
    //printf("5.ORDENAR EMPLEADOS\n");
    printf("6.INFORMES\n");
    printf("7.SALIR\n");
    printf("\n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opc);

    return opc;
}

int buscarLibre(eEmployee lista[], int tam){
    int indice = -1;
    if( lista != NULL && tam > 0 ){
        for(int i=0; i<tam; i++){
            if( lista[i].isEmpty == 1){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int buscarEmpleado(eEmployee lista[], int tam, int id){
    int indice = -1;
    if( lista != NULL && tam > 0 ){
        for(int i=0; i<tam; i++){
            if( !lista[i].isEmpty && lista[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaEmpleado(eEmployee lista[], int tam){

    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    system("cls");
    printf("\n BAJA EMPLEADO\n");
    mostrarEmpleados(lista, tam);
    printf("\nIngrese NUMERO ID: ");
    scanf("%0004d", &id);

    indice = buscarEmpleado(lista, tam, id);

    if( indice == -1){
        fflush(stdin);
        printf("\n No existe ningun empleado con el numero Id %0004d\n", id);
    }
    else{
        mostrarEmpleado(lista[indice]);
        printf("\nConfirma baja? ");
        fflush(stdin);
        scanf("%c", &confirma);
        if( confirma == 's' ){
            lista[indice].isEmpty = 1;

            todoOk = 1;
        }
        else{
            printf("\nBaja cancelada por el usuario\n");
        }
    }
    return todoOk;
}

