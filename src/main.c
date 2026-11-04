/*Menú principal y flujo general.*/

//importacion de bibliotecas de C
#include <stdio.h>
#include <stdlib.h>

//importacion de locales
#include "validaciones.h"
#include "artemis.h"
#include "funcion_global.h"

//definicion de funciones
void mostrar_menu_general(){
    printf("Menusaso\n");
}

//inicio programa
int main(){
    //logo_utn_animado();
    //limpiarPantalla();
    mostrar_menu_general();
    //limpiarPantalla();
    //mostrar_outro();
    return 0;
}

/*

Guia de compilación para cada computadora de cada integrante del equipo:
compilacion en LINUX:
gcc src/main.c src/artemis.c src/funcion_global.c src/intro_outro.c src/validaciones.c -o bin/lin/executor ; ./bin/lin/executor

compilacion en WINDOWS:
gcc src/main.c src/artemis.c src/funcion_global.c src/intro_outro.c src/validaciones.c -o bin/win/executor.exe ; ./bin/win/executor.exe

compilacion en MAC:
clang src/main.c src/artemis.c src/funcion_global.c src/intro_outro.c src/validaciones.c -o bin/mac/executor -lm && ./bin/mac/executor

*/