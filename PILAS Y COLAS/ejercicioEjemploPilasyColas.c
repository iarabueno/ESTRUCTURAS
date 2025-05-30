#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4

/*La cantidad de numeros multiplos de tres
promedio de los divisores de cuatro */

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;


/*PRIMER PASO: MODIFICAMOS ACÁ. PARA SABER SI ES MULTIPLO O NO*/
/*CUARTO PASO: DECLARAMOS LAS VARIABLES PARA LA SEGUNDA CONDICION*/
void mostrar (nodo aux, int *cont_multiplo, int *suma, int *cont) //pasamos al contador como puntero

{
     	printf("%d \n", aux.dato);
     	
     	/*validamos con aux.dato para saber si son multiplos*/
     	if(aux.dato%3==0){
     	    /*tenemos que acceder al valor de memoria entonces ponemos
     	    asterisco */
     	    *cont_multiplo+=1;
     	}
     	/*TERCER PASO: Tenemos que hacer la segunda condicion*/
     	if(4 % aux.dato == 0){
     	    *suma += aux.dato;
     	    *cont+=1;
     	    
     	}
     	
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


  	u->siguiente = *p;
  	printf("%02d p=%p u=%p\n", u->dato, *p, u);
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{

/*PASO NRO 2: MODIFICAR ACÁ*/
   int i,num, suma = 0, cont = 0, cant_multiplo =0;
   nodo* p=NULL;

   


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   }


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
       //con el & le estamos la direccion de memoria de la variable.
    	mostrar(desapilar(&p), &cant_multiplo, &suma, &cont);
   }
   printf("la cantidad de los multiplos de 3 es: %d", cant_multiplo);
   
   if(cont!=0){
       printf("el promedio de los divisores de 4 es %d", suma/cont);
   } else{
        printf("no se puede");  
   }



   getch();
   return 0;
}
