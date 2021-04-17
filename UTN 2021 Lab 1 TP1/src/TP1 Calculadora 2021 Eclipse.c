/*
 ============================================================================
 Name        : TP1.c
 Author      : EZEQUIEL ESTEBAN FERNANDEZ    1G
 Version     : 1.1
 Copyright   : Your copyright notice         © 2021
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "hmatematicas.h"

int main() {

	setbuf(stdout,NULL);
    char seguir = 's';
    char confirma;
    float numA;
    float numB;
    int opcion;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicar;
    float resultadoDividir;
    long long int resultadoFactorialA;
    long long int resultadoFactorialB;

    do
    {
        system("cls");    //system("clear"); para Linux
        printf("    ***MENU DE OPCIONES***\n\n");
        if(!flag1){
                printf("\n 1. Ingresar 1er Operando (A=x)");
        }
        else{
            printf("\n 1. Ingresar 1er Operando (A=%.2f)", numA);
            }
        if(!flag2){
                printf("\n 2. Ingresar 2do Operando (B=y)");
        }
        else{
            printf("\n 2. Ingresar 2do Operando (B=%.2f)", numB);
        }
        printf("\n 3. Calcular todas las operaciones ");
        printf("\n  a) Calcular la suma (A+B)");
        printf("\n  b) Calcular la resta (A-B)");
        printf("\n  c) Calcular la division (A/B)");
        printf("\n  d) Calcular la multiplicacion (A*B)");
        printf("\n  e) Calcular el factorial (A!) y (B!)");
        printf("\n 4. Informar resultados ");
        printf("\n 5. Salir ");
        printf("\n\n");
        printf("\n Ingrese Opcion: ");
        scanf("%d", &opcion);
        while(opcion > 5 || opcion < 0)
        {
                printf("\nOpcion invalida, reingrese una opcion entre 1, 2, 3, 4 o 5: \n");
                scanf("%d", &opcion);
        }

        switch(opcion)
        {
			case 1 :
				system("cls");
				printf("\n1. Ingresar 1er Operando (A=x): ");
				scanf("%f", &numA);
				flag1 = 1;
				break;
			case 2 :
					if(flag1)
					{
						system("cls");
						printf("\n2. Ingresar 2do Operando (B=y): ");
						scanf("%f", &numB);
						flag2 = 1;
					}
					else
					{
						printf("\nAntes debes ingresar el primer operando\n");
						printf("\n");
						system("pause");
					}
				break;
			case 3 :
					if(!flag1 || (flag1 && !flag2))
					{
						printf("\nPrimero debes ingresar ambos operandos\n");
					}
					else
					{
							resultadoSuma = sumar(numA, numB);
							resultadoResta = restar(numA, numB);
							resultadoDividir = dividir(numA, numB);
							resultadoMultiplicar = multiplicar(numA, numB);
							resultadoFactorialA = factorial(numA);
							resultadoFactorialB = factorial(numB);
							printf("\n3. Operaciones realizadas\n");
							flag1 = 0;
							flag2 = 0;
							flag3 = 1;
							}
				printf("\n");
				system("pause");
				break;
			case 4 :
				if(flag3 == 1)
				{
					mostrar(numA, numB, resultadoSuma, resultadoResta, resultadoDividir, resultadoMultiplicar, resultadoFactorialA, resultadoFactorialB);
				}
				else
				{
					printf("\nPrimero debes calcular las operaciones\n");
				}
				flag3 = 0;
				printf("\n");
				system("pause");
				break;
			case 5 :
					printf("\nConfirma salida?\n");
					printf("\nPresione 's' para salir o cualquier caracter para continuar\n");
				fflush(stdin);
				confirma = getch();
				if(confirma == 's')
				{
					seguir = 'n';
				}
				break;

          }

    }while(seguir == 's');


    return EXIT_SUCCESS;

}
