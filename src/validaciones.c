/*Lectura segura y validación de datos.*/

#include <stdio.h>
#include "validaciones.h"

// Vacia el buffer de teclado descartando caracteres sobrantes (como 'enter' o texto erroneo)
void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Implementacion para leer enteros de forma segura
int leer_entero(const char *mensaje, int min, int max) {
    int valor;
    int leido;
    do {
        printf("%s", mensaje);
        leido = scanf("%d", &valor);
        limpiar_buffer(); // Limpia caracteres residuales
        if (leido != 1 || valor < min || valor > max) {
            printf("[ERROR] Entrada invalida. Ingrese un numero entero entre %d y %d.\n", min, max);
        }
    } while (leido != 1 || valor < min || valor > max);
    return valor;
}

// Implementacion para leer reales (double) de forma segura
double leer_double(const char *mensaje, double min, double max) {
    double valor;
    int leido;
    do {
        printf("%s", mensaje);
        leido = scanf("%lf", &valor);
        limpiar_buffer(); // Limpia caracteres residuales
        if (leido != 1 || valor < min || valor > max) {
            printf("[ERROR] Entrada invalida. Ingrese un valor numerico entre %.2f y %.2f.\n", min, max);
        }
    } while (leido != 1 || valor < min || valor > max);
    return valor;
}