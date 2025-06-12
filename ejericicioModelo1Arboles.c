/*
Ejercicio nª1: Crear y Mostrar un árbol binario de búsqueda.
Escribir las funciones necesarias para calcular y luego mostrar:
a) Buscar el mayor elemento del árbol divisor de la raíz
b) Cantidad de nodos hojas impares
*/
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
//paso nro 3: tenemos que modificar el prototipo
void mostrar (treenode *hoja, int raiz, int *mayor, int *cont);

int main ()
{
    //paso nro 6: agregamos acá los valores
    int mayor = 0, cont = 0;

    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    
    //paso nro 4: agregamos la raiz
    int raiz = arbol -> dato;

    //paso nro 5: modificamos acá
    mostrar (arbol, raiz, &mayor, &cont);
    
    printf("cantidad de nodos con hoja impares: %d\n", cont);
    
    if(mayor > 0){
        printf("\nmayor elemento divisor de la raiz: %d \n", mayor);
    } else {
        printf("\nno hay divisor de la raiz");
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



//paso nro 1 modificamos acá agregando las variables que faltan
void mostrar (treenode *hoja, int raiz, int *mayor, int *cont)
{
    if (hoja!=NULL)
    {
        //tenemos que modificar acá
        mostrar(hoja->izq, raiz, mayor, cont);
        printf("%d ",hoja->dato);
        
        //paso nro 2: modificar acá
        
        //punto a:  Buscar el mayor elemento del árbol divisor de la raíz
        if (hoja->dato != raiz && raiz % hoja->dato == 0)
        {
            if (hoja->dato > *mayor)
                *mayor = hoja->dato;
        }
        
        //punto b: nos pide saber cantidad de nodos impares
        //primera condicion si es un nodo hoja
        if ((hoja->izq == NULL) && (hoja->der == NULL)){
            
            //la codicion para saber si es un nodo impare
            if(hoja->dato%2 != 0){
            (*cont)++;
            }
        }
        //tenemos que modificar acá
        mostrar(hoja->der, raiz, mayor, cont);

    }
    return;
}
