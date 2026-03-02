//
// Created by Moisés Rojas on 02/03/2026.
//

// Centro de Mando Nivel 3 (Produccion y Optimizacion O(n)).
// Ejecuta recurrencias, calcula Delta_n (Error de Aproximacion)
// y prepara la comparacion de eficiencia de ciclos.

#include <stdio.h>
#include <math.h>
#include "include/series_v3.h"

// Macro de alto rendimiento para calcular el valor absoluto (Delta_n)
#define ABS(x) ((x) < 0 ? -(x) : (x))

int main(int argc, char *argv[]) {
    int opcion, n;
    double x = 0.0, alpha = 0.0, a = 0.0;

    // Variables de Metricas de Rendimiento
    double resultado_opt = 0.0;
    double valor_real = 0.0;
    double delta_n = 0.0;

    do {
        printf("\n======================================================\n");
        printf("   CATALOGO DE SERIES (NIVEL 3 - PRODUCCION O(n)) \n");
        printf("======================================================\n");
        printf(" [19] Ejemplo de Prueba: sen(x)\n");
        printf(" [0] SALIR\n");
        printf("------------------------------------------------------\n");
        printf("Seleccione una funcion: ");

        // BARRERA 1: Higiene de buffer
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Error: Entrada invalida.\n");
            continue;
        }

        if (opcion == 0) {
            printf("Cerrando el entorno de produccion...\n");
            break;
        }

        // TODO Equipo: Implementar comparacion de eficiencia (for, while, do-while).
        // Sugerencia: Pueden agregar un sub-menu aqui que pregunte con que ciclo
        // desean ejecutar la funcion, o ejecutar los tres y medir el tiempo.

        // BARRERA 2: Limitador de iteraciones
        do {
            printf("Ingrese el numero de terminos (1 a 20 maximo): ");
            if (scanf("%d", &n) != 1) {
                while (getchar() != '\n');
                n = -1;
            }
        } while (n < 1 || n > 20);

        // BARRERA 3: Peticion de variables (A expandir por el equipo)
        if (opcion == 19) {
            printf("Ingrese el valor de x: ");
            scanf("%lf", &x);
        }

        // =====================================================================
        // ENRUTADOR Y CÁLCULO DE MÉTRICAS
        // =====================================================================
        switch(opcion) {
            case 19:
                resultado_opt = serie_19_seno_v3(x, n);
                valor_real = sin(x); // Obtenemos la "verdad absoluta" de math.h
                break;

            // TODO Equipo: Conectar las otras 32 funciones hacia _v3 y
            // asignar su respectiva funcion de math.h a 'valor_real'.

            default:
                printf("Opcion en construccion.\n");
                continue;
        }

        // Calculo del Error Absoluto de Aproximacion
        delta_n = ABS(valor_real - resultado_opt);

        // Impresion de Metricas Profesionales (Usamos %e para ver notacion cientifica en errores microscopicos)
        printf("\n---------------- REPORTE DE METRICAS ----------------\n");
        printf("=> Resultado Optimizado O(n): %.10f\n", resultado_opt);
        printf("=> Valor Real (math.h):       %.10f\n", valor_real);
        printf("=> Error Aproximacion (Delta): %.10e\n", delta_n);
        printf("------------------------------------------------------\n");

    } while (opcion != 0);

    return 0;
}