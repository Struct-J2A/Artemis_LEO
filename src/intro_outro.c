/*Implementación de banners y animaciones de consola.*/
#include <stdio.h>
#include "intro_outro.h"

void mostrar_intro(void) {
    printf("\n");
    printf("  ===============================================================\n");
    printf("   ____  ____  _____ _____ __  __ _____ ____       _     _____ ___ \n");
    printf("  / A  \\|  _ \\|_   _| ____|  \\/  |_   _/ ___|     | |   | ____/ _ \\\n");
    printf(" | /_\\ || |_) | | | |  _| | |\\/| | | | \\___ \\     | |   |  _|| | | |\n");
    printf(" | ___ ||  _ <  | | | |___| |  | | | |  ___) |    | |___| |__| |_| |\n");
    printf(" |_| |_||_| \\_\\ |_| |_____|_|  |_| |_| |____/     |_____|_____\\___/\n");
    printf("  ===============================================================\n");
    printf("    SIMULADOR DE INSERCION Y ESTABILIDAD EN ORBITA TERRESTRE BAJA\n");
    printf("                    UTN FRRE - CATEDRA AEDD                      \n");
    printf("  ===============================================================\n\n");
}

void mostrar_outro(void) {
    printf("\n");
    printf("  ===============================================================\n");
    printf("   [+] Maniobra completada. Cerrando telemetria de la Orion...\n");
    printf("   [+] Gracias por utilizar el Simulador Artemis II (Escenario 2).\n");
    printf("   [+] ¡Hasta la proxima mision!\n");
    printf("  ===============================================================\n\n");
}