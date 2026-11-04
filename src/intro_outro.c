/*Implementación de banners y animaciones de consola.*/
#include <stdio.h>
#include <stdlib.h>

// Manejo de retardos y detección de teclas según el sistema operativo
#ifdef _WIN32
    #include <windows.h>
    #include <conio.h> // Para _kbhit() y _getch() en Windows
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

// Logo 1: La araña de la UTN
static void logo_utn_arania(void) {
    limpiar_pantalla();
    printf("  ██==============================================██  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░▄░░░░░▄▄░░░░░▄░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░▀█░░░░██░░░░█▀░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░▀█▄▄░██░▄▄█▀░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░█▄██▄█░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░██████████████░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░█▀██▀█░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░▄█▀▀░██░▀▀█▄░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░▄█░░░░██░░░░█▄░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░▀░░░░░▀▀░░░░░▀░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ██==============================================██  \n");
    printf("\n          >> PRESIONA ENTER PARA INGRESAR <<          \n");
}

// Logo 2: UTN FRRE
static void logo_utn_nombre(void) {
    limpiar_pantalla();
    printf("  ██==============================================██  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░╔╗░╔╦════╦═╗░╔╗░░░░╔═══╦═══╦═══╦═══╗░░░░░||  \n");
    printf("  ||░░░░░║║░║║╔╗╔╗║║╚╗║║░░░░║╔══╣╔═╗║╔═╗║╔══╝░░░░░||  \n");
    printf("  ||░░░░░║║░║╠╝║║╚╣╔╗╚╝║░░░░║╚══╣╚═╝║╚═╝║╚══╗░░░░░||  \n");
    printf("  ||░░░░░║║░║║░║║░║║╚╗║║╔══╗║╔══╣╔╗╔╣╔╗╔╣╔══╝░░░░░||  \n");
    printf("  ||░░░░░║╚═╝║░║║░║║░║║║╚══╝║║░░║║║╚╣║║╚╣╚══╗░░░░░||  \n");
    printf("  ||░░░░░╚═══╝░╚╝░╚╝░╚═╝░░░░╚╝░░╚╝╚═╩╝╚═╩═══╝░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ||░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░||  \n");
    printf("  ██==============================================██  \n");
    printf("\n          >> PRESIONA ENTER PARA INGRESAR <<          \n");
}

// Revisa cada 50ms si se presionó la tecla Enter ('\r' o '\n')
static int esperar_con_deteccion(double segundos) {
    int pasos = (int)(segundos / 0.05);
    for (int i = 0; i < pasos; i++) {
#ifdef _WIN32
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == '\r' || tecla == '\n') {
                return 1; // Bandera para interrumpir la animación
            }
        }
#endif
        SLEEP_MS(50);
    }
    return 0;
}

// Bucle principal de la animación
void logo_utn_animado(void) {
    while (1) {
        // 1. Mostrar araña UTN
        logo_utn_arania();
        if (esperar_con_deteccion(1.0)) {
            break;
        }

        // 2. Mostrar letras UTN FRRE
        logo_utn_nombre();
        if (esperar_con_deteccion(1.0)) {
            break;
        }
    }

    limpiar_pantalla();
    printf("\n<< Cargando el programon Artemis... >>\n");
    SLEEP_MS(1000);
}

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