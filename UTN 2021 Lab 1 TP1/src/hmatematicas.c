#include <stdio.h>
#include <stdlib.h>
#include "hmatematicas.h"

float sumar(float a, float b){   //sumarV4 2 float
    return a+b;
}

float restar(float a, float b){  //restar 2 float
    return a-b;
}

float multiplicar(float a, float b){  //multiplicar 2 float
    return a*b;
}

float dividir(float a, float b){  //dividir 2 float
    float rta;
    if( b != 0){
        rta = (float) a/b;
    }
    return rta;
}

long long int factorial(int n){  //factorial hasta 12
    long long int fact = 1;
    for(int i = 1; i <= n; i++){
        fact = fact*i;
    }
    return fact;
}

void mostrar(float numA, float numB, float resultadoSuma, float resultadoResta, float resultadoDividir, float resultadoMultiplicar, long long int resultadoFactorialA, long long int resultadoFactorialB)
{

        printf("\n4. Los resultados son: ");
        printf("\n El resultado de A+B es: %.2f", resultadoSuma);
        printf("\n El resultado de A-B es: %.2f", resultadoResta);
        if(numB != 0)
        {
                printf("\n El resultado de A/B es: %.2f", resultadoDividir);
        }
        else
        {
            printf("\n El resultado de A/B es: No es posible efectuar la division por cero");
        }
        printf("\n El resultado de A*B es: %.2f", resultadoMultiplicar);
        if(numA < 0)
        {
            printf("\n El factorial de A!  es: No es posible efectuar factorial de un numero menor a cero");
        }
        else if(numA > 12){
            printf("\n El factorial de A!  es: No es posible efectuar factorial de un numero mayor a 12");
        }
        else{
            printf("\n El factorial de A!  es: %I64u.00", resultadoFactorialA);
        }
        if(numB < 0)
		{
			printf("\n El factorial de B!  es: No es posible efectuar factorial de un numero menor a cero");
			printf("\n");
		}
		else if(numB > 12){
			printf("\n El factorial de B!  es: No es posible efectuar factorial de un numero mayor a 12");
			printf("\n");
		}
		else{
			printf("\n El factorial de B!  es: %I64u.00", resultadoFactorialB);
			printf("\n");
		}
}
