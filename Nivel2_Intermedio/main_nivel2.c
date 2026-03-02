//
// Created by Moisés Rojas on 01/03/2026.
//

// Centro de Mando Nivel 2 (Proteccion de entradas y ruteo)

#include <stdio.h>
#include "include/series_v2.h" // Vinculación con el contrato

int main(int argc, char *argv[]) {
    int opcion, n;
    double x = 0.0, alpha = 0.0, a = 0.0, resultado = 0.0;

    do {
        printf("\n======================================================\n");
        printf("   CATALOGO DE SERIES (NIVEL 2 - ESTABILIZADO) \n");
        printf("======================================================\n");
        printf(" [01-06] Constantes (ln(2), pi, fracciones)\n");
        printf(" [07-13] Exponenciales y Logaritmos\n");
        printf(" [14-15] Binomio y Potencia a^x\n");
        printf(" [16-18] Numeros de Bernoulli y Euler\n");
        printf(" [19-26] Trigonometricas e Inversas\n");
        printf(" [27-33] Hiperbolicas y Varias\n");
        printf(" [0] SALIR\n");
        printf("------------------------------------------------------\n");
        printf("Seleccione una funcion (1-33): ");

        // BARRERA 1: Higiene de buffer (evita bucles infinitos por letras)
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Error: Entrada invalida. Ingrese un numero.\n");
            continue;
        }

        if (opcion == 0) {
            printf("Cerrando el sistema Nivel 2...\n");
            break;
        }

        if (opcion < 1 || opcion > 33) {
            printf("Error: Opcion fuera de rango (1-33).\n");
            continue;
        }

        // BARRERA 2: Limitador de iteraciones (Protección contra Overflow)
        do {
            printf("Ingrese el numero de terminos o limite 'k' (1 a 20 maximo): ");
            if (scanf("%d", &n) != 1) {
                while (getchar() != '\n');
                n = -1; // Forzamos el error para repetir el ciclo
            }
            if(n < 1 || n > 20) {
                printf("Error de Dominio: Por seguridad de memoria, 'n' debe estar entre 1 y 20.\n");
            }
        } while (n < 1 || n > 20);

        // BARRERA 3: Petición condicional de variables
        if ((opcion >= 7 && opcion <= 15) || (opcion >= 19 && opcion <= 33)) {
            printf("Ingrese el valor de x: ");
            scanf("%lf", &x);
        }

        if (opcion == 14) {
            printf("Ingrese el valor de alpha: ");
            scanf("%lf", &alpha);
        } else if (opcion == 15) {
            printf("Ingrese el valor de la base a: ");
            scanf("%lf", &a);
        }

        // Enrutador Maestro a los archivos .c
        switch(opcion) {
            // ZONA QUIM
            case 1:  resultado = serie_01_ln2_v2(n); break;
            case 2:  resultado = serie_02_pi4_v2(n); break;
            case 3:  resultado = serie_03_pi2_6_v2(n); break;
            case 4:  resultado = serie_04_pi2_8_v2(n); break;
            case 5:  resultado = serie_05_un_medio_v2(n); break;
            case 6:  resultado = serie_06_tres_cuartos_v2(n); break;
            case 7:  resultado = serie_07_exp_v2(x, n); break;
            case 8:  resultado = serie_08_x_exp_v2(x, n); break;
            case 9:  resultado = serie_09_x_x2_exp_v2(x, n); break;
            case 10: resultado = serie_10_ln1plusx_v2(x, n); break;
            case 11: resultado = serie_11_variante_log_v2(x, n); break;

            // ZONA JP
            case 12: resultado = serie_12_ln_x_v1_v2(x, n); break;
            case 13: resultado = serie_13_ln_x_v2_v2(x, n); break;
            case 14: resultado = serie_14_binomio_v2(x, alpha, n); break;
            case 15: resultado = serie_15_a_potencia_x_v2(a, x, n); break;
            case 16: resultado = serie_16_bernoulli_v2(n); break;
            case 17: resultado = serie_17_euler_Ek_v2(n); break;
            case 18: resultado = serie_18_euler_E2k_v2(n); break;
            case 19: resultado = serie_19_seno_v2(x, n); break;
            case 20: resultado = serie_20_coseno_v2(x, n); break;
            case 21: resultado = serie_21_tangente_v2(x, n); break;
            case 22: resultado = serie_22_secante_v2(x, n); break;

            // ZONA MOY
            case 23: resultado = serie_23_cosecante_v2(x, n); break;
            case 24: resultado = serie_24_arcsin_v2(x, n); break;
            case 25: resultado = serie_25_arccos_v2(x, n); break;
            case 26: resultado = serie_26_arctan_v2(x, n); break;
            case 27: resultado = serie_27_senh_v2(x, n); break;
            case 28: resultado = serie_28_cosh_v2(x, n); break;
            case 29: resultado = serie_29_tanh_v2(x, n); break;
            case 30: resultado = serie_30_csenh_v2(x, n); break;
            case 31: resultado = serie_31_arctanh_v2(x, n); break;
            case 32: resultado = serie_32_serie_combinada_v2(x, n); break;
            case 33: resultado = serie_33_exp_seno_v2(x, n); break;
        }

        printf("\n=> Resultado Nivel 2: %.10f\n", resultado);

    } while (opcion != 0);

    return 0;
}