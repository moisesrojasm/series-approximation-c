//
// Archivo: main_nivel3.c
// Centro de Mando Nivel 3 (Motor de Tablas + Benchmark de Tiempo O(n))
//

#include <stdio.h>
#include <math.h>
#include <time.h> // Libreria para medir los ciclos de reloj de la CPU
#include "include/series_v3.h"

// =========================================================================
// ENRUTADOR MAESTRO NIVEL 3
// =========================================================================
double evaluar_serie_v3(int opcion, double x, double alpha, double a, int n) {
    switch(opcion) {
        case 1:  return serie_01_ln2_v3(n);
        case 2:  return serie_02_pi4_v3(n);
        case 3:  return serie_03_pi2_6_v3(n);
        case 4:  return serie_04_pi2_8_v3(n);
        case 5:  return serie_05_un_medio_v3(n);
        case 6:  return serie_06_tres_cuartos_v3(n);
        case 7:  return serie_07_exp_v3(x, n);
        case 8:  return serie_08_x_exp_v3(x, n);
        case 9:  return serie_09_x_x2_exp_v3(x, n);
        case 10: return serie_10_ln1plusx_v3(x, n);
        case 11: return serie_11_variante_log_v3(x, n);
        case 12: return serie_12_ln_x_v1_v3(x, n);
        case 13: return serie_13_ln_x_v2_v3(x, n);
        case 14: return serie_14_binomio_v3(x, alpha, n);
        case 15: return serie_15_a_potencia_x_v3(a, x, n);
        case 16: return serie_16_bernoulli_v3(n);
        case 17: return serie_17_euler_Ek_v3(n);
        case 18: return serie_18_euler_E2k_v3(n);
        case 19: return serie_19_seno_v3(x, n);
        case 20: return serie_20_coseno_v3(x, n);
        case 21: return serie_21_tangente_v3(x, n);
        case 22: return serie_22_secante_v3(x, n);
        case 23: return serie_23_cosecante_v3(x, n);
        case 24: return serie_24_arcsin_v3(x, n);
        case 25: return serie_25_arccos_v3(x, n);
        case 26: return serie_26_arctan_v3(x, n);
        case 27: return serie_27_senh_v3(x, n);
        case 28: return serie_28_cosh_v3(x, n);
        case 29: return serie_29_tanh_v3(x, n);
        case 30: return serie_30_csenh_v3(x, n);
        case 31: return serie_31_arctanh_v3(x, n);
        case 32: return serie_32_serie_combinada_v3(x, n);
        case 33: return serie_33_exp_seno_v3(x, n);
        default: return 0.0;
    }
}

// =========================================================================
// FUNCION PRINCIPAL
// =========================================================================
int main(int argc, char *argv[]) {
    int opcion;
    double alpha = 0.0, a = 0.0;
    double x_vals[3] = {0.0, 0.0, 0.0};
    int num_x = 1;

    // Saltos en potencias de 2 exigidos por la rubrica
    int n_octavas[] = {2, 4, 8, 16, 32, 64, 128, 256};

    do {
        printf("\n======================================================\n");
        printf("   MOTOR BENCHMARK (NIVEL 3 - OPTIMIZACION O(n)) \n");
        printf("======================================================\n");
        printf(" [01-06] Constantes      [19-26] Trigonometricas\n");
        printf(" [07-13] Exponenciales   [27-33] Hiperbolicas\n");
        printf(" [14-18] Especiales      [0] SALIR\n");
        printf("------------------------------------------------------\n");
        printf("Seleccione una funcion (1-33): ");

        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Error: Entrada invalida. Ingrese un numero.\n");
            continue;
        }

        if (opcion == 0) break;
        if (opcion < 1 || opcion > 33) continue;

        if ((opcion >= 7 && opcion <= 15) || (opcion >= 19 && opcion <= 33)) {
            printf("Ingrese 3 valores de 'x' separados por espacio (ej. 0.5 1.0 1.5): ");
            if (scanf("%lf %lf %lf", &x_vals[0], &x_vals[1], &x_vals[2]) != 3) {
                while (getchar() != '\n');
                x_vals[0] = 0.5; x_vals[1] = 1.0; x_vals[2] = 1.5;
            }
            num_x = 3;
        } else {
            num_x = 1;
        }

        if (opcion == 14) {
            printf("Ingrese el valor de alpha: ");
            scanf("%lf", &alpha);
        } else if (opcion == 15) {
            printf("Ingrese el valor de la base a: ");
            scanf("%lf", &a);
        }

        printf("\nGenerando Benchmark de Rendimiento...\n");

        for (int v = 0; v < num_x; v++) {
            if (num_x == 3) {
                printf("\n===================================================================================\n");
                printf(" Bloque: x = %f\n", x_vals[v]);
                printf("===================================================================================\n");
            }

            // Cabecera ampliada con métrica de Tiempo
            printf("%-6s | %-16s | %-16s | %-16s | %-15s\n", "n", "S_n(x)", "Delta_n(x)", "e_a(x)", "Tiempo (us)");
            printf("-----------------------------------------------------------------------------------\n");

            for (int i = 0; i < 8; i++) {
                int n_actual = n_octavas[i];
                int n_mitad = n_actual / 2;

                // 1. Benchmark de Tiempo (Corremos 1000 veces para tener una lectura medible)
                clock_t inicio = clock();
                double s_n = 0.0;
                for(int iter = 0; iter < 1000; iter++) {
                    s_n = evaluar_serie_v3(opcion, x_vals[v], alpha, a, n_actual);
                }
                clock_t fin = clock();

                // Tiempo en microsegundos (us) por evaluacion promedio
                double tiempo_us = ((double)(fin - inicio) / CLOCKS_PER_SEC) * 1000000.0 / 1000.0;

                // 2. Calculamos la mitad para el delta
                double s_n_mitad = evaluar_serie_v3(opcion, x_vals[v], alpha, a, n_mitad);

                // 3. Matematicas de Convergencia
                double delta = fabs(s_n - s_n_mitad);
                double max_val = fabs(s_n) > 1e-15 ? fabs(s_n) : 1e-15;
                double e_a = delta / max_val;

                // 4. Salida en formato tabla
                printf("%-6d | %-16.6f | %-16.6e | %-16.6e | %-15.4f\n", n_actual, s_n, delta, e_a, tiempo_us);
            }
        }
        printf("\n");

    } while (opcion != 0);

    return 0;
}