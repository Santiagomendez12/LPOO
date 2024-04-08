/*2. Realiza un programa que cuente cuántas vocales tiene una cadena de
caracteres ingresada por el usuario.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Biblioteca para usar tolower()

int contarVocales(char *cadena) {
    int contador = 0;
    int longitud = strlen(cadena);

    for (int i = 0; i < longitud; i++) {
        char letra = tolower(cadena[i]); // Convertir a minúscula
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            contador++;
        }
    }

    return contador;
}

int main() {
    char cadena[100];

    printf("Ingresa una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea

    int cantidadVocales = contarVocales(cadena);

    printf("La cadena '%s' tiene %d vocales.\n", cadena, cantidadVocales);

    return 0;
}
