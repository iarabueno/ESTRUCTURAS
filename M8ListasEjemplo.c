// creas y mostrar la lista, la carga de los datos termina con dni= 0, la carga de los datos se hace de forma ascendente por dni
// generar otra lista con todos los saldos negativos

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para usar strcpy y strcmp

//paso nro 1: cambiamos esta estructura
typedef struct lista{
	int dni;
    char nombre[20];
    float saldo;
    
	struct lista *sig;
 }nodo;


void crear (nodo *pt);
void mostrar(nodo *pt);
void saldos_negativos(nodo *prin,nodo* segunda);


int main()
{
    nodo *prin;
    
    //6) creamos otro nodo para lista negativa
    nodo *segunda;
    
    prin=(nodo*)malloc(sizeof(nodo));
    
    //7) reservamos memoria 
    segunda=(nodo*)malloc(sizeof(nodo));
    
    crear(prin);
    mostrar (prin);
    
    //8) creamos la funcion para los saldos negativos
    saldos_negativos(prin,segunda);
    

    //11) mostrar saldos negativos
    printf("\nlos saldos negativos son: \n");
    mostrar(segunda);
    


    return 0;
}

//9) recorrer la lista entonces va a ser de tipo void
//prin es la primera lista y segunda es la lista de los saldos negativos que todavia no está llena.
void saldos_negativos(nodo *prin,nodo* segunda){
    while(prin->sig!=NULL){//condicion para recorrer
    
    if(prin->saldo<0){
        //10) generamos la condicion para guardarlo en la lista segunda
        segunda->dni=prin->dni;
        segunda->saldo=prin->saldo;
        // segunda->nombre=prin->nombre;
        strcpy(segunda->nombre,prin->nombre);
        
        segunda->sig = (nodo*)malloc(sizeof(nodo));
        segunda = segunda -> sig;
    }
    
        printf("%d", prin->dni);
        prin=prin->sig; //me muevo de la lista
        
    }
    segunda->sig = NULL;
}


//2) modificamos este codigo
void crear (nodo *registro)
{
    //printf("Ingrese numero");
    //scanf("%d",&registro->num); ESTO VIENE DE BASE Y HAY QUE CAMBIARLO

    printf("ingrese dni: \n"); //condicion de corte
    scanf("%d", &registro->dni); //asignamos el puntero y el dni

    if (registro->dni==0){ //3) cambiamos la condicion de corte
        registro->sig=NULL;
    }else
	{
        //en caso de que no se haya ingresado el dni = 0, se van a pedir mas datos entonces
        //4) rellenamos acá

        printf("ingresar el saldo: \n");
        scanf("%f",  &registro->saldo);
        /* */ 
        printf("ingresar nombre: \n");
        scanf("%s", registro->nombre);


        //aca creamos el nodo, se enlaza y se llama
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    //5) modificamos el codigo de acá
    if (registro->sig !=NULL)
	{
        printf ("dni: %d\t",registro->dni);
        printf("nombre: %s\t", registro->nombre);
        printf("saldo: %f\t", registro->saldo);

        mostrar (registro->sig);
	}
	return;
}
