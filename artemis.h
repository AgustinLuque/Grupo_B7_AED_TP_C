#ifndef ARTEMIS_H
#define ARTEMIS_H

/* Valores de referencia(ascenso del SLS) */
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

void configuracion_inicial(Configuracion *c);
void mostrar_configuracion(const Configuracion *c);

#endif
