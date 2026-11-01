/*Prototipos de las funciones de validación.*/

#ifndef VALIDACIONES_H
#define VALIDACIONES_H

// Limpia el buffer de entrada de la consola para evitar bucles infinitos
void limpiar_buffer(void);

// Lee un numero entero (int) garantizando que sea correcto y este dentro de un rango [min, max]
int leer_entero(const char *mensaje, int min, int max);

// Lee un numero con decimales (double) garantizando que sea correcto y este dentro de un rango [min, max]
double leer_double(const char *mensaje, double min, double max);

#endif