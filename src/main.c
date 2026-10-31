#include <stdio.h>
#include <stdlib.h>

void mostrar_menu_general(){
    printf("Menusaso\n");
}

int main(){
    mostrar_menu_general();
    return 0;
}

/*
compilacion en LINUX:
gcc src/main.c src/artemis.c src/intro_outro.c -o bin/lin/executor ; ./bin/lin/executor

compilacion en WINDOWS:
gcc src/main.c src/artemis.c src/intro_outro.c -o bin/win/executor.exe ; ./bin/win/executor.exe

compilacion en MAC:
clang src/main.c src/artemis.c src/intro_outro.c -o bin/mac/executor -lm && ./bin/mac/executor

*/