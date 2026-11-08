#include <stdio.h>
#include <math.h>
#include "artemis.h"

void configuracion_inicial(Configuracion *c) {
    *c = (Configuracion){A1_DEF, A2_DEF, T1_DEF, H_DEF, GRAVEDAD};
}

void mostrar_configuracion(const Configuracion *c) {
    printf("\n--- CONFIGURACION INICIAL ---\n");
    printf("Aceleracion fase 1: %.2f m/s2\n", c->a1);
    printf("Aceleracion fase 2: %.2f m/s2\n", c->a2);
    printf("Tiempo de separacion SRB: %.2f s\n", c->t1);
    printf("Altura de apagado: %.2f m\n", c->altura);
    printf("Gravedad: %.2f m/s2\n", c->g);
}

int calcular_ascenso(const Configuracion *c, ResultadoAscenso *r) {
    double distancia;

    if (c == NULL || r == NULL) return 0;
    if (c->a1 <= 0 || c->a2 <= 0 || c->t1 <= 0 || c->g <= 0) return 0;
    if (c->altura <= 0) return 0;

    /* Fase 1: movimiento uniformemente acelerado desde reposo. */
    r->v1 = c->a1 * c->t1;
    r->y1 = 0.5 * c->a1 * c->t1 * c->t1;

    /* La separacion de los SRB debe ocurrir antes del apagado. */
    if (c->altura <= r->y1) return 0;

    /* Fase 2: otra aceleracion constante hasta la altura indicada. */
    distancia = c->altura - r->y1;
    r->v2 = sqrt(r->v1 * r->v1 + 2.0 * c->a2 * distancia);
    r->t2 = (r->v2 - r->v1) / c->a2;

    /* Ascenso libre ideal con gravedad constante, hasta v = 0. */
    r->hmax = c->altura + r->v2 * r->v2 / (2.0 * c->g);
    r->gs = c->a1 / c->g;
    return 1;
}

void mostrar_resultados(const ResultadoAscenso *r) {
    puts("\n--- RESULTADOS DEL ASCENSO ---");
    printf("Velocidad al separar SRB: %.2f m/s\n", r->v1);
    printf("Altura al separar SRB: %.2f m\n", r->y1);
    printf("Duracion de la fase 2: %.2f s\n", r->t2);
    printf("Velocidad al apagar motores: %.2f m/s\n", r->v2);
    printf("Altura maxima ideal: %.2f m (%.2f km)\n", r->hmax, r->hmax / 1000.0);
    printf("Aceleracion de fase 1: %.3f g\n", r->gs);
    puts("Modelo simplificado: ascenso vertical y gravedad constante.");
}
