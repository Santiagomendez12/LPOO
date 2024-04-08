/*7. Realizar un programa que ingrese 5 palabras y devuelta la cadena mas
larga entre ellas*/

#include <stdio.h>
#include <string.h>

#define MAX_PALABRAS 5

int main() {
    char palabras[MAX_PALABRAS][100];
    int longitudes[MAX_PALABRAS];
    int maxLongitud = 0;
    int indiceMasLarga = 0;

    printf("Ingresa %d palabras:\n", MAX_PALABRAS);

    // Leer las palabras ingresadas por el usuario
    for (int i = 0; i < MAX_PALABRAS; i++) {
        printf("Palabra %d: ", i + 1);
        fgets(palabras[i], sizeof(palabras[i]), stdin);
        palabras[i][strcspn(palabras[i], "\n")] = '\0'; // Eliminar el salto de línea

        // Calcular la longitud de la palabra actual
        longitudes[i] = strlen(palabras[i]);

        // Actualizar la palabra más larga si es necesario
        if (longitudes[i] > maxLongitud) {
            maxLongitud = longitudes[i];
            indiceMasLarga = i;
        }
    }

    printf("\nLa palabra mas larga es: %s\n", palabras[indiceMasLarga]);

    return 0;
}
