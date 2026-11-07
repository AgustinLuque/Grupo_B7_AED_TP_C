#include <stdio.h>
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
