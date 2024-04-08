/*6. Realiza un programa que determine si una cadena de caracteres ingresada
por el usuario es un anagrama de otra cadena también ingresada por el
usuario. Un anagrama es una palabra o frase formada por las mismas
letras de otra palabra o frase, pero en un orden diferente, como por
ejemplo "roma" y "amor". */

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Biblioteca para usar tolower()

int esAnagrama(char *cadena1, char *cadena2) {
    int longitud1 = strlen(cadena1);
    int longitud2 = strlen(cadena2);

    // Verificar si las cadenas tienen la misma longitud
    if (longitud1 != longitud2) {
        return 0; // No son anagramas
    }

    // Convertir ambas cadenas a minúsculas
    for (int i = 0; cadena1[i]; i++) {
        cadena1[i] = tolower(cadena1[i]);
    }
    for (int i = 0; cadena2[i]; i++) {
        cadena2[i] = tolower(cadena2[i]);
    }

    // Crear arreglos para contar las frecuencias de los caracteres
    int frecuencias1[26] = {0};
    int frecuencias2[26] = {0};

    // Contar las frecuencias de los caracteres en ambas cadenas
    for (int i = 0; cadena1[i]; i++) {
        if (isalpha(cadena1[i])) {
            frecuencias1[cadena1[i] - 'a']++;
        }
    }
    for (int i = 0; cadena2[i]; i++) {
        if (isalpha(cadena2[i])) {
            frecuencias2[cadena2[i] - 'a']++;
        }
    }

    // Comparar las frecuencias de los caracteres
    for (int i = 0; i < 26; i++) {
        if (frecuencias1[i] != frecuencias2[i]) {
            return 0; // No son anagramas
        }
    }

    return 1; // Son anagramas
}

int main() {
    char cadena1[100], cadena2[100];

    printf("Ingresa la primera cadena de caracteres: ");
    fgets(cadena1, sizeof(cadena1), stdin);
    cadena1[strcspn(cadena1, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingresa la segunda cadena de caracteres: ");
    fgets(cadena2, sizeof(cadena2), stdin);
    cadena2[strcspn(cadena2, "\n")] = '\0'; // Eliminar el salto de línea

    if (esAnagrama(cadena1, cadena2)) {
        printf("Las cadenas '%s' y '%s' son anagramas.\n", cadena1, cadena2);
    } else {
        printf("Las cadenas '%s' y '%s' no son anagramas.\n", cadena1, cadena2);
    }

    return 0;
}


