/*funciones de uso global*/
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void configurar_terminal(void) {
#ifdef _WIN32
    // Configura la consola de Windows para soportar UTF-8 (Code Page 65001)
    SetConsoleOutputCP(65001);
#endif
    // En Linux y Mac no se necesita configuración extra, ya usan UTF-8 nativo.
}