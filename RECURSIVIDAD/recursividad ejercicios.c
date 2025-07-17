/*1. Diseñar un algoritmo recursivo que permita hacer la división por restas sucesivas*/
#include <stdio.h>

// Prototipos
int division(int num, int divisor);
int factorial(int num);

int main(){
    int num, dividendo, divisor;
    
    printf("ingrese el dividendo: \n");
    scanf("%d", &dividendo);
    
    printf("ingrese el divisor: \n");
    scanf("%d", &divisor);

    num = division(dividendo, divisor);
    printf("division es: %d\n", num);

    return 0;
}

// División por restas sucesivas recursiva
int division(int num, int divisor){
    if (divisor == 0) {
        return -1; // Manejo simple de división por cero
    }
    if (num < divisor){
        return 0;
    }
    return division(num - divisor, divisor) + 1;
}

// Factorial recursivo (extra ejemplo)
int factorial(int num){
    if(num == 0){
        return 1;
    }
    return num * factorial(num - 1);
}

/*2. Diseñar un algoritmo recursivo que permita invertir un número. Por ejemplo,
Entrada: 123 Salida: 321*/
#include <stdio.h>

// Prototipos
int invertirAux(int num, int invertido);
int invertir(int num);

int main(){
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);

    printf("El número invertido es: %d\n", invertir(num));
    return 0;
}

#include <stdio.h>

// Función auxiliar recursiva
int invertirAux(int num, int invertido) {
    int nuevoInvertido;
    if (num == 0)
        return invertido;
    nuevoInvertido = invertido * 10 + num % 10;
    return invertirAux(num / 10, nuevoInvertido);
}

// Función principal
int invertir(int num) {
    return invertirAux(num, 0);
}
/*3. Diseñar un algoritmo recursivo que permita sumar los dígitos de un número. Por
ejemplo, Entrada: 123 Resultado: 6.*/
#include <stdio.h>

// Prototipos
int sumaDigitos(int num);

int main(){
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);

    int suma = sumaDigitos(num);
    printf("La suma de los dígitos es: %d\n", suma);
    return 0;

}

// Función recursiva para sumar los dígitos de un número
int sumaDigitos(int num) {
    if (num == 0)
        return 0;
    int digito = num % 10;
    return digito + sumaDigitos(num / 10);
}

/*7. Diseñar un algoritmo recursivo que nos permita obtener el determinante de una
matriz cuadrada de dimensión n*/
#include <stdio.h>
#include <stdlib.h>

// Copia la matriz sin la fila y columna indicadas (sin usar continue)
void copiarSinFilaColumna(int n, int matriz[][10], int nueva[][10], int excluirFila, int excluirCol) {
    int ni = 0;
    for (int i = 0; i < n; i++) {
        if (i != excluirFila) {
            int nj = 0;
            for (int j = 0; j < n; j++) {
                if (j != excluirCol) {
                    nueva[ni][nj] = matriz[i][j];
                    nj++;
                }
            }
            ni++;
        }
    }
}

int determinante(int n, int matriz[][10]) {
    if (n == 1) {
        return matriz[0][0];
    }
    if (n == 2) {
        return matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];
    }
    int total = 0;
    int signo = 1;
    int submatriz[10][10];

    for (int f = 0; f < n; f++) {
        copiarSinFilaColumna(n, matriz, submatriz, 0, f);
        total = total + signo * matriz[0][f] * determinante(n-1, submatriz);
        signo = -signo;
    }
    return total;
}

int main() {
    int n, i, j;
    int matriz[10][10];
    printf("Ingrese el tamaño (n) de la matriz cuadrada (máx 10): ");
    scanf("%d", &n);
    printf("Ingrese los números de la matriz, fila por fila:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);

    printf("El determinante es: %d\n", determinante(n, matriz));
    return 0;
}

/*8. Cargar un vector con n elementos enteros y calcular la suma de sus elementos en
forma recursiva*/
#include <stdio.h>

// Función recursiva para sumar los elementos de un vector
int suma(int v[], int n) {
    if (n == 0)
        return 0;
    else
        return v[n-1] + suma(v, n-1);
}

int main() {
    int n, i;
    int vec[100];

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    printf("Ingrese los elementos:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    int resultado = suma(vec, n);
    printf("La suma de los elementos es: %d\n", resultado);

    return 0;
}

/*9. Cargar un vector con n elementos enteros y calcular el promedio de sus elementos
en forma recursiva.*/
#include <stdio.h>

// Función recursiva para sumar los elementos del vector
int suma(int v[], int n) {
    if (n == 0)
        return 0;
    else
        return v[n-1] + suma(v, n-1);
}

// Función para calcular el promedio
double promedio(int v[], int n) {
    if (n == 0)
        return 0;
    return (double)suma(v, n) / n;
}

int main() {
    int n, i, vec[100];
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    printf("Ingrese los elementos:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &vec[i]);

    printf("El promedio es: %.2f\n", promedio(vec, n));
    return 0;
}
/*10. Cargar una matriz de n filas y n columnas, calcular y mostrar el elemento máximo
de cada fila en forma recursiva.*/
#include <stdio.h>

// Función recursiva para encontrar el máximo en una fila
int maxFila(int fila[], int n) {
    if (n == 1)
        return fila[0];
    int maxRestante = maxFila(fila, n-1);
    if (fila[n-1] > maxRestante)
        return fila[n-1];
    else
        return maxRestante;
}

int main() {
    int n, i, j;
    int matriz[20][20];

    printf("Ingrese la dimensión n de la matriz cuadrada (máx 20): ");
    scanf("%d", &n);

    printf("Ingrese los elementos de la matriz fila por fila:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);

    printf("Máximo de cada fila:\n");
    for (i = 0; i < n; i++)
        printf("Fila %d: %d\n", i+1, maxFila(matriz[i], n));

    return 0;
}

/*11. Cargar una matriz de n filas y n columnas, calcular y mostrar el producto de los
elementos de la diagonal principal en forma recursiva.*/
#include <stdio.h>

// Función recursiva para calcular el producto de la diagonal principal
int productoDiagonal(int matriz[][20], int n, int i) {
    if (i == n)
        return 1;
    else
        return matriz[i][i] * productoDiagonal(matriz, n, i + 1);
}

int main() {
    int n, i, j, matriz[20][20];

    printf("Ingrese la dimensión n de la matriz cuadrada (máx 20): ");
    scanf("%d", &n);

    printf("Ingrese los elementos de la matriz fila por fila:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);

    int prod = productoDiagonal(matriz, n, 0);
    printf("El producto de la diagonal principal es: %d\n", prod);

    return 0;
}

/*12.  Ingresar dos números y calcular el m.c.d. en los mismos en forma recursiva.*/
#include <stdio.h>

// Función recursiva para calcular el máximo común divisor (m.c.d.)
int mcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return mcd(b, a % b);
}

int main() {
    int x, y;
    printf("Ingrese dos números: ");
    scanf("%d %d", &x, &y);

    printf("El máximo común divisor es: %d\n", mcd(x, y));
    return 0;
}