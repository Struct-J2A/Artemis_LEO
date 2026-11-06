/*Menú principal y flujo general de la simulación Artemis (Escenario 2).*/

#include <stdio.h>
#include <stdlib.h>
#include "artemis.h"
#include "validaciones.h"
#include "funcion_global.h"
#include "intro_outro.h"

void mostrar_menu_opciones(void) {
    printf("\n=== MENU PRINCIPAL - MISION ARTEMIS LEO ===\n");
    printf("1. Telemetria Nominal de la Mision (h = 192 km, m = 33.000 kg)\n");
    printf("2. Simular Altitud Personalizada (Prueba de estabilidad)\n");
    printf("3. Calcular Desviacion por Pulso de Propulsor Lateral (Inciso d)\n");
    printf("4. Salir\n");
}

int main(void) {
    NaveOrion orion;
    int opcion;

    const double ALTITUD_NOMINAL = 192.0; // km
    const double MASA_NOMINAL = 33000.0;  // kg

    // 1. Mostrar logo interactivo de la UTN FRRE
    logo_utn_animado();

    do {
        limpiarPantalla();
        mostrar_intro();
        mostrar_menu_opciones();
        
        opcion = leer_entero("\nSeleccione una opcion (1-4): ", 1, 4);

        switch (opcion) {
            case 1:
                limpiarPantalla();
                inicializar_nave(&orion, ALTITUD_NOMINAL, MASA_NOMINAL);
                mostrar_reporte_completo(&orion);
                printf("\nPresione ENTER para volver al menu...");
                limpiar_buffer();
                break;

            case 2: {
                limpiarPantalla();
                printf("\n--- SIMULACION DE ALTITUD PERSONALIZADA ---\n");
                double nueva_altitud = leer_double("Ingrese altitud deseada en km (100.0 a 2000.0): ", 100.0, 2000.0);
                
                inicializar_nave(&orion, nueva_altitud, MASA_NOMINAL);
                mostrar_reporte_completo(&orion);
                printf("\nPresione ENTER para volver al menu...");
                limpiar_buffer();
                break;
            }

            case 3: {
                limpiarPantalla();
                printf("\n--- INCISO D: DESVIACION POR IMPULSO LATERAL ---\n");
                printf("Valores teoricos: a = 0.50 m/s^2 | dt = 10.0 s\n\n");
                
                double a_lat = leer_double("Ingrese aceleracion lateral en m/s^2 (0.01 a 10.0): ", 0.01, 10.0);
                double t_lat = leer_double("Ingrese tiempo de encendido en segundos (0.1 a 120.0): ", 0.1, 120.0);
                
                double desviacion = calcular_desviacion_impulso(a_lat, t_lat);
                
                printf("\n=======================================================\n");
                printf("           RESULTADO DE LA MANIOBRA LATERAL            \n");
                printf("=======================================================\n");
                printf(" Aceleracion transversal (a): %.2f m/s^2\n", a_lat);
                printf(" Tiempo de encendido (dt):    %.2f s\n", t_lat);
                printf(" Desviacion lateral instantanea (dy): %.2f metros\n", desviacion);
                printf("=======================================================\n");
                
                printf("\nPresione ENTER para volver al menu...");
                limpiar_buffer();
                break;
            }

            case 4:
                limpiarPantalla();
                mostrar_outro();
                break;
        }

    } while (opcion != 4);

    return 0;
}

/*
Guia de compilacion actualizada para el equipo:

compilacion en LINUX:
gcc src/main.c src/artemis.c src/funcion_global.c src/intro_outro.c src/validaciones.c -o bin/lin/executor -lm && ./bin/lin/executor

compilacion en WINDOWS:
gcc src/main.c src/artemis.c src/funcion_global.c src/intro_outro.c src/validaciones.c -o bin/win/executor.exe -lm ; .\bin\win\executor.exe

compilacion en MAC:
clang src/main.c src/artemis.c src/funcion_global.c src/intro_outro.c src/validaciones.c -o bin/mac/executor -lm && ./bin/mac/executor
*/