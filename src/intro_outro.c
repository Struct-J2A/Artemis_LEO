/*Implementación de banners y animaciones de consola.*/
#include <stdio.h>
#include <stdlib.h>
#include "funcion_global.h"
#include "intro_outro.h"

// Manejo de retardos y detección de teclas según el sistema operativo
#ifdef _WIN32
    #include <windows.h>
    #include <conio.h> // Para _kbhit() y _getch() en Windows
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #include <sys/select.h>

    #define SLEEP_MS(ms) usleep((ms) * 1000)
#endif



// Logo 1: La araña de la UTN en ASCII estándar
static void logo_utn_arania(void) {
    //limpiarPantalla();
    printf("  +===============================================+\n");
    printf("  |                                               |\n");
    printf("  |                .     ..     .                 |\n");
    printf("  |                -#    ##    #-                 |\n");
    printf("  |                 -##  ##  ##-                  |\n");
    printf("  |                    ####                       |\n");
    printf("  |              ################                 |\n");
    printf("  |                    ####                       |\n");
    printf("  |                 .##  ##  ##.                  |\n");
    printf("  |                .#    ##    #.                 |\n");
    printf("  |                '     ''     '                 |\n");
    printf("  |                                               |\n");
    printf("  +===============================================+\n");
    printf("\n          >> PRESIONA ENTER PARA INGRESAR <<          \n");
}
static void logo_utn_arania_C(void) {
    //limpiarPantalla();
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
    printf("  ██==============================================██  \n\n");
    printf("          >> PRESIONA ENTER PARA INGRESAR <<          \n\n");

}



// Logo 2: UTN FRRE en ASCII estándar
static void logo_utn_nombre(void) {
    // limpiarPantalla();
    printf("  +===============================================+\n");
    printf("  |                                               |\n");
    printf("  |                                               |\n");
    printf("  |   _  _ _____ _  _    _____ ___  ___  ___      |\n");
    printf("  |  | || |_   _| \\| |  |  ___| _ \\| _ \\| __|     |\n");
    printf("  |  | || | | | | .` |  |  _| |   /|   /| _|      |\n");
    printf("  |  | || | | | | |\\ |  | |   | |_\\| |_\\| |___    |\n");
    printf("  |   \\__/  |_| |_|\\_|  |_|   |_|\\_\\|_|\\_\\____|   |\n");
    printf("  |                                               |\n");
    printf("  |                                               |\n");
    printf("  +===============================================+\n");
    printf("\n          >> PRESIONA ENTER PARA INGRESAR <<          \n");
}
static void logo_utn_nombre_C(void) {
    // limpiarPantalla();
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
    printf("  ██==============================================██  \n\n");
    printf("          >> PRESIONA ENTER PARA INGRESAR <<          \n\n");
}



//Logo ARTEMIS "intro"
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
void logo_artemis_intro() { //Estilo "ANSI-Shadow"
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────────────┐\n");
    printf("│██▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀██│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌       █████╗ ██████╗ ████████╗███████╗███╗   ███╗██╗███████╗     ▐│\n");
    printf("│▌      ██╔══██╗██╔══██╗╚══██╔══╝██╔════╝████╗ ████║██║██╔════╝     ▐│\n");
    printf("│▌      ███████║██████╔╝   ██║   █████╗  ██╔████╔██║██║███████╗     ▐│\n");
    printf("│▌      ██╔══██║██╔══██╗   ██║   ██╔══╝  ██║╚██╔╝██║██║╚════██║     ▐│\n");
    printf("│▌      ██║  ██║██║  ██║   ██║   ███████╗██║ ╚═╝ ██║██║███████║     ▐│\n");
    printf("│▌      ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝╚═╝╚══════╝     ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌          ██╗    ██╗         ███████╗     ██████╗     ██╗         ▐│\n");
    printf("│▌         ██╔╝    ██║         ██╔════╝    ██╔═══██╗    ╚██╗        ▐│\n");
    printf("│▌        ██╔╝     ██║         █████╗      ██║   ██║     ╚██╗       ▐│\n");
    printf("│▌        ╚██╗     ██║         ██╔══╝      ██║   ██║     ██╔╝       ▐│\n");
    printf("│▌         ╚██╗    ███████╗    ███████╗    ╚██████╔╝    ██╔╝        ▐│\n");
    printf("│▌          ╚═╝    ╚══════╝    ╚══════╝     ╚═════╝     ╚═╝         ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌   SIMULADOR DE INSERCION Y ESTABILIDAD EN ORBITA TERRESTRE BAJA  ▐│\n");
    printf("│▌           UTN FRRE - Algoritmos y Estructuras de Datos           ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│██▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄██│\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}



//Logo ARTEMIS "Outro"
void mostrar_outro(void) {
    printf("\n");
    printf("                                                                    \n");
    printf("       █████╗ ██████╗ ████████╗███████╗███╗   ███╗██╗███████╗       \n");
    printf("      ██╔══██╗██╔══██╗╚══██╔══╝██╔════╝████╗ ████║██║██╔════╝       \n");
    printf("      ███████║██████╔╝   ██║   █████╗  ██╔████╔██║██║███████╗       \n");
    printf("      ██╔══██║██╔══██╗   ██║   ██╔══╝  ██║╚██╔╝██║██║╚════██║       \n");
    printf("      ██║  ██║██║  ██║   ██║   ███████╗██║ ╚═╝ ██║██║███████║       \n");
    printf("      ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝╚═╝╚══════╝       \n");
    printf("                                                                    \n");
    printf("          ██╗    ██╗         ███████╗     ██████╗     ██╗           \n");
    printf("         ██╔╝    ██║         ██╔════╝    ██╔═══██╗    ╚██╗          \n");
    printf("        ██╔╝     ██║         █████╗      ██║   ██║     ╚██╗         \n");
    printf("        ╚██╗     ██║         ██╔══╝      ██║   ██║     ██╔╝         \n");
    printf("         ╚██╗    ███████╗    ███████╗    ╚██████╔╝    ██╔╝          \n");
    printf("          ╚═╝    ╚══════╝    ╚══════╝     ╚═════╝     ╚═╝           \n");
    printf("                                                                    \n");
    printf("  ===============================================================   \n");
    printf("   [+] Maniobra completada. Cerrando telemetria de la Orion...      \n");
    printf("   [+] Gracias por utilizar el Simulador Artemis II.                \n");
    printf("   [+] Hasta la proxima mision!                                     \n");
    printf("  ==============================================================    \n\n");
}



//Logo UTN con nombre
void frre_arania_nombre(void) {
    printf("\n");
    printf("  ██▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀██  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░▄░░░░░▄▄░░░░░▄░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░▀█░░░░██░░░░█▀░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░▀█▄▄░██░▄▄█▀░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░░░░█▄██▄█░░░░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░██████████████░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░░░░█▀██▀█░░░░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░▄█▀▀░██░▀▀█▄░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░▄█░░░░██░░░░█▄░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░▀░░░░░▀▀░░░░░▀░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░╔╗░╔╦════╦═╗░╔╗░░░░╔═══╦═══╦═══╦═══╗░░░░░░▐  \n");
    printf("  ▌░░░░░░║║░║║╔╗╔╗║║╚╗║║░░░░║╔══╣╔═╗║╔═╗║╔══╝░░░░░░▐  \n");
    printf("  ▌░░░░░░║║░║╠╝║║╚╣╔╗╚╝║░░░░║╚══╣╚═╝║╚═╝║╚══╗░░░░░░▐  \n");
    printf("  ▌░░░░░░║║░║║░║║░║║╚╗║║╔══╗║╔══╣╔╗╔╣╔╗╔╣╔══╝░░░░░░▐  \n");
    printf("  ▌░░░░░░║╚═╝║░║║░║║░║║║╚══╝║║░░║║║╚╣║║╚╣╚══╗░░░░░░▐  \n");
    printf("  ▌░░░░░░╚═══╝░╚╝░╚╝░╚═╝░░░░╚╝░░╚╝╚═╩╝╚═╩═══╝░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ▌░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐  \n");
    printf("  ██▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄██  \n");
    printf("\n");
}



//otros
void marco_general(void) {  // 66 columnas libres - 20 filas libres
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────────────┐\n");
    printf("│██▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀██│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│▌                                                                  ▐│\n");
    printf("│██▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄██│\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

static int esperar_con_deteccion(double segundos) {
    int pasos = (int)(segundos / 0.05);

    fflush(stdout);

    for (int i = 0; i < pasos; i++) {
#ifdef _WIN32
        if (_kbhit()) {
            char tecla = _getch();

            if (tecla == '\r' || tecla == '\n') {
                return 1;
            }
        }
#else
        fd_set entrada;
        struct timeval espera = {0, 0};

        FD_ZERO(&entrada);
        FD_SET(STDIN_FILENO, &entrada);

        int disponible = select(
            STDIN_FILENO + 1,
            &entrada,
            NULL,
            NULL,
            &espera
        );

        if (disponible > 0) {
            char tecla;
            ssize_t leidos = read(STDIN_FILENO, &tecla, 1);

            if (leidos == 0) {
                return 1;
            }

            if (leidos > 0 && (tecla == '\n' || tecla == '\r')) {
                return 1;
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
        limpiarPantalla();
        logo_utn_arania_C();
        if (esperar_con_deteccion(1.0)) {
            break;
        }

        // 2. Mostrar letras UTN FRRE
        limpiarPantalla();
        logo_utn_nombre_C();
        if (esperar_con_deteccion(1.0)) {
            break;
        }
    }

    limpiarPantalla();
    printf("\n<< Cargando el programon Artemis... >>\n");
    SLEEP_MS(1000);
}

/* // MAIN DE PRUEBAS
int main() {
    //funciones de generacion general:
    configurar_terminal();

    //inicio de programa
    logo_utn_animado();
    // marco_general();
    // logo_utn_arania_C();
    // logo_utn_nombre_C();
    // logo_artemis_intro();
    // mostrar_outro();
    // frre_arania_nombre();
    return 0;
} */

/* 
gcc src/intro_outro.c src/funcion_global.c -o bin/win/intro_outro.exe -lm ; .\bin\win\intro_outro.exe

cls
"D:\GoogleDrive\_Universidad\UTN-2026\AED 2026\Laboratorio_C\TFI_LabC_Artemis\Artemis_LEO\bin\win\intro_outro.exe"

*/

//ⒶⓇⓉⒺⓂⒾⓈ ~ ⓁⒺⓄ

/**
 *    ┏━┓┏━┓╺┳╸┏━╸┏┳┓╻┏━┓         ╻  ┏━╸┏━┓
 *    ┣━┫┣┳┛ ┃ ┣╸ ┃┃┃┃┗━┓   ┏━┛   ┃  ┣╸ ┃ ┃
 *    ╹ ╹╹┗╸ ╹ ┗━╸╹ ╹╹┗━┛         ┗━╸┗━╸┗━┛
 */

/**
 *    ╭─╮╭─╮╶┬╴╭─╴╭┬╮╷╭─╮         ╷  ╭─╴╭─╮
 *    ├─┤├┬╯ │ ├╴ ││││╰─╮   ╭─╯   │  ├╴ │ │
 *    ╵ ╵╵╰╴ ╵ ╰─╴╵ ╵╵╰─╯         ╰─╴╰─╴╰─╯
 */
/*
     ▄▄▄     ▄▄▄▄▄▄▄▄    ▄▄▄▄▄▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄▄▄▄ ▄▄▄▄▄      ▄▄▄  ▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄            ▄▄▄▄▄     ▄▄▄▄▄▄▄▄▄▄    ▄▄▄▄▄    
  ▄▀█▓▓░▄  ▌░▒▒▒▓▓▓█░▄  ▌ ░░▒▒▒▒▓▓█▌▀▄░▒▒▒▓▓▓█▓▀▄░▒▒▒█   ▄▒▒░░▀▀▄░▒▒▒▓█▀▄▀░▒▒▓▓█▓▒█▄        ▄▀░▒█▒▀    ▀▄░▒▒▒▓▓▓█▓  ▄▀░▒▒▒░░▄  
  ▌▓▒▀▒▒░  ▐▐░▒░▀▀▀▐▓░▌ ▀▀▀▀▌░▒▐▀▀▀   ▐░▒░▀▀▀▒█  ▐░▒▓▒▄▄▀░▓░░▌   ▐░▒░█  ▌░░░▀▀▀▀▀█▀          █▒▓▓▌       ▐░▒░▀▀▀▒█ ▐░░░▀▀▀░░░▌ 
 ▐▒▒▌ ▐░▒▌  ▐▓ ▐▌ ▄▀▄▀      ▌ ░▐      ▐▓ ▐▄▄▄    ▐▓ ▐██▒█▓░▓█    ▐▓ ▓▌  ▐   ▀▀▀▀▄            ▐ ▒▒▌       ▐▓ ▐▄▄▄   ▌▓ ▌   ▐ ▓▐ 
 ▐█▓▀▀▀▓█▌  ▌▒▓▓▀▀░▀▄       ▌▓ ▐      ▌▒▓▓▒░▌    ▌▒▓█▌▀▄▀█▓░▐▌   ▌▒▓▓▌   ▀▄▄▄█▓▓▒▀▄          ▐░▒▓▌       ▌▒▓▓▒░▌  ▐▓▒▐     ▌▒▓▌
 ▌▓▒▄▄▄▒▓▐  ▌░ ▐▀▀▄▓▒█      ▌ ▓▐      ▌░ ▐▀▀     ▌░ █    █░▓░█   ▌░ ▐▌  ▄▄▄▄ ▀▌▒░░▐▌         ▐ ░░▌   ▄   ▌░ ▐▀▀    ▐▒░▌   ▐░▒▐ 
 ▌░ ▌ ▐ ░▐  ▌  █   █░ █     ▌ ▒▐      ▌  ▀▄▄▄▀█ ▐▌  ▐▌   ▐▌░ ▐▌  ▌   █  ▐  ▀▄▄▀ ░ █▌         ▐   ▀▀▀▀ ▌  ▌  ▀▄▄▄▀█ ▐░░▀▄▄▄▀░░▌ 
▐  ▐   ▌  ▌▄▀  ▀▄ ▄▀   █   ▐    ▌   ▄▀        ▐ █    ▀▄  █    █▄▀  ░▓█▄ ▐▌      ▄▄▀          ▌        ▐▄▀        ▐  ▀▄     ▄▀  
▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀    ▀▀▀▀▀     ▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀    ▀▀▀▀  ▀▀▀▀▀▀   ▀▀▀▀▀▀▀            ▀▀▀▀▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀▀▀▀    ▀▀▀▀▀    
*/


/* Dibuja una linea desplazada hacia la derecha. */
static void linea_nave(int desplazamiento, const char *texto) {
    printf("%*s%s\n", desplazamiento, "", texto);
}

/* Animacion final y creditos del equipo. */
void mostrar_postcreditos(void) {
    const char *integrantes[] = {
        "Jose Marin",
        "Jose Pastori",
        "Guido Burgos"
    };

    limpiarPantalla();

    printf("\n\n");
    printf("          ARTEMIS LEO - CREDITOS\n");
    printf("          =====================\n\n");
    printf("              DESARROLLADO POR\n\n");
    fflush(stdout);

    /* Los nombres aparecen uno por uno. */
    for (int i = 0; i < 3; i++) {
        printf("              %s\n\n", integrantes[i]);
        fflush(stdout);
        SLEEP_MS(800);
    }

    SLEEP_MS(1500);

    /* La nave cruza la pantalla de izquierda a derecha. */
    for (int posicion = 0; posicion <= 40; posicion += 2) {
        limpiarPantalla();

        printf("\n     *                  .                *\n");
        printf("              .                 *\n");
        printf("\n          ORION: INICIANDO RETIRADA...\n\n");

        linea_nave(posicion, "          /\\");
        linea_nave(posicion, "     ____/  \\____");
        linea_nave(posicion, "<<< |    ORION   >");
        linea_nave(posicion, "     ----\\  /----");
        linea_nave(posicion, "          \\/");

        printf("\n\n       .                     *          .\n");

        fflush(stdout);
        SLEEP_MS(100);
    }

    /* Breve pausa antes de la explosion. */
    printf("\n          HOUSTON... TENEMOS UN PROBLEMA.\n");
    fflush(stdout);
    SLEEP_MS(1300);

    /* Explosion que aumenta de tamano. */
    for (int cuadro = 0; cuadro < 3; cuadro++) {
        limpiarPantalla();
        printf("\n\n\n");

        if (cuadro == 0) {
            printf("                         \\ | /\n");
            printf("                          ***\n");
            printf("                         / | \\\n");
        } else if (cuadro == 1) {
            printf("                       \\  |  /\n");
            printf("                     -- ***** --\n");
            printf("                       *******\n");
            printf("                     -- ***** --\n");
            printf("                       /  |  \\\n");
        } else {
            printf("                   *      |      *\n");
            printf("                      \\   |   /\n");
            printf("                 * -- ********* -- *\n");
            printf("                     *** BOOM ***\n");
            printf("                 * -- ********* -- *\n");
            printf("                      /   |   \\\n");
            printf("                   *      |      *\n");
        }

        fflush(stdout);
        SLEEP_MS(450);
    }

    SLEEP_MS(700);
    limpiarPantalla();

    printf("\n\n");
    printf("       ==========================================\n");
    printf("                     ¡GRACIAS!\n");
    printf("       ==========================================\n\n");

    printf("           Por acompanarnos en esta mision.\n\n");

    for (int i = 0; i < 3; i++) {
        printf("                  %s\n", integrantes[i]);
    }

    printf("\n");
    printf("           UTN FRRe - Ingenieria en Sistemas\n");
    printf("           Algoritmos y Estructuras de Datos\n\n");

    printf("       La fisica salio bien. El estacionamiento no.\n\n");
    printf("       [Escena ficticia: no afecta la simulacion]\n\n");

    fflush(stdout);
}