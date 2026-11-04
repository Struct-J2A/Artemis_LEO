/*Lógica de cálculos físicos y movimiento circular uniforme (MCU).*/
#include <stdio.h>
#include <math.h>
#include "artemis.h"

void inicializar_nave(NaveOrion *nave, double altitud_km, double masa_kg) {
    nave->masa = masa_kg;
    nave->altitud = altitud_km * 1000.0; // km a metros
    nave->radio_orbital = RADIO_TIERRA + nave->altitud;
    calcular_telemetria_orbital(nave);
}

void calcular_telemetria_orbital(NaveOrion *nave) {
    double r = nave->radio_orbital;
    
    // a) Velocidad orbital: v = sqrt(G * MT / r)
    nave->velocidad_orb = sqrt((G_CONST * MASA_TIERRA) / r);
    
    // b) Período orbital: T = 2 * PI * r / v
    nave->periodo_s = (2.0 * PI * r) / nave->velocidad_orb;
    nave->periodo_min = nave->periodo_s / 60.0;
    
    // c) Aceleración centrípeta: ac = v^2 / r
    nave->aceleracion_c = (nave->velocidad_orb * nave->velocidad_orb) / r;
    nave->ac_en_g = nave->aceleracion_c / GRAVEDAD_G;
}

double calcular_desviacion_impulso(double a_lateral, double tiempo_s) {
    // d) Desviacion lateral: dy = 0.5 * a * dt^2
    return 0.5 * a_lateral * (tiempo_s * tiempo_s);
}

void mostrar_reporte_completo(const NaveOrion *nave) {
    printf("\n=======================================================\n");
    printf("         TELEMETRIA ORBITAL - NAVE ORION (LEO)         \n");
    printf("=======================================================\n");
    printf(" Masa de la Nave (m):        %.1f kg\n", nave->masa);
    printf(" Altitud Constante (h):      %.2f km (%.1f m)\n", nave->altitud / 1000.0, nave->altitud);
    printf(" Radio Orbital Total (r):    %.2f km (%.1f m)\n", nave->radio_orbital / 1000.0, nave->radio_orbital);
    printf("-------------------------------------------------------\n");
    printf(" a) Velocidad Orbital (v):   %.2f m/s (%.2f km/h)\n", nave->velocidad_orb, nave->velocidad_orb * 3.6);
    printf(" b) Periodo Orbital (T):     %.2f s (%.2f min)\n", nave->periodo_s, nave->periodo_min);
    printf(" c) Aceleracion Centripeta:  %.4f m/s^2 (%.3f g)\n", nave->aceleracion_c, nave->ac_en_g);
    printf("=======================================================\n");
}