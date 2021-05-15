/*
 * Empleados.c
 *
 *  Created on: 15 may. 2021
 *      Author: Ezequiel
 */

#include "Empleados.h"

void mostrarEmpleado(eEmpleado unEmpleado){

   printf("%d    %10s     %d     %c    %9.2f   %02d/%02d/%d\n",
            unEmpleado.legajo,
            unEmpleado.nombre,
            unEmpleado.edad,
            unEmpleado.sexo,
            unEmpleado.sueldo,
            unEmpleado.fechaIngreso.dia,
            unEmpleado.fechaIngreso.mes,
            unEmpleado.fechaIngreso.anio);
}

int mostrarEmpleados(eEmpleado lista[],int tam){

    int flag = 1;
    printf("    Lista de Empleados\n");
    printf("Legajo    Nombre    Edad    Sexo    Sueldo    Fecha Ingreso\n");
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

void ordenarEmpleados(eEmpleado lista[], int tam){

    eEmpleado auxEmpleado;
    //ordenar por edad descendente
    for(int i=0; i < tam-1; i++){
        for(int j= i+1; j < tam; j++){
                //  ordena por sexo descendente y legajo ascendente:
            if(lista[i].sexo < lista[j].sexo || (lista[i].sexo == lista[j].sexo && lista[i].legajo > lista[j].legajo)){    // ordenar por nombre: if(strcmp(lista[i].nombre, lista[j].nombre)>0)   //  ordenar por edad: if(lista[i].edad < lista[j].edad)
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }
}

void inicializarEmpleados(eEmpleado lista[], int tam){

    for(int i=0; i < tam; i++){
            lista[i].isEmpty = 1;
        }
}

int eEmpleado_Alta(eEmpleado lista[], int tam, int* pId){

    int todoOk = 0;
    int indice;
    eEmpleado nuevoEmpleado;

    if( lista != NULL && tam > 0 && pId != NULL ){

        system("cls");
        printf("* ALTA EMPLEADO *\n");
        printf("\nASIGNANDO LEGAJO: %d\n", *pId);

        indice = buscarLibre(lista, tam);
        if (indice == -1){
            printf("\nNo hay espacio en el sistema\n");
        }
        else{
             nuevoEmpleado.legajo = *pId;

             printf("Ingrese NOMBRE: ");
             fflush(stdin);
             gets(nuevoEmpleado.nombre);

             printf("Ingrese EDAD: ");
             scanf("%d", &nuevoEmpleado.edad);

             printf("Ingrese SEXO: f o m ");
             fflush(stdin);
             scanf("%c", &nuevoEmpleado.sexo);

             printf("Ingrese SUELDO: ");
             scanf("%f", &nuevoEmpleado.sueldo);

             printf("Ingrese fecha de INGRESO  dd/mm/aaaa: ");
             scanf("%d/%d/%d", &nuevoEmpleado.fechaIngreso.dia,
                               &nuevoEmpleado.fechaIngreso.mes,
                               &nuevoEmpleado.fechaIngreso.anio);

             nuevoEmpleado.isEmpty = 0;
             //if(flagNombre && flagEdad && flagSexo);
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
    printf("5.ORDENAR EMPLEADOS\n");
    printf("6.INFORMES\n");
    printf("7.SALIR\n");
    printf("\n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opc);

    return opc;
}

int buscarLibre(eEmpleado lista[], int tam){
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

int buscarEmpleado(eEmpleado lista[], int tam, int legajo){
    int indice = -1;
    if( lista != NULL && tam > 0 ){
        for(int i=0; i<tam; i++){
            if( !lista[i].isEmpty && lista[i].legajo == legajo){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaEmpleado(eEmpleado lista[], int tam){

    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    system("cls");
    printf("\n BAJA EMPLEADO\n");
    mostrarEmpleados(lista, tam);
    printf("\nIngrese LEGAJO: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1){
        printf("\n No existe un empleado con el legajo %d\n", &legajo);
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

