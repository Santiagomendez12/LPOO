/*5. Realiza un programa que reemplace todas las apariciones de un carácter
en una cadena de caracteres ingresada por el usuario por otro carácter
también ingresado por el usuario.*/

#include <stdio.h>
#include <string.h>

void reemplazarCaracteres(char *cadena, char caracterBuscar, char caracterReemplazo) {
    int longitud = strlen(cadena);

    for (int i = 0; i < longitud; i++) {
        if (cadena[i] == caracterBuscar) {
            cadena[i] = caracterReemplazo;
        }
    }
}

int main() {
    char cadena[100];
    char caracterBuscar, caracterReemplazo;

    printf("Ingresa una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingresa el carácter que deseas buscar: ");
    scanf(" %c", &caracterBuscar);

    printf("Ingresa el carácter de reemplazo: ");
    scanf(" %c", &caracterReemplazo);

    reemplazarCaracteres(cadena, caracterBuscar, caracterReemplazo);

    printf("La cadena actualizada es: %s\n", cadena);

    return 0;
}
