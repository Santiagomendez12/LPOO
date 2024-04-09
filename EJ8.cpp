/*8. Realizar un programa en el cual el usuario primero ingrese una oración
la cual puede estar en mayúscula o minúscula o de manera alternada
y luego pueda seleccionar que realice las siguientes acciones
a) Mostrar la oración toda en mayúscula
b) Mostrar la oración todo en minúsculas
c) Mostrar la oración alternando una mayúscula y una minúscula
D) Mostrar la oración comenzando todas las palabras con mayúscula*/

#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD 100


void convertirMayusculas(char *cadena) {
    int i = 0;
    while (cadena[i]) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] -= 32;
        }
        i++;
    }
}

void convertirMinusculas(char *cadena) {
    int i = 0;
    while (cadena[i]) {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] += 32;
        }
        i++;
    }
}

void alternarMayusculasMinusculas(char *cadena) {
    int i = 0;
    int alternar = 0;
    while (cadena[i]) {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) {
            if (alternar) {
                if (cadena[i] >= 'a' && cadena[i] <= 'z') {
                    cadena[i] -= 32;
                }
            } else {
                if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
                    cadena[i] += 32;
                }
            }
            alternar = !alternar;
        }
        i++;
    }
}

void capitalizarPalabras(char *cadena) {
    int i = 0;
    cadena[0] = cadena[0] >= 'a' && cadena[0] <= 'z' ? cadena[0] - 32 : cadena[0];
    for (i = 1; cadena[i]; i++) {
        if (cadena[i - 1] == ' ') {
            cadena[i] = cadena[i] >= 'a' && cadena[i] <= 'z' ? cadena[i] - 32 : cadena[i];
        } else {
            cadena[i] = cadena[i] >= 'A' && cadena[i] <= 'Z' ? cadena[i] + 32 : cadena[i];
        }
    }
}

int main() {
    char oraion[MAX_LONGITUD];
    char opcion;

    printf("Ingrese una oracion: ");
    fgets(oraion, MAX_LONGITUD, stdin);
    oraion[strcspn(oraion, "\n")] = '\0'; // Eliminar el salto de línea

    printf("\nSeleccione una opcion:\n");
    printf("a) Mostrar la oracion toda en mayuscula\n");
    printf("b) Mostrar la oracion toda en minuscula\n");
    printf("c) Mostrar la oracion alternando una mayuscula y una minoscula\n");
    printf("d) Mostrar la oracion comenzando todas las palabras con mayoscula\n");
    printf("Opcion: ");
    scanf(" %c", &opcion);

    switch (opcion) {
        case 'a':
        case 'A':
            convertirMayusculas(oraion);
            break;
        case 'b':
        case 'B':
            convertirMinusculas(oraion);
            break;
        case 'c':
        case 'C':
            alternarMayusculasMinusculas(oraion);
            break;
        case 'd':
        case 'D':
            capitalizarPalabras(oraion);
            break;
        default:
            printf("Opcion invalida.\n");
            return 1;
    }

    printf("La oracion modificada es: %s\n", oraion);

    return 0;
}
