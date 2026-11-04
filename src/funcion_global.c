/*funciones de uso global*/
#include <stdlib.h>

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
