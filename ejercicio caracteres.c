/*1. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras
tienen más de 3 letras.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    int cont = 0, palabras_mas_3 = 0;

    printf("Ingrese una frase que termine con un '.':\n");
    c = getchar();

    while(c != '.'){
        if(c != ' '){
            cont++;
        } else{
            if(cont > 3){
                palabras_mas_3++;
            }
            cont = 0;
        }
        c = getchar();
    }

    // Para la última palabra antes del punto
    if (cont > 3) {
        palabras_mas_3++;
    }

    printf("Cantidad de palabras con más de 3 letras: %d\n", palabras_mas_3);
    return 0;
}

/*2. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto con un
blanco y eliminando las palabras de 1 letra*/
#include <stdio.h>
#include <string.h>

int main() {
    char palabra[50];

    printf("Ingrese el texto terminado en punto:\n");
    do {
        scanf("%s", palabra);
        if(strcmp(palabra, ".") != 0 && strlen(palabra) > 1) {
            printf("%s ", palabra);
        }
    } while(strcmp(palabra, ".") != 0);

    printf("\n");
    return 0;
}

/*
3. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras
tienen más de 2 letras y terminan con “s”
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char c, ultimo;
    int contador = 0, cantidad = 0;

    printf("Ingrese una frase terminada en punto:\n");

    c = getchar();
    while (c != '.') {
        if (c != ' ') {
            contador++;
            ultimo = c; // guarda el último carácter leído de la palabra
        } else {
            if (contador > 2 && ultimo == 's') {
                cantidad++;
            }
            contador = 0;
        }
        c = getchar();
    }

    // Para la última palabra antes del punto
    if (contador > 2 && ultimo == 's') {
        cantidad++;
    }

    printf("Cantidad de palabras con más de 2 letras y terminadas en 's': %d\n", cantidad);
    return 0;
}

/*4. Leer un texto carácter a carácter, terminado en PUNTO y repetirlo reemplazando
los grupos ‘vl’ por ‘bl’.*/
#include <stdio.h>

int main() {
    char c, anterior = 0;
    printf("Ingrese una frase terminada en punto:\n");

    c = getchar();
    while (c != '.') {
        if (anterior == 'v' && c == 'l') {
            // Reemplaza 'vl' por 'bl'
            putchar('b');
            putchar('l');
            anterior = 0; // Ya procesamos ambos
            c = getchar();
            continue;
        }
        if (anterior) {
            putchar(anterior);
        }
        anterior = c;
        c = getchar();
    }
    // Imprime el último carácter si no fue parte de 'vl'
    if (anterior && anterior != 'v') {
        putchar(anterior);
    }
    printf(".\n"); // Agrega el punto final
    return 0;
}

#include <stdio.h>

int main() {
    char c, primera, ultima;
    int en_palabra = 0, contador = 0;

    printf("Ingrese el texto terminado en punto:\n");

    c = getchar();
    while (c != '.') {
        if (c != ' ') {
            if (!en_palabra) {
                // Comienza una nueva palabra
                primera = c;
                en_palabra = 1;
            }
            ultima = c;
        } else {
            if (en_palabra && primera == ultima) {
                contador++;
            }
            en_palabra = 0;
        }
        c = getchar();
    }
    // Para la última palabra antes del punto
    if (en_palabra && primera == ultima) {
        contador++;
    }

    printf("Cantidad de palabras que empiezan y terminan con la misma letra: %d\n", contador);
    return 0;
}

/*5. Leer un texto carácter a carácter terminado en PUNTO. Contar cuantas palabras
empiezan y terminan con la misma letra.*/
#include <stdio.h>

int main() {
    char c, primera, ultima;
    int en_palabra = 0, contador = 0;

    printf("Ingrese el texto terminado en punto:\n");

    c = getchar();
    while (c != '.') {
        if (c != ' ') {
            if (!en_palabra) {
                // Comienza una nueva palabra
                primera = c;
                en_palabra = 1;
            }
            ultima = c;
        } else {
            if (en_palabra && primera == ultima) {
                contador++;
            }
            en_palabra = 0;
        }
        c = getchar();
    }
    // Para la última palabra antes del punto
    if (en_palabra && primera == ultima) {
        contador++;
    }

    printf("Cantidad de palabras que empiezan y terminan con la misma letra: %d\n", contador);
    return 0;
}

/*6. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto
intercambiando la última letra con la anteúltima de las palabras de 2 o más letras*/
#include <stdio.h>
#include <stdio.h>

int main() {
    char palabra[100];
    int i = 0;
    char c;

    printf("Ingrese el texto terminado en punto:\n");

    while ((c = getchar()) != '.') {
        if (c != ' ') {
            // Guarda el carácter en el arreglo
            palabra[i++] = c;
        } else {
            // Fin de palabra
            if (i == 1) {
                // Palabra de una sola letra: imprimir tal cual
                putchar(palabra[0]);
            } else if (i >= 2) {
                // Intercambia la última y la anteúltima letra
                char tmp = palabra[i - 1];
                palabra[i - 1] = palabra[i - 2];
                palabra[i - 2] = tmp;
                // Imprimir la palabra modificada
                for (int j = 0; j < i; j++) {
                    putchar(palabra[j]);
                }
            }
            putchar(' '); // Imprime el espacio
            i = 0; // Reinicia índice para la próxima palabra
        }
    }

    // Procesa la última palabra antes del punto
    if (i == 1) {
        putchar(palabra[0]);
    } else if (i >= 2) {
        char tmp = palabra[i - 1];
        palabra[i - 1] = palabra[i - 2];
        palabra[i - 2] = tmp;
        for (int j = 0; j < i; j++) {
            putchar(palabra[j]);
        }
    }
    putchar('.'); // Imprime el punto final
    putchar('\n');

    return 0;
}

/*7. Ingresar un texto carácter a carácter y determinar e informar cuantas palabras
capicúas hay de 2 o 3 letras*/
#include <stdio.h>

int main() {
    char palabra[10];
    int i = 0, capicua = 0;
    char c;

    printf("Ingrese el texto (finalice con punto):\n");
    while ((c = getchar()) != '.') {
        if (c != ' ') {
            palabra[i++] = c;
        } else {
            // Procesar la palabra
            if (i == 2 && palabra[0] == palabra[1]) {
                capicua++;
            } else if (i == 3 && palabra[0] == palabra[2]) {
                capicua++;
            }
            i = 0; // Reiniciar para la próxima palabra
        }
    }
    // Procesar última palabra antes del punto
    if (i == 2 && palabra[0] == palabra[1]) {
        capicua++;
    } else if (i == 3 && palabra[0] == palabra[2]) {
        capicua++;
    }

    printf("Cantidad de palabras capicúas de 2 o 3 letras: %d\n", capicua);
    return 0;
}

/*8. Ingresar un texto carácter a carácter terminado en PUNTO. Contar cuantas
palabras empiezan con la anteúltima letra de la palabra anterior. En palabras de 1
sola letra deberá tomar esta única letra como anteúltima*/
#include <stdio.h>

int main() {
    char palabra[50];
    int i = 0, contador = 0;
    char anteultima = 0;
    char c;

    printf("Ingrese el texto terminado en punto:\n");

    while ((c = getchar()) != '.') {
        if (c != ' ') {
            palabra[i++] = c;
        } else {
            if (i > 0) {
                // Determinar anteúltima letra de la palabra anterior
                char actual_anteultima;
                if (i == 1) {
                    actual_anteultima = palabra[0];
                } else {
                    actual_anteultima = palabra[i - 2];
                }
                // Comparar la primera letra con la anteúltima de la anterior palabra, si no es la primera palabra
                if (anteultima != 0 && palabra[0] == anteultima) {
                    contador++;
                }
                anteultima = actual_anteultima;
                i = 0;
            }
        }
    }
    // Procesar la última palabra antes del punto
    if (i > 0) {
        char actual_anteultima;
        if (i == 1) {
            actual_anteultima = palabra[0];
        } else {
            actual_anteultima = palabra[i - 2];
        }
        if (anteultima != 0 && palabra[0] == anteultima) {
            contador++;
        }
    }

    printf("Cantidad de palabras que empiezan con la anteúltima letra de la anterior: %d\n", contador);
    return 0;
}

/*9. Leer un texto carácter a carácter terminado en PUNTO. Contar cuantas palabras
comienzan con las mismas 2 letras de la palabra anterior*/
#include <stdio.h>

int main() {
    char palabra[100];
    int i = 0, contador = 0;
    char prev_primera = 0, prev_segunda = 0;
    char c;

    printf("Ingrese el texto terminado en punto:\n");
    c = getchar();

    while (c != '.') {
        if (c != ' ') {
            palabra[i] = c;
            i++;
        } else if (i > 0) { // Fin de palabra
            if (i >= 2 && prev_primera && prev_segunda
                && palabra[0] == prev_primera && palabra[1] == prev_segunda) {
                contador++;
            }
            if (i >= 1) prev_primera = palabra[0];
            else        prev_primera = 0;
            if (i >= 2) prev_segunda = palabra[1];
            else        prev_segunda = 0;
            i = 0;
        }
        c = getchar();
    }
    // Procesar la última palabra antes del punto
    if (i > 0 && i >= 2 && prev_primera && prev_segunda
        && palabra[0] == prev_primera && palabra[1] == prev_segunda) {
        contador++;
    }

    printf("Cantidad de palabras que comienzan con las mismas dos letras de la anterior: %d\n", contador);
    return 0;
}

/*10. Leer un texto carácter por carácter terminando en PUNTO. Contar cuántas
palabras con 2 letras seguidas iguales hay*/
#include <stdio.h>

int main() {
    char palabra[100];
    int i = 0, contador = 0;
    char c;
    int tiene_doble = 0;

    printf("Ingrese el texto terminado en punto:\n");
    c = getchar();

    while (c != '.') {
        if (c != ' ') {
            palabra[i] = c;
            if (i > 0 && palabra[i] == palabra[i-1]) {
                tiene_doble = 1;
            }
            i++;
        } else if (i > 0) { // Fin de palabra
            if (tiene_doble) {
                contador++;
            }
            tiene_doble = 0;
            i = 0;
        }
        c = getchar();
    }
    // Procesar la última palabra antes del punto
    if (i > 0 && tiene_doble) {
        contador++;
    }

    printf("Cantidad de palabras con 2 letras seguidas iguales: %d\n", contador);
    return 0;
}

/*11.  Ingrese un texto carácter a carácter terminado en PUNTO contar cuantas palabras
tienen más de una vez repetida la primera vocal que aparece en el texto.*/
#include <stdio.h>
#include <stdio.h>

int es_vocal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    char palabra[100];
    int i = 0, contador = 0;
    char c;
    char primera_vocal = 0;

    printf("Ingrese el texto terminado en punto:\n");
    c = getchar();

    // Buscar la primera vocal del texto
    while (c != '.' && !primera_vocal) {
        if (es_vocal(c)) {
            primera_vocal = c;
        }
        c = getchar();
    }

    // Si no hay vocal, no hay palabras que la repitan
    if (!primera_vocal) {
        printf("Cantidad de palabras con la primera vocal repetida: 0\n");
        return 0;
    }

    // Reiniciar el texto para procesar palabra por palabra
    printf("Ingrese el texto nuevamente terminado en punto:\n");
    c = getchar();

    while (c != '.') {
        if (c != ' ') {
            palabra[i] = c;
            i++;
        } else if (i > 0) { // Fin de palabra
            int repite = 0, j, cuenta = 0;
            for (j = 0; j < i; j++) {
                if (palabra[j] == primera_vocal) cuenta++;
            }
            if (cuenta > 1) repite = 1;
            if (repite) contador++;
            i = 0;
        }
        c = getchar();
    }
    // Procesar la última palabra antes del punto
    if (i > 0) {
        int repite = 0, j, cuenta = 0;
        for (j = 0; j < i; j++) {
            if (palabra[j] == primera_vocal) cuenta++;
        }
        if (cuenta > 1) repite = 1;
        if (repite) contador++;
    }

    printf("Cantidad de palabras con la primera vocal repetida: %d\n", contador);
    return 0;
}

/*12.  Ingrese un texto carácter a carácter terminado en PUNTO y repítalo agregando una
‘u’ entre cada letra ‘q’ seguida de ‘i’ o ‘e’.*/
#include <stdio.h>

int main() {
    char c, ant;

    printf("Ingrese un texto terminado en punto:\n");
    ant = getchar();

    while (ant != '.') {
        c = getchar();
        putchar(ant);
        if (ant == 'q' && (c == 'i' || c == 'e')) {
            putchar('u');
        }
        ant = c;
    }
    putchar('.'); // Imprime el punto al final
    printf("\n");
    return 0;
}

/*13.  Leer un texto carácter por carácter terminando en PUNTO y contar la cantidad de
letras iguales a la primera distinta de blanco.*/
#include <stdio.h>

int main() {
    char c, primera = 0;
    int contador = 0;

    printf("Ingrese el texto terminado en punto:\n");
    c = getchar();

    // Buscar la primera letra distinta de blanco
    while (c == ' ' && c != '.') {
        c = getchar();
    }
    if (c != '.') {
        primera = c;
    }

    // Si hay una letra válida, contar las iguales
    while (c != '.') {
        if (c == primera) {
            contador++;
        }
        c = getchar();
    }

    printf("Cantidad de letras iguales a la primera distinta de blanco: %d\n", contador);
    return 0;
}

/*14.  Leer un texto carácter por carácter terminando en PUNTO. Contar grupos "TA".
Mostrar reemplazando por “TE”.*/
#include <stdio.h>

int main() {
    char c, ant;
    int gruposTA = 0;

    printf("Ingrese el texto terminado en punto:\n");
    ant = getchar();

    while (ant != '.') {
        c = getchar();
        if (ant == 'T' && c == 'A') {
            gruposTA++;
            putchar('T');
            putchar('E');
            ant = getchar(); // Saltar la 'A' que ya procesamos
        } else {
            putchar(ant);
            ant = c;
        }
    }
    putchar('.'); // Termina con el punto
    printf("\nCantidad de grupos \"TA\": %d\n", gruposTA);
    return 0;
}

/*15.  Leer un texto carácter por carácter terminando en punto. Contar cuántas veces
aparecen dos letras iguales. Mostrarlas intercalándoles el signo “=”.*/
#include <stdio.h>

int main() {
    char c, ant;
    int repeticiones = 0;

    printf("Ingrese el texto terminado en punto:\n");
    ant = getchar();

    while (ant != '.') {
        c = getchar();
        if (c == ant && c != '.' && c != ' ') {
            repeticiones++;
            putchar(ant);
            putchar('=');
            putchar(c);
            ant = getchar(); // Saltar la segunda letra igual ya procesada
        } else {
            putchar(ant);
            ant = c;
        }
    }
    putchar('.'); // Termina con el punto
    printf("\nCantidad de veces que aparecen dos letras iguales: %d\n", repeticiones);
    return 0;
}

/*16. Leer un texto carácter por carácter terminando en punto. Reemplazar grupos “y”
por “ll”.*/

#include <stdio.h>

int main() {
    char c, ant;
    printf("Ingrese el texto terminado en punto:\n");
    ant = getchar();

    while (ant != '.') {
        c = getchar();
        if (ant == 'y') {
            putchar('l');
            putchar('l');
        } else {
            putchar(ant);
        }
        ant = c;
    }
    putchar('.'); // Termina con el punto
    printf("\n");
    return 0;
}

/*17. Leer un texto carácter por carácter terminando en punto. Contar palabras
terminadas en “n” y mostrarlas pasándolas al plural.*/
#include <stdio.h>

int main() {
    char palabra[100];
    int i = 0, contador = 0;
    char c;

    printf("Ingrese el texto terminado en punto:\n");
    c = getchar();

    while (c != '.') {
        if (c != ' ') {
            palabra[i] = c;
            i++;
        } else if (i > 0) { // Fin de palabra
            palabra[i] = '\0';
            if (palabra[i-1] == 'n' || palabra[i-1] == 'N') {
                contador++;
                printf("%ses ", palabra); // Plural: agrega "es"
            }
            i = 0;
        }
        c = getchar();
    }
    // Procesar la última palabra antes del punto
    if (i > 0) {
        palabra[i] = '\0';
        if (palabra[i-1] == 'n' || palabra[i-1] == 'N') {
            contador++;
            printf("%ses ", palabra);
        }
    }

    printf("\nCantidad de palabras terminadas en 'n' (pluralizadas): %d\n", contador);
    return 0;
}
