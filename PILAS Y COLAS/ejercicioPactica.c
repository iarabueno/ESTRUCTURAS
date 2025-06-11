/*
PARA PILAS
*/
// 1. numeros multiplos de 3

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

/*paso nro 1: modificamos acá*/

void mostrar (nodo aux, int *cont_multiplo)

{
     	printf("%d \n", aux.dato);
     	
     	//validamos si es multiplo o no
     	if (aux.dato%3 == 0){
     	    *cont_multiplo+=1;
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
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

//paso nro 2: modificamos acá las variables
   int i,num, cont_multiplo=0;
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
       //paso nro 3: tenemos que modificar acá indicandole la direccion de memoria de la variable
    	mostrar(desapilar(&p), &cont_multiplo);
   }
   printf("la cantidad de multiplos de 3 es: %d", cont_multiplo);


   getch();
   return 0;
}
//-------------------------------------------------------
// 2. El promedio de aquellos números divisores de 4.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

// paso nro 1: modificamos acá
void mostrar (nodo aux, int *sum, int *cont) //agregamos como puntero sum y cont

{
     	printf("%d \n", aux.dato);
     	
     	//acá abajo
     	
     	if(4 % aux.dato == 0){
     	    *sum += aux.dato;
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
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

//paso nro 2: modificamos acá
   int i,num, sum = 0, cont = 0;
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
    	mostrar(desapilar(&p), &sum, &cont);
   }
   
   if (cont!= 0){
       printf("el promedio de los divisores de 4: es %d", sum/cont);
       
   } else {
       printf("no se puede");
   }


   getch();
   return 0;
}
//-------------------------------------------------------
// 3. La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

//paso nro 1 tendriamos que modificar acá -> prototipo
void mostrar (nodo aux, int primer_elemento, int *sum) //agrregamos como puntero *sum

{
     	printf("%d \n", aux.dato);
     	//paso nro 2: la condicion si es multiplo del primer_elemento
     	if(primer_elemento != 0 && aux.dato % primer_elemento == 0){
     	    *sum += aux.dato;
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
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


   int i,num, primer_elemento, sum = 0;
   nodo* p=NULL;
  


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   	
   	//paso nro 4: la condicion del primer elemento
       	if(i== 0){
       	    primer_elemento = num;
       	}
   }


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
       //paso nro 4: ponemos acá como direccion de memmoria &suma
    	mostrar(desapilar(&p),primer_elemento, &sum);
   }
   printf("la sumatoria de multiplos del primer elemento (%d) es: %d ", primer_elemento, sum);


   getch();
   return 0;
}

//-------------------------------------------------------
//4. El número máximo y su posición en la pila.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

// paso nro 1: modificamos acá
void mostrar (nodo aux, int *max, int *pos_max, int pos)

{
     	printf("%d \n", aux.dato);
     	
     	//modificamos acá para poner la condicion
     	if(aux.dato > *max){
     	    *max = aux.dato;
     	    *pos_max = pos;
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
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


   int i,num, sum, max, pos_max, pos;
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
    	mostrar(desapilar(&p), &max, &pos_max, pos);
    	pos++;
   }
   printf("el numero max es (%d) y su posicion de fila es (%d)", max, pos_max);


   getch();
   return 0;
}
//-------------------------------------------------------
//4. El número mínimo y su posición en la pila.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

// paso nro 1: modificamos acá
void mostrar(nodo aux, int *min, int *pos_min, int pos) {
    printf("%d \n", aux.dato);
    if (pos == 1) {
        *min = aux.dato;
        *pos_min = pos;
    } else if (aux.dato < *min) {
        *min = aux.dato;
        *pos_min = pos;
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
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


   int i,num, min, pos_min, pos;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   }


   printf("\nVamos a desapilar todo\n");
   pos = 1;
	while(p!=NULL)
   {
    	mostrar(desapilar(&p), &min, &pos_min, pos);
    	pos++;
   }
   printf("el numero min es (%d) y su posicion de fila es (%d)", min, pos_min);


   getch();
   return 0;
}
//------------------------------------
// 4. Ingresar un numero por teclado y calcular la sumatoria de aquellos números
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

//paso nro 1: modificamos acá
void mostrar (nodo aux, int *sum)

{
     	printf("%d \n", aux.dato);
     	
     	*sum += aux.dato;
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
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

//paso nro 2: declaramos acá

   int i,num, sum = 0;
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
       //paso nro 3: ponemos acá
    	mostrar(desapilar(&p),  &sum);
   }
   printf("la suma total de los numero es: %d", sum);


   getch();
   return 0;
}
/*
PARA COLAS
*/
// 2. El promedio de aquellos números divisores del último número ingresado a la cola
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

//paso nro 1 modificamos el prototipo mostrar agregando los punteros necesarios
void mostrar (nodo aux, int ultimo_dato, int *sum, int *cont)
{
  	printf("%d \n", aux.dato);
  	//ponemos la condicion
  	if (ultimo_dato % aux.dato == 0){
  	    *sum+=aux.dato;
  	    *cont+=1;
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

// paso nro 3: agregamos las variables acá
   int i,num, ultimo_dato, sum = 0, cont = 0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
        //paso nro 4: tenemos que conseguir el ultimo dato y como es una cola, el ultimo dato ingresado, se conseguira en acolar
        ultimo_dato = num; //con esto guardamos el ultimo dato ingresado

   }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
       // paso nro 5: modifcamos acá
    	mostrar(desacolar(&p), ultimo_dato, &sum, &cont);
   }
   // paso nro 6: modificamos acá
   if(cont != 0){
       printf("el ultimo numero ingresado es (%d) y el promedio es (%d)", ultimo_dato, sum/cont);
   } else {
       printf("no hay numeros divisores");
   }
   return 0;
}

//-----------------------------------
//3. Sumatoria de aquellos números divisores de primer elemento ingresado a la cola.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

//primer paso: modificamos acá el prototipo
void mostrar (nodo aux, int primer_numero, int *sum)
{
  	printf("%d \n", aux.dato);
  	//condicion para recibir el primer elemento
  	if(primer_numero != 0 && primer_numero%aux.dato == 0){
  	    *sum+= aux.dato;
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
// paso nro 2: modifcamos acá agregando variables
   int i,num, primer_numero = 0, sum = 0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
        if (i == 0){
    	    primer_numero = num;
        }
   }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), primer_numero, &sum);
    	
   }
   printf("primer elemento: %d sumatoria de divisores: %d", primer_numero, sum);
   return 0;
}
//-----------------------------------
// 4. El número máximo y su posición en la cola.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

//paso nro 1: modificamos el prototipo
void mostrar (nodo aux, int *max, int *posicion_max, int *cont)
{
  	printf("%d \n", aux.dato);
  	*cont=*cont+1;
  	//la condicion
  	if(aux.dato > *max){
  	    *max = aux.dato;
  	    *posicion_max =* cont;
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
// modificamos acá
   int i,num, max = 0, cont = 0, posicion_max = 0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
        if (i == 0){
            max = num;
        }

   }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &max, &posicion_max, &cont);
   }
   //
   printf("el numero maximo es %d y la posicion es %d", max, posicion_max);
   return 0;
}

//-------------------------------
// 5. El número mínimo y su posición en la cola.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

//paso nro 1: modificamos el prototipo
void mostrar (nodo aux, int *min, int *posicion_min, int *cont)
{
  	printf("%d \n", aux.dato);
  	*cont=*cont+1;
  	//la condicion
  	if(aux.dato < *min){
  	    *min = aux.dato;
  	    *posicion_min =* cont;
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
// modificamos acá
   int i,num, min = 0, cont = 0, posicion_min = 0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
        if (i == 0){
            min = num;
        }

   }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &min, &posicion_min, &cont);
   }
   //
   printf("el numero min es %d y la posicion min es %d", min, posicion_min);
   return 0;
}
