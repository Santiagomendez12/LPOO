/*1. Pedir al usuario que ingrese su nombre y luego imprimirlo en pantalla.*/

#include <stdio.h>

int main() {
    char nombre[50]; // Arreglo para almacenar el nombre

    printf("Ingresa tu nombre: ");
    fgets(nombre, sizeof(nombre), stdin); // Leer el nombre del usuario

    printf("Hola, %s", nombre); // Imprimir el nombre

    return 0;
}
