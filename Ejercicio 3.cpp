/*3. Realiza un programa que determine si una cadena de caracteres ingresada
por el usuario es palíndromo (se lee igual de izquierda a derecha que de
derecha a izquierda).*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Biblioteca para usar tolower()

int esPalindromo(char *cadena) {
    int longitud = strlen(cadena);
    int i, j;

    // Convertir todos los caracteres a minúsculas
    for (i = 0; cadena[i]; i++) {
        cadena[i] = tolower(cadena[i]);
    }

    // Eliminar espacios en blanco del principio y final de la cadena
    i = 0;
    while (isspace(cadena[i])) i++;
    j = longitud - 1;
    while (isspace(cadena[j])) j--;

    // Comparar caracteres desde los extremos hacia el centro
    while (i < j) {
        if (cadena[i] != cadena[j]) {
            return 0; // No es un palíndromo
        }
        i++;
        j--;
    }

    return 1; // Es un palíndromo
}

int main() {
    char cadena[100];

    printf("Ingresa una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea

    if (esPalindromo(cadena)) {
        printf("La cadena '%s' es un palindromo.\n", cadena);
    } else {
        printf("La cadena '%s' no es un palindromo.\n", cadena);
    }

    return 0;
}
