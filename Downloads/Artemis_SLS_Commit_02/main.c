#include <stdio.h>
#include "artemis.h"

int main(void) {
    Configuracion config;
    ResultadoAscenso resultado;
    char entrada[80];
    char sobrante;
    int opcion;

    configuracion_inicial(&config);

    do {
        puts("\n===== SIMULADOR ARTEMIS SLS =====");
        puts("1. Ver configuracion inicial");
        puts("2. Simular ascenso del SLS");
        puts("0. Salir");
        printf("Seleccione una opcion: ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            puts("Fin de entrada.");
            break;
        }
        if (sscanf(entrada, " %d %c", &opcion, &sobrante) != 1) {
            puts("Opcion invalida.");
            opcion = -1;
        }

        switch (opcion) {
            case 1:
                mostrar_configuracion(&config);
                break;
            case 2:
                if (calcular_ascenso(&config, &resultado)) {
                    mostrar_resultados(&resultado);
                } else {
                    puts("Error: configuracion fisica no valida.");
                }
                break;
            case 0:
                puts("Fin del programa.");
                break;
            default:
                puts("Seleccione 0, 1 o 2.");
        }
    } while (opcion != 0);

    return 0;
}
