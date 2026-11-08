#ifndef ARTEMIS_H
#define ARTEMIS_H

/* Valores de referencia del problema 1 (ascenso del SLS). */
#define A1_DEF 20.0
#define A2_DEF 12.5
#define T1_DEF 120.0
#define H_DEF 160000.0
#define GRAVEDAD 9.8

typedef struct {
    double a1;
    double a2;
    double t1;
    double altura;
    double g;
} Configuracion;

/* Resultados fisicos de una simulacion. */
typedef struct {
    double v1;    /* Velocidad cuando se separan los SRB (m/s). */
    double y1;    /* Altura cuando se separan los SRB (m). */
    double t2;    /* Duracion de la segunda fase (s). */
    double v2;    /* Velocidad al apagar los motores (m/s). */
    double hmax;  /* Altura maxima ideal despues del apagado (m). */
    double gs;    /* Aceleracion de fase 1 expresada en g. */
} ResultadoAscenso;

void configuracion_inicial(Configuracion *c);
void mostrar_configuracion(const Configuracion *c);
int calcular_ascenso(const Configuracion *c, ResultadoAscenso *r);
void mostrar_resultados(const ResultadoAscenso *r);

#endif
