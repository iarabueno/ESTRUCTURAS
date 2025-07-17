/*EJERCICIO 1 - PILAS: la cantidad de numeros multiplo tope de una pila de numeros enteros*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

//paso nro1 1: tenemos que modificar acá
void mostrar(nodo aux, int tope, int *cont_multiplo)
{
    printf("%d \n", aux.dato);
    if (tope != 0 && aux.dato % tope == 0) {
        (*cont_multiplo) += 1;
    }
}

/*EJERCICIO 2 - ARBOL: la cantidad de nodos con UN SOLO HIJO que a su vez son divisores de la raiz en un arbol binario*/
#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
//paso nro 2: modificamos acá
void mostrar (treenode *hoja, int raiz, int *cont);

int main ()
{
    //paso nro 3: agregamos variables
    int cont = 0;

    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    //declaramos la raiz 
    int raiz = arbol -> dato;
    //paso nro 4: agregamos acá los datos
    mostrar (arbol, raiz, &cont);
    printf("\nCantidad de nodos con un solo hijo divisores de la raíz: (%d): %d\n", raiz, cont);


    return 0;
}
void crear (treenode **hoja)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{




    if (numero>(*hoja)->dato)
    {

        insertar (&(*hoja)->der,elem);

    }
    else
    {

        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}


// paso nro 1: modificamos esta funcion
void mostrar (treenode *hoja, int raiz, int *cont)
{
    if (hoja!=NULL)
    {

        //modificamos tanto acá
        mostrar(hoja->izq, raiz, cont);
        
        printf("%d ",hoja->dato);
        
        //condicion nro1: queremos que sean nodos de UN SOLO HIJO
        if((hoja->izq == NULL && hoja -> der != NULL) || (hoja->izq != NULL && hoja->der == NULL)){
            //condicion nro 2: queremos que sea divisor de la raiz
            if (hoja->dato != 0 && raiz % hoja->dato == 0){
                (*cont)++;
            }
        }
        // y acá
        mostrar(hoja->der, raiz, cont);

    }
    return;
}

#include <stdio.h>

int factorial(int num);
int division(int num, int divisor);
int invertir(int num);

int main(){
    int num, divisor, opcion;

    printf("Elija una opción:\n1. Factorial\n2. División\n3. Invertir\nOpción: ");
    scanf("%d", &opcion);

    if(opcion == 1) {
        printf("Ingrese un número para calcular su factorial: ");
        scanf("%d", &num);
        printf("El factorial de %d es: %d\n", num, factorial(num));
    } else if(opcion == 2) {
        printf("Ingrese el número y el divisor para dividir (entera): ");
        scanf("%d %d", &num, &divisor);
        printf("La división entera de %d por %d es: %d\n", num, divisor, division(num, divisor));
    } else if(opcion == 3) {
        printf("Ingrese un número para invertir sus dígitos: ");
        scanf("%d", &num);
        printf("El número invertido es: %d\n", invertir(num));
    } else {
        printf("Opción inválida\n");
    }

    return 0;
}

int division(int num, int divisor){
    if (num < divisor){
        return 0;
    }
    return division(num-divisor, divisor) + 1;
}

// Para invertir, necesitamos saber cuántos dígitos tiene el número original
int invertir(int num){
    int invertido = 0;
    // Función auxiliar para invertir recursivamente
    int helper(int n, int pot){
        if(n < 10)
            return n * pot;
        return (n % 10) * pot + helper(n / 10, pot / 10);
    }
    // Calcula la potencia de 10 mayor o igual al número
    int pot = 1, temp = num;
    while(temp >= 10) {
        pot *= 10;
        temp /= 10;
    }
    return helper(num, pot);
}

int factorial(int num){
    if(num == 0){
        return 1;
    }
    return num * factorial(num-1);
}

