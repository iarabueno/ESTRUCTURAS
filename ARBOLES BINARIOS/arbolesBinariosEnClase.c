/*
Diseñar una funcion que, dado un arbol binari de busqueda, calcule el promedio de aquellos nodos
multiploss de la raiz
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
//paso nro 3: modificamos la estructura
void mostrar(treenode *hoja, int *acum, int *cont, int raiz, int *contHojas, int *contSolo, int *contDos);

int main ()
{
int cont = 0, acum = 0, sum  = 0, prom;
int contHojas = 0, contSolo = 0, contDos = 0;

    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

//paso nro 5, ponemos la raiz 

 int raiz = arbol->dato;
//paso nro 4: modifcamos acá con el &
    mostrar (arbol, &acum, &cont, raiz, &contHojas, &contSolo, &contDos);
    
    if (cont > 0) {
        prom = acum / cont;
        printf("\nPromedio de los nodos múltiplos de la raíz (%d): %d\n", raiz, prom);
    } else {
        printf("\nNo hay múltiplos de la raíz (%d) en el árbol.\n", raiz);
    }
    
    printf("Cantidad de nodos hoja: %d\n", contHojas);
    printf("Cantidad de nodos con un solo hijo: %d\n", contSolo);
    printf("Cantidad de nodos con dos hijos: %d\n", contDos);


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


/*voy a tener que modficarlo aca*/
// primero modicamos acá y agregamos la variables
void mostrar(treenode *hoja, int *acum, int *cont, int raiz, int *contHojas, int *contSolo, int *contDos)
{
    if (hoja!=NULL)
    {


        mostrar(hoja->izq, acum, cont, raiz, contHojas, contSolo, contDos);
        printf("%d ",hoja->dato);
        
        //paso nro 2:
        //como tenemos que sacar los multiplos de la raiz, ponemos 
        //esto como condición 
        if(hoja->dato % raiz == 0){
            
            //el acum
            *acum += hoja->dato;
            *cont += 1;
        }
        
        //para calcular los valores de nodo hoja
        if(hoja->der == NULL && hoja->izq==NULL){
            *contHojas+=1;
        }
        
        //para calcular nodos que tienen 1 solo hijo
        if((hoja->der==NULL && hoja->izq!=NULL) || (hoja->der!=NULL && hoja->izq ==NULL)){
            *contSolo+=1;
        }
        
        //para calcular con dos hijos
        if(hoja->der != NULL && hoja->izq !=NULL){
            *contDos+=1;
        }
        
        mostrar(hoja->der, acum, cont, raiz, contHojas, contSolo, contDos);
        

    
        

    }
    return;
}
