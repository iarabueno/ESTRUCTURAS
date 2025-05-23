#include<stdio.h>

#include<stdlib.h>

#include<string.h>



#define CANT 6

//El número máximo y su posición en la cola.

typedef struct tiponodo

{

 int dato;

  struct tiponodo *siguiente;

}nodo;

void mostrar (nodo aux, int *maximo, int *posicion_mayor, int *contador)

{

  printf("%d \n", aux.dato);

  *contador=*contador+1;

  if(aux.dato>*maximo){

    *maximo=aux.dato;

    *posicion_mayor=*contador;

  }

}

nodo* crear_nodo(int dato)

{

  nodo* u;

  u = (nodo *)malloc(sizeof(nodo));

  u->dato = dato;

  u->siguiente = NULL;

  return u;

}

void acolar(nodo** p,nodo** u, nodo *q)

{

  printf("acolar_nodo\n");

 if(*p==NULL)

  *p = *u = q; /*porque hay uno solo*/

  else

  {

   (*u)->siguiente = q;

   (*u) = q;

  }

  printf("%02d p=%X u=%X\n", q->dato, *p, *u);

}

nodo desacolar(nodo** inicio)

{

 nodo* aux;

  nodo datos;

 datos=**inicio;

 aux=*inicio;

 *inicio=(*inicio)->siguiente;

 free(aux);

  return datos;

}

int main()

{

  int i,num, maximo=0, contador=0, posicion_mayor=0;

  nodo* p=NULL;

  nodo* u=NULL;

  for(i=0; i<CANT; i++)

  {

    printf("Ingrese un numero");

    scanf("%d",&num);

    acolar(&p, &u, crear_nodo(num));

  }

  printf("\nVamos a desacolar todo\n");

 while(p!=NULL)

  {

   mostrar(desacolar(&p),&maximo,&posicion_mayor,&contador);

  }

  printf("El maximo es %d", maximo);

  printf("\n");

  printf("La posicion del maximo es %d", posicion_mayor);

  return 0;

}
