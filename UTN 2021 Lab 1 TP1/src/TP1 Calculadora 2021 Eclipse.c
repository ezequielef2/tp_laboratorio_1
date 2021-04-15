/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "hmatematicas.h"

int main(void) {

	setbuf(stdout,NULL);
    char seguir = 's';
    char confirma;
    int numA;
    int numB;
    char opcion;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicar;
    float resultadoDividir;
    long long int resultadoFactorial;

    do
    {
        system("cls");    //system("clear"); para Linux
        printf("    ***MENU DE OPCIONES***\n\n");
        if(!flag1){
                printf("\n 1. Ingresar 1er Operando (A=x)");
        }
        else{
            printf("\n 1. Ingresar 1er Operando (A=%d)", numA);
        }
        if(!flag2){
                printf("\n 2. Ingresar 2do Operando (B=y)");
        }
        else{
            printf("\n 2. Ingresar 2do Operando (B=%d)", numB);
        }
        printf("\n 3. Calcular todas las operaciones ");
        printf("\n  a) Calcular la suma (A+B)");
        printf("\n  b) Calcular la resta (A-B)");
        printf("\n  c) Calcular la division (A/B)");
        printf("\n  d) Calcular la multiplicacion (A*B)");
        printf("\n  e) Calcular el factorial (A!)");
        printf("\n 4. Informar resultados ");
        printf("\n 5. Salir ");
        printf("\n\n");
        printf("\n Ingrese Opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
        case'1':
            system("cls");
            printf("\n1. Ingresar 1er Operando (A=x): ");
            scanf("%d", &numA);
            flag1 = 1;
            break;
        case'2':
                if(flag1)
                {
                    system("cls");
                    printf("\n2. Ingresar 2do Operando (B=y): ");
                    scanf("%d", &numB);
                    flag2 = 1;
                }
                else
                {
                    printf("\nAntes debes ingresar el primer operando\n");
                    printf("\n");
                    system("pause");
                }
            break;
        case'3':
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
                        resultadoFactorial = factorial(numA);
                        printf("\n3. Operaciones realizadas\n");
                        flag1 = 0;
                        flag2 = 0;
                        flag3 = 1;
                        }
            printf("\n");
            system("pause");
            break;
        case'4':
            if(flag3 == 1){
                printf("\n4. Los resultados son: ");
                printf("\n El resultado de A+B es: %d", resultadoSuma);
                printf("\n El resultado de A-B es: %d", resultadoResta);
                if(numB != 0){
                        printf("\n El resultado de A/B es: %.2f", resultadoDividir);
                }
                else{
                    printf("\n El resultado de A/B es: No es posible efectuar la division por cero");
                }
                printf("\n El resultado de A*B es: %d", resultadoMultiplicar);
                if(numA < 0){
                    printf("\n El factorial de A!  es: No es posible efectuar factorial de un numero menor a cero");
                    printf("\n");
                }
                else if(numA > 12){
                    printf("\n El factorial de A!  es: No es posible efectuar factorial de un numero mayor a 12");
                    printf("\n");
                }
                else{
                    printf("\n El factorial de A!  es: %I64u.00", resultadoFactorial);
                    printf("\n");
                }
                flag3 = 0;
            }
            else{
                printf("\nPrimero debes calcular las operaciones\n");
            }
            printf("\n");
            system("pause");
            break;
        case'5':
                printf("\nConfirma salida?\n");
                printf("\nPresione 's' para salir o cualquier caracter para continuar\n");
            fflush(stdin);
            confirma = getch();
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\nOpcion invalida!\n");
            printf("\n");
            system("pause");
        }

    }

    while(seguir == 's');
    return EXIT_SUCCESS;

}
