/*Definición de constantes, estructuras y prototipos del escenario Artemis LEO.*/
#ifndef ARTEMIS_H
#define ARTEMIS_H

// Constantes físicas del problema
#define G_CONST 6.674e-11        // N*m^2/kg^2
#define MASA_TIERRA 5.972e24     // kg
#define RADIO_TIERRA 6371000.0   // m (6371 km)
#define PI 3.14159265358979323846
#define GRAVEDAD_G 9.80          // m/s^2

// Estructura para almacenar el estado de la nave Orion
typedef struct {
    double masa;            // kg
    double altitud;         // m
    double radio_orbital;   // m (RT + h)
    double velocidad_orb;   // m/s
    double periodo_s;       // segundos
    double periodo_min;     // minutos
    double aceleracion_c;   // m/s^2
    double ac_en_g;         // multiplo de g
} NaveOrion;

// Declaración de funciones
void inicializar_nave(NaveOrion *nave, double altitud_km, double masa_kg);
void calcular_telemetria_orbital(NaveOrion *nave);
double calcular_desviacion_impulso(double a_lateral, double tiempo_s);
void mostrar_reporte_completo(const NaveOrion *nave);

#endif