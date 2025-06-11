// 1. Diseñar una función que, dado un árbol binario y un valor, determine si el valor pertenece al árbol.
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
//paso 3. modificamos el prototipo 
void mostrar(treenode *hoja, int valoraBuscar);

int main ()
{

    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol);
    
    //paso 4. para buscar el valoraBuscar
    int valor;
    printf("\nIngrese valor a buscar: ");
    scanf("%d", &valor);
    
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, valor);


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


//paso 1. modificamos acá, agregamos las variables necesarias
void mostrar (treenode *hoja, int valoraBuscar)
{
    if (hoja!=NULL)
    {

// tenemos que modificar acá
        mostrar(hoja->izq, valoraBuscar);
        printf("%d ",hoja->dato);
        
        //paso 2. agregamos la condicion acá si pertenece o no al arbol
        if(hoja -> dato == valoraBuscar){
            printf("\n el valor %d pertenece al arbol", valoraBuscar);
        }
// tenemos que modificar acá        
        mostrar(hoja->der, valoraBuscar);
    }
    return;
}
// 2. Diseñar una función que, dado un árbol binario, calcule su cantidad de nodos.
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
void mostrar (treenode *hoja, int *contNodos);

int main ()
{

    printf ("arboles\n");
    treenode* arbol=NULL;
    
    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    
    int total = 0;
    mostrar (arbol, &total);
    printf("\n la cantidad total de nodos es: %d", total);


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


//paso 1. modificamos acá
void mostrar(treenode *hoja, int *contNodos)
{
    if (hoja!=NULL)
    {

//modificamos acá 
        mostrar(hoja->izq, contNodos);
        printf("%d ",hoja->dato);
        (*contNodos)++;
//modificamos acá
        mostrar(hoja->der, contNodos);

    }
    return;
}
// 3. Diseñar tres funciones para el recorrido de un árbol binario (pre orden, orden y post orden).

// 4. Diseñar una función que, dado un árbol binario de búsqueda, calcule el promedio de aquellos nodos múltiplos de la raíz.
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

//paso 3. modifcamos el prototipo
void mostrar (treenode *hoja, int raiz, int *acum, int *cont);

int main ()
{
//paso 4. agregamos variables nuevas
int acum = 0, cont = 0, prom;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    //paso 5. agregamos la variable raiz
     int raiz = arbol->dato;
     
    mostrar (arbol, raiz, &acum, &cont);

    
    //paso 6. agregamos la condicion para el promedio
    if (cont > 0) {
        prom = acum / cont;
        printf("\nPromedio de los nodos múltiplos de la raíz (%d): %d\n", raiz, prom);
    } else {
        printf("\nNo hay múltiplos de la raíz (%d) en el árbol.\n", raiz);
    }

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


//paso 1. modificamos acá agregando las variables
void mostrar (treenode *hoja, int raiz, int *acum, int *cont)
{
    if (hoja!=NULL)
    {


        mostrar(hoja->izq, raiz, acum, cont);
        printf("%d ",hoja->dato);
        //paso 2. agregamos la condicion acá
        if(hoja->dato % raiz == 0){
            *acum += hoja -> dato;
            *cont+=1;
        }
        mostrar(hoja->der, raiz, acum, cont);

    }
    return;
}
// 5. Diseñar una función que, dado un árbol binario de búsqueda, calcule la cantidad de nodos hojas divisores de la raíz.
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
//paso 3. modificamos acá
void mostrar (treenode *hoja, int raiz, int *acum, int *con);

int main ()
{
    //agregamos variables
    int acum = 0, cont = 0; 

    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    //
    int raiz = arbol->dato;
     
    mostrar (arbol, raiz, &acum, &cont);
    printf("\nCantidad de nodos hoja divisores de la raíz (%d): %d\n", raiz, cont);


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


//paso 1. modificamos acá
void mostrar (treenode *hoja, int raiz, int *acum, int *cont)
{
    if (hoja!=NULL)
    {


        mostrar(hoja->izq, raiz, acum, cont);
        printf("%d ",hoja->dato);
        //paso 2. ponemos la condición
        //si hoja no tiene hijos
        if(hoja->izq == NULL && hoja -> der == NULL){
            //si se es divisor de la raiz
            if (hoja->dato != 0 && raiz % hoja->dato == 0){
                (*cont)++;
            }
        }
        
        mostrar(hoja->der, raiz, acum, cont);

    }
    return;
}

// 6. Diseñar una función que, dado un árbol binario de búsqueda, calcule la sumatoria de aquellos nodos pares con un solo hijo.
//7. Diseñar una función que, dado un árbol binario de búsqueda, calcule la cantidad de nodos impares con dos hijos.
