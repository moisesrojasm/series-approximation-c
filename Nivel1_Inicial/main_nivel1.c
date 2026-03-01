//
// Created by Moisés Rojas on 27/02/2026.
//

/**
 * @file main_nivel1.c
 * @brief Implementación de Nivel 1 (Inicial) para las 33 series matemáticas.
 * @details Calcula las aproximaciones usando fuerza bruta O(n^2).
 */

#include <stdio.h>

// 1. PROTOTIPOS DE FUNCIONES bla bla bla

// Constantes y Fracciones (01-06)
double serie_01_ln2(int n);
double serie_02_pi4(int n);
double serie_03_pi2_6(int n);
double serie_04_pi2_8(int n);
double serie_05_un_medio(int n);
double serie_06_tres_cuartos(int n);

// Exponenciales y Logaritmos (07-13)
double serie_07_exp(double x, int n);
double serie_08_x_exp(double x, int n);
double serie_09_x_x2_exp(double x, int n);
double serie_10_ln1plusx(double x, int n);
double serie_11_variante_log(double x, int n);
double serie_12_ln_x_v1(double x, int n);
double serie_13_ln_x_v2(double x, int n);

// Especiales: Binomio, Potencia, Bernoulli y Euler (14-18)
// JP, recuerda que la 14 requiere 'alpha' y la 15 requiere la base 'a'
double serie_14_binomio(double x, double alpha, int n);
double serie_15_a_potencia_x(double a, double x, int n);
double serie_16_bernoulli(int k);
double serie_17_euler_Ek(int k);
double serie_18_euler_E2k(int k);

// Trigonométricas e Inversas (19-26)
double serie_19_seno(double x, int n);
double serie_20_coseno(double x, int n);
double serie_21_tangente(double x, int n);
double serie_22_secante(double x, int n);
double serie_23_cosecante(double x, int n);
double serie_24_arcsin(double x, int n);
double serie_25_arccos(double x, int n);
double serie_26_arctan(double x, int n);

// Hiperbólicas y Varias (27-33)
double serie_27_senh(double x, int n);
double serie_28_cosh(double x, int n);
double serie_29_tanh(double x, int n);
double serie_30_csenh(double x, int n);
double serie_31_arctanh(double x, int n);
double serie_32_serie_combinada(double x, int n);
double serie_33_exp_seno(double x, int n);


// 2. FUNCIÓN PRINCIPAL (El centro de mando)

int main(int argc, char *argv[]) {
    int opcion, n;
    double x = 0.0, alpha = 0.0, a = 0.0, resultado = 0.0;

    do {
        printf("\n======================================================\n");
        printf("   CATALOGO DE SERIES MATEMATICAS (NIVEL 1) \n");
        printf("======================================================\n");
        printf(" [01-06] Constantes (ln(2), pi, fracciones)\n");
        printf(" [07-13] Exponenciales y Logaritmos\n");
        printf(" [14-15] Binomio y Potencia a^x\n");
        printf(" [16-18] Numeros de Bernoulli y Euler\n");
        printf(" [19-26] Trigonometricas e Inversas\n");
        printf(" [27-33] Hiperbolicas y Varias\n");
        printf(" [0] SALIR\n");
        printf("------------------------------------------------------\n");
        printf("Seleccione el numero de la funcion (1-33) o 0 para salir: ");

        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n'); // Limpia el buffer si meten letras
            printf("Error: Ingrese un numero valido.\n");
            continue;
        }

        if (opcion == 0) {
            printf("Saliendo del programa...\n");
            break;
        }

        if (opcion < 1 || opcion > 33) {
            printf("Opcion fuera de rango. Intente de nuevo.\n");
            continue;
        }

        // Pedimos el número de términos o límite 'k' (Esta aplica para todas las funciones)
        printf("Ingrese el numero de terminos o limite (n/k): ");
        scanf("%d", &n);

        // Solo pedimos 'x' si la función no es una constante o coeficiente
        if ((opcion >= 7 && opcion <= 15) || (opcion >= 19 && opcion <= 33)) {
            printf("Ingrese el valor de x: ");
            scanf("%lf", &x);
        }

        // Estas requieren parámetros extra
        if (opcion == 14) {
            printf("Ingrese el valor de alpha: ");
            scanf("%lf", &alpha);
        } else if (opcion == 15) {
            printf("Ingrese el valor de la base a: ");
            scanf("%lf", &a);
        }

        switch(opcion) {
            // Constantes
            case 1:  resultado = serie_01_ln2(n); break;
            // case 2:  resultado = serie_02_pi4(n); break;
            // case 3:  resultado = serie_03_pi2_6(n); break;
            // case 4:  resultado = serie_04_pi2_8(n); break;
            // case 5:  resultado = serie_05_un_medio(n); break;
            // case 6:  resultado = serie_06_tres_cuartos(n); break;

            // Exp y Log
            // case 7:  resultado = serie_07_exp(x, n); break;
            // case 8:  resultado = serie_08_x_exp(x, n); break;
            // case 9:  resultado = serie_09_x_x2_exp(x, n); break;
            // case 10: resultado = serie_10_ln1plusx(x, n); break;
            // case 11: resultado = serie_11_variante_log(x, n); break;
            case 12: resultado = serie_12_ln_x_v1(x, n); break;
            // case 13: resultado = serie_13_ln_x_v2(x, n); break;

            // Especiales
            // case 14: resultado = serie_14_binomio(x, alpha, n); break;
            // case 15: resultado = serie_15_a_potencia_x(a, x, n); break;
            // case 16: resultado = serie_16_bernoulli(n); break; // Usamos 'n' como 'k'
            // case 17: resultado = serie_17_euler_Ek(n); break;
            // case 18: resultado = serie_18_euler_E2k(n); break;

            // Trigonométricas
            // case 19: resultado = serie_19_seno(x, n); break;
            // case 20: resultado = serie_20_coseno(x, n); break;
            // case 21: resultado = serie_21_tangente(x, n); break;
            // case 22: resultado = serie_22_secante(x, n); break;
            // case 23: resultado = serie_23_cosecante(x, n); break;
            // case 24: resultado = serie_24_arcsin(x, n); break;
            // case 25: resultado = serie_25_arccos(x, n); break;
            // case 26: resultado = serie_26_arctan(x, n); break;

            // Hiperbólicas y Varias
            case 27: resultado = serie_27_senh(x, n); break;
            // case 28: resultado = serie_28_cosh(x, n); break;
            // case 29: resultado = serie_29_tanh(x, n); break;
            // case 30: resultado = serie_30_csenh(x, n); break;
            // case 31: resultado = serie_31_arctanh(x, n); break;
            // case 32: resultado = serie_32_serie_combinada(x, n); break;
            // case 33: resultado = serie_33_exp_seno(x, n); break;
        }

        // Impresión (genérica) del resultado
        printf("\n=> Resultado de la aproximacion: %.10f\n", resultado);

    } while (opcion != 0);

    return 0;
}


// 3. IMPLEMENTACIÓN DE FUNCIONES (Lógica Nivel 1: Fuerza Bruta)

// ZONA DE QUIM: Funciones 01 al 11

/**
 * @brief Implementacion Nivel 1 de ln(2)
 * @param n Numero de terminos
 * @return Aproximacion de ln(2)
 */
double serie_01_ln2(int n) {
    // Solución Quim
    return 0.0;
}

// ... [Quim: Agregar implementaciones 02 a la 11 aquí] ...


// ZONA DE JP: Funciones 12 al 22

/**
 * @brief Implementacion Nivel 1 de ln(x) Forma 1
 * @param x Valor real (x > 0)
 * @param n Numero de terminos
 * @return Aproximacion de ln(x)
 */
double serie_12_ln_x_v1(double x, int n) {
    // Solución JP
    return 0.0;
}

// ... [JP: Agregar implementaciones 13 a la 22 aquí] ...


// ZONA DE MOY: Funciones 23 al 33

/**
 * @brief Implementacion Nivel 1 de senh(x)
 * @param x Valor real
 * @param n Numero de terminos
 * @return Aproximacion del seno hiperbolico
 */
double serie_27_senh(double x, int n) {
    // Solución Moy
    return 0.0;
}
