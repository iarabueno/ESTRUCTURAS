// crear y mostrar la lista con numeros enteros. termina con numero=-2

// crear otra lista los numeros impares mostrarla: termina con el numero = 2

// eliminar todos los valores menores al promedio de la lista original en la lista de numeros impares. mostrarla.

//lista original: 5 7 14 6 2 9 3 21 6 2 4 8

//nueva lista 5 7 9 3 21 3

///lista modificada: 7 9 21


#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;


void crear (nodo *pt);
void mostrar(nodo *pt);
nodo* eliminar1(nodo* , int prom);
void eliminar2(nodo*, int prom);
//6) declaramos la función para los numeros impares
void crear_impares(nodo *impares,nodo *prin);
//12) hacemos prototipo de esto
int promedio(nodo *prin);



int main()
{

//guardamos el promedio 
    int prom;

    nodo *prin=NULL;
    //2) creamos un nuevo nodo llamado impares
    nodo *impares=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    //3) reservamos memoria 
    impares=(nodo*)malloc(sizeof(nodo));
    
    
    crear(prin);
    printf("lista original\n");
    mostrar(prin);
    
    //4) creamos otra lista
    
    crear_impares(prin,impares);
    printf("lista de impares\n");
    mostrar(impares);
    //10) acá ponemos el promedio
    prom=promedio(prin);
    printf("el promedio de la lista original es %d", prom);
    //acá ponemos lo de eliminar
    impares=eliminar1(impares, prom);
    eliminar2(impares,prom);

    
    
    return 0;
}
//--------------------------------------------------------//

//9) creamos una funcion que se llame promedios
int promedio(nodo *prin){
    //11) las variables que vamos a usar
    int acum=0, cont=0;
    //10)condicion de corte
    while(prin->sig!=NULL){
        acum+=prin->num;
        cont+=1;
        
        prin=prin->sig;
    }
    return acum/cont;
}

//5) creamos una función para crear los impares
void crear_impares(nodo *prin,nodo *impares){
    //5 7 14 6 2 9 3 21 6 2 4 8
    //6) tenemos que hacer una condicion para poder recorrer la lista entonces
    while(prin->sig!=NULL){
     //condicion para hacer que los numeros sean impares  
        if(prin->num%2!=0){
            impares->num=prin->num;
            impares->sig=(nodo*)malloc(sizeof(nodo));
            //7) para que avance tenemos que hacer que
            impares= impares->sig;
        }
        prin=prin->sig;
    }
    //8) para que termine la condicion
    impares->sig=NULL;
}


void crear (nodo *registro)
{

    scanf("%d",&registro->num);

//1) modificamos la condicion de corte
    if (registro->num==-2)
        registro->sig=NULL;
    else
	{
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("%d\n",registro->num);
        mostrar (registro->sig);
	}
	return;
}


//13) agregamos otro parametro más
nodo* eliminar1(nodo* p, int prom)
{nodo *aux;
    while(p->num<prom)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}
void eliminar2(nodo* p, int prom)
{nodo *aux;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if(p->sig->num<prom)//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
    }
}


/*Crear y mostrar la lista. Termina con num=1000.
b) Generar otra lista con aquellos números múltiplos de 3. Mostrarla
c) Si la suma de nodos consecutivos de la lista original es mayor a 20 agregar
adelante del primer nodo (que se suma) un nodo con num=0.
Si la suma de nodos consecutivos es menor a 10 eliminar el segundo nodo que
se suma.
Mostrar la lista
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;


void crear (nodo *pt);
void mostrar(nodo *pt);
nodo* insertar1(nodo* );
nodo* eliminar1(nodo* );
void insertar2 (nodo* );
void eliminar2(nodo* );


int main()
{

    nodo *prin=NULL;
    
    //paso nro 2: creamos un nuevo nodo llamado multiplos de tres(3)
    nodo *multiplo3=NULL;
    
    prin=(nodo*)malloc(sizeof(nodo));
    
    //paso nro 3: reservamos memoria
    multiplo3=(nodo*)malloc(sizeof(nodo));
    crear(prin);
    mostrar (prin);
    prin=insertar1(prin);
    insertar2(prin);
    prin=eliminar1(prin);
    eliminar2(prin);
    mostrar(prin);

    return 0;
}

void crear (nodo *registro)
{
    printf("ingrese un numero \n");
    scanf("%d",&registro->num);
//paso nro 1: modificamos la condicion de corte
    if (registro->num==1000)
        registro->sig=NULL;
    else
	{
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("%d\n",registro->num);
        mostrar (registro->sig);
	}
	return;
}

//tenemos que generar una nueva funcion con nodos multiplos de multiplo3
void crear_multiplos3(nodo *prin, nodo *multiplos3){
    while (prin->sig != NULL) {
        if (prin->num % 3 == 0) {
            multiplos3->num = prin->num;
            multiplos3->sig = (nodo*)malloc(sizeof(nodo));
            multiplos3 = multiplos3->sig; // avanza al siguiente nodo de la nueva lista
        }
        prin = prin->sig; // avanza al siguiente nodo de la lista original
    }
    multiplos3->sig = NULL; // marca el final de la lista de múltiplos de 3
}

//tenemos que modificar acá
nodo* insertar1(nodo *p)
{
    nodo *aux;
    if(p && p->sig && (p->num + p->sig->num > 20))//condicion de insercion
    {
        aux=(nodo *)malloc(sizeof(nodo));
        aux->num=0;//valor a insertar
        aux->sig=p;
        p=aux;
    }
    return p;
}

void insertar2 (nodo *p)
{nodo *aux;
    while(p && p->sig && p->sig != NULL)
    {
        if(p->sig->num + p->sig->sig->num > 20) //condicion de insercion
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=0;//valor a insertar
            aux->sig=p->sig;
            p->sig=aux;

        }
        p=p->sig;
    }
}

// Elimina el primer nodo mientras la suma de los dos primeros sea < 10
nodo* eliminar1(nodo* p)
{nodo *aux;
    while(p && p->sig && (p->num + p->sig->num < 10))//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}

// Elimina el segundo nodo de cada par consecutivo cuya suma < 10
void eliminar2(nodo* p)
{nodo *aux;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if(p->sig->num + p->sig->sig->num < 10)//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
    }

}