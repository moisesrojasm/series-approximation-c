//
// Created by Moisés Rojas on 01/03/2026.
//

// Centro de Mando Nivel 2 (Motor de Tablas y Estabilizacion)

#include <stdio.h>
#include <math.h>
#include "include/series_v2.h" // Vinculacion con el contrato

// =========================================================================
// ENRUTADOR MAESTRO
// Encapsulamos el switch para poder llamarlo multiples veces en el bucle
// =========================================================================
double evaluar_serie(int opcion, double x, double alpha, double a, int n) {
    switch(opcion) {
        case 1:  return serie_01_ln2_v2(n);
        case 2:  return serie_02_pi4_v2(n);
        case 3:  return serie_03_pi2_6_v2(n);
        case 4:  return serie_04_pi2_8_v2(n);
        case 5:  return serie_05_un_medio_v2(n);
        case 6:  return serie_06_tres_cuartos_v2(n);
        case 7:  return serie_07_exp_v2(x, n);
        case 8:  return serie_08_x_exp_v2(x, n);
        case 9:  return serie_09_x_x2_exp_v2(x, n);
        case 10: return serie_10_ln1plusx_v2(x, n);
        case 11: return serie_11_variante_log_v2(x, n);
        case 12: return serie_12_ln_x_v1_v2(x, n);
        case 13: return serie_13_ln_x_v2_v2(x, n);
        case 14: return serie_14_binomio_v2(x, alpha, n);
        case 15: return serie_15_a_potencia_x_v2(a, x, n);
        case 16: return serie_16_bernoulli_v2(n); // k = n
        case 17: return serie_17_euler_Ek_v2(n);  // k = n
        case 18: return serie_18_euler_E2k_v2(n);  // k = n
        case 19: return serie_19_seno_v2(x, n);
        case 20: return serie_20_coseno_v2(x, n);
        case 21: return serie_21_tangente_v2(x, n);
        case 22: return serie_22_secante_v2(x, n);
        case 23: return serie_23_cosecante_v2(x, n);
        case 24: return serie_24_arcsin_v2(x, n);
        case 25: return serie_25_arccos_v2(x, n);
        case 26: return serie_26_arctan_v2(x, n);
        case 27: return serie_27_senh_v2(x, n);
        case 28: return serie_28_cosh_v2(x, n);
        case 29: return serie_29_tanh_v2(x, n);
        case 30: return serie_30_csenh_v2(x, n);
        case 31: return serie_31_arctanh_v2(x, n);
        case 32: return serie_32_serie_combinada_v2(x, n);
        case 33: return serie_33_exp_seno_v2(x, n);
        default: return 0.0;
    }
}

// =========================================================================
// FUNCION PRINCIPAL
// =========================================================================
int main(int argc, char *argv[]) {
    int opcion;
    double alpha = 0.0, a = 0.0;
    double x_vals[3] = {0.0, 0.0, 0.0}; // Arreglo para los 3 valores de x
    int num_x = 1; // Por defecto 1 (para constantes)

    // Saltos en potencias de 2 exigidos por la rubrica
    int n_octavas[] = {2, 4, 8, 16, 32, 64, 128, 256};

    do {
        printf("\n======================================================\n");
        printf("   MOTOR DE TABLAS (NIVEL 2 - ESTABILIZADO) \n");
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
        if (opcion < 1 || opcion > 33) {
            printf("Error: Opcion fuera de rango.\n");
            continue;
        }

        // PETICION CONDICIONAL DE VARIABLES
        if ((opcion >= 7 && opcion <= 15) || (opcion >= 19 && opcion <= 33)) {
            printf("La rubrica exige 3 valores de 'x'. Ingrese separados por espacio (ej. 0.5 1.0 1.5): ");
            if (scanf("%lf %lf %lf", &x_vals[0], &x_vals[1], &x_vals[2]) != 3) {
                while (getchar() != '\n');
                printf("Error de formato. Se usaran valores por defecto (0.5, 1.0, 1.5).\n");
                x_vals[0] = 0.5; x_vals[1] = 1.0; x_vals[2] = 1.5;
            }
            num_x = 3;
        } else {
            num_x = 1; // Constantes, Bernoulli y Euler no usan 'x'
        }

        if (opcion == 14) {
            printf("Ingrese el valor de alpha: ");
            scanf("%lf", &alpha);
        } else if (opcion == 15) {
            printf("Ingrese el valor de la base a: ");
            scanf("%lf", &a);
        }

        printf("\nGenerando tabla de resultados...\n");

        // MOTOR DE TABLAS
        for (int v = 0; v < num_x; v++) {
            if (num_x == 3) {
                printf("\n=================================================================\n");
                printf(" Bloque: x = %f\n", x_vals[v]);
                printf("=================================================================\n");
            }

            // Cabecera de la tabla
            printf("%-6s | %-20s | %-20s | %-20s\n", "n", "S_n(x)", "Delta_n(x)", "e_a(x)");
            printf("-----------------------------------------------------------------\n");

            for (int i = 0; i < 8; i++) {
                int n_actual = n_octavas[i];
                int n_mitad = n_actual / 2;

                // 1. Calculamos la serie actual
                double s_n = evaluar_serie(opcion, x_vals[v], alpha, a, n_actual);

                // 2. Calculamos la serie en n/2 para hallar el delta
                double s_n_mitad = evaluar_serie(opcion, x_vals[v], alpha, a, n_mitad);

                // 3. Calculamos Delta_n
                double delta = fabs(s_n - s_n_mitad);

                // 4. Calculamos Error Relativo (e_a)
                double max_val = fabs(s_n) > 1e-15 ? fabs(s_n) : 1e-15; // epsilon = 10^-15
                double e_a = delta / max_val;

                // 5. Imprimimos el renglon con precision cientifica
                printf("%-6d | %-20.6f | %-20.6e | %-20.6e\n", n_actual, s_n, delta, e_a);
            }
        }
        printf("\n");

    } while (opcion != 0);

    return 0;
}