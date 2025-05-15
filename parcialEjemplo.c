
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
