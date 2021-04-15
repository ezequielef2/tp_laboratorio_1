#include <stdio.h>
#include <stdlib.h>
#include "hmatematicas.h"

int sumar(int a, int b){   //sumarV4 2 int
    return a+b;
}

int restar(int a, int b){  //restar 2 int
    return a-b;
}

int multiplicar(int a, int b){  //multiplicar 2 int
    return a*b;
}

float dividir(int a, int b){  //dividir 2 float
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
