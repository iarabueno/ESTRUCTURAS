#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int codmat;
    char nombre[15];
    struct lista *sig;
} nodo;

void crear(nodo *registro);
void mostrar(nodo *registro);
void mostrarAlumnosMateria(nodo *pt, int cod);
int contarAlumnos(nodo *pt, int cod);
int materiaConMasAlumnos(nodo *pt);

int main() {
    nodo *prin;
    prin = (nodo *)malloc(sizeof(nodo));

    crear(prin);

    printf("\n--- Lista completa ---\n");
    mostrar(prin);

    int cod;
    printf("\nIngrese código de materia a buscar: ");
    scanf("%d", &cod);
    printf("\nAlumnos de la materia %d:\n", cod);
    mostrarAlumnosMateria(prin, cod);

    int codMax = materiaConMasAlumnos(prin);
    printf("\nLa materia con más alumnos es: %d\n", codMax);

    return 0;
}

void crear(nodo *registro) {
    printf("Ingrese codmat (0 para terminar): ");
    scanf("%d", &registro->codmat);

    if (registro->codmat == 0) {
        registro->sig = NULL;
    } else {
        printf("Ingrese nombre del alumno: ");
        scanf("%s", registro->nombre);

        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
}

void mostrar(nodo *registro) {
    if (registro->sig != NULL) {
        printf("Codmat: %d, Nombre: %s\n", registro->codmat, registro->nombre);
        mostrar(registro->sig);
    }
}

void mostrarAlumnosMateria(nodo *pt, int cod) {
    while (pt != NULL && pt->codmat != 0) {
        if (pt->codmat == cod) {
            printf("Alumno: %s\n", pt->nombre);
        }
        pt = pt->sig;
    }
}

int contarAlumnos(nodo *pt, int cod) {
    int count = 0;
    while (pt != NULL && pt->codmat != 0) {
        if (pt->codmat == cod) {
            count++;
        }
        pt = pt->sig;
    }
    return count;
}

int materiaConMasAlumnos(nodo *pt) {
    int maxCod = 0;
    int maxCant = 0;

    while (pt != NULL && pt->codmat != 0) {
        int actualCod = pt->codmat;
        int cant = contarAlumnos(pt, actualCod);
        if (cant > maxCant) {
            maxCant = cant;
            maxCod = actualCod;
        }

        // avanzar hasta que cambie el código de materia
        while (pt != NULL && pt->codmat == actualCod) {
            pt = pt->sig;
        }
    }

    return maxCod;
