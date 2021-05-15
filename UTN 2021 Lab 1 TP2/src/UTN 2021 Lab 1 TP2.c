/*
 ============================================================================
 Name        : UTN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleados.h"

#define TAM 1000

int main(void) {

setbuf(stdout,NULL);

	int criterioDeOrdenamiento;
	char seguir = 's';
	int opc;
	int nextId = 1;

	//CREO ARRAY DE ESTRUCTURA
	eEmpleado lista[TAM];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	inicializarEmpleados(lista, TAM);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		//Menu();


		//MENU SWITCH
		switch(menu()){

//		case 0:
//			/** PREGUNTAR SI DESEA SALIR */
//			opc = 0;
//			break;
		case 1:
			//ALTA EMPLEADO
			if (eEmpleado_Alta(lista, TAM, &nextId) == 1) {
				printf("\n* EMPLEADO DADO DE ALTA EXITOSAMENTE *\n");
			} else {
				printf("\n* ERROR. NO SE PUDO DAR EL ALTA *\n");
				printf("\n");
			}
			//system("pause");
			break;
		case 2:
			//BAJA EMPLEADO
			if (bajaEmpleado(lista, TAM) == 1) {
				printf("\n* EMPLEADO DADO DE BAJA EXITOSAMENTE *\n");
			} else {
				printf("\n* ERROR. NO SE PUDO DAR DE BAJA *\n");
				printf("\n");
			}
			//system("pause");
			break;
//		case 3:
//			//MODIFICACION
//			if (eEmpleado_Modificacion(eEmpleado, TAM_ESTRUCTURA)) {
//				puts("\n * MODIFICACION DE Producto EXITOSA\n");
//				eEmpleado_MostrarTodos(eEmpleado, TAM_ESTRUCTURA);
//			} else {
//				puts("\n * MODIFICACION DE Producto CANCELADA");
//			}
//			system("pause");
//			break;
		case 4:
			//LISTADO MOSTRAR EMPLEADOS
			if(mostrarEmpleados(lista, TAM) == 1){
				system("pause");
			}else{
				puts("\n* NO HAY NADA PARA MOSTRAR *\n");
			}

			break;
//		case 5:
//			//ORDENAR
//			criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
//			eEmpleado_Sort(eEmpleado, TAM_ESTRUCTURA, criterioDeOrdenamiento);
//			system("pause");
//			break;
        case 7:
            //SALIR
            seguir = 'n';
            break;

        default:
            printf("\n* OPCION INVALIDA *\n");
		}
        printf("\n");
		system("pause");

	} while(seguir == 's');

	puts("\n. . . FIN PROGRAMA");

	return 0;
}
