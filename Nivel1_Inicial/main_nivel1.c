//
// Created by Moisés Rojas on 27/02/2026.
//

/**
 * @file main_nivel1.c
 * @brief Implementación de Nivel 1 (Inicial) para las 33 series matemáticas.
 * @details Calcula las aproximaciones usando fuerza bruta O(n^2).
 */

#include <stdio.h>

// =========================================================================
// 1. PROTOTIPOS DE FUNCIONES (El índice del programa)
// =========================================================================

// --- Constantes y Fracciones (01-06) ---
double serie_01_ln2(int n);
double serie_02_pi4(int n);
// ... [prototipos 03 al 06] ...

// --- Exponenciales y Logaritmos (07-13) ---
double serie_07_exp(double x, int n);
double serie_10_ln1plusx(double x, int n);
// ... [prototipos 08, 09, 11, 12, 13] ...

// --- Especiales: Bernoulli y Euler (14-18) ---
double serie_16_bernoulli(int k);
double serie_18_euler_E2k(int k);
// ... [prototipos 14, 15, 17] ...

// --- Trigonométricas e Inversas (19-26) ---
double serie_19_seno(double x, int n);
double serie_24_arcsin(double x, int n);
// ... [prototipos 20 al 26] ...

// --- Hiperbólicas y Varias (27-33) ---
double serie_27_senh(double x, int n);
double serie_30_csenh(double x, int n);
// ... [prototipos 28, 29, 31, 32, 33] ...


// =========================================================================
// 2. FUNCIÓN PRINCIPAL (Donde elegimos que función ejecutar)
// =========================================================================
int main(int argc, char *argv[]) {
    int opcion, n;
    double x = 0.0, resultado = 0.0;

    do {
        printf("\n--- CATALOGO DE SERIES (NIVEL 1) ---\n");
        printf("1. ln(2)\n");
        printf("7. e^x\n");
        printf("24. arcsin(x)\n");
        printf("27. senh(x)\n");
        printf("0. Salir\n");
        printf("Seleccione una funcion (1-33): ");
        scanf("%d", &opcion);

        if (opcion == 0) break;

        // Pedimos 'n' para todas las series
        printf("Ingrese el numero de terminos (n): ");
        scanf("%d", &n);

        // Nivel 1: Filtramos visualmente las que NO necesitan 'x'
        if (opcion >= 7 && opcion != 14 && opcion != 16 && opcion != 17 && opcion != 18) {
            printf("Ingrese el valor de x: ");
            scanf("%lf", &x);
        }

        // Selector de funciones
        switch(opcion) {
            case 1:  resultado = serie_01_ln2(n); break;
            case 7:  resultado = serie_07_exp(x, n); break;
            case 24: resultado = serie_24_arcsin(x, n); break;
            case 27: resultado = serie_27_senh(x, n); break;
            // ... [Agregar los 33 cases aquí] ...
            default: printf("Opcion no valida o no implementada.\n"); continue;
        }

        printf("\n=> Resultado de la aproximacion: %.10f\n", resultado);

    } while (opcion != 0);

    return 0;
}


// =========================================================================
// 3. IMPLEMENTACIÓN DE FUNCIONES (donde las programamos)
// =========================================================================


// Funciones de Quim (1 - 11)

/**
 * @brief Implementacion Nivel 1 de ln(2)
 * @param n Numero de terminos
 * @return Aproximacion de ln(2)
 */
double serie_01_ln2(int n) {
    // Solución
}

// Funciones de JP (12 - 22)

// Funciones de Moy (23 - 33)

/**
 * @brief Implementacion Nivel 1 de senh(x)
 * @param x Valor real
 * @param n Numero de terminos
 * @return Aproximacion del seno hiperbolico
 */
double serie_27_senh(double x, int n) {
    // Solución
}

// ... [Implementar el resto de las funciones aqui abajo] ...