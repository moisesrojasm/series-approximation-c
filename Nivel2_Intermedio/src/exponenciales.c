//
// Created by Moisés Rojas on 01/03/2026.
//

// Implementacion Nivel 2 (Validacion de Dominios y Producto Incremental)

#include <stdio.h>
#include <math.h>
#include "../include/series_v2.h" // Vinculacion con el contrato

// =========================================================================
// Exponenciales (07 - 09) - Usando Producto Incremental O(n^2)
// =========================================================================

double serie_07_exp_v2(double x, int n) {
    if (n <= 0) {
        printf("Error [Serie 07]: El numero de terminos debe ser mayor a 0.\n");
        return 0.0;
    }

    double exp_suma = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;

        // Magia Nivel 2: Multiplicacion de fracciones paso a paso (x/1 * x/2 * ... x/i)
        // Esto previene que el denominador explote la memoria RAM.
        for (int j = 1; j <= i; j++) {
            fct *= (x / j);
        }
        exp_suma += fct;
    }
    return exp_suma;
}

double serie_08_x_exp_v2(double x, int n) {
    if (n <= 0) return 0.0;

    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double fct = 1.0;
        for (int j = 1; j <= i; j++) {
            fct *= (x / j);
        }
        suma += (i * fct);
    }
    return suma;
}

double serie_09_x_x2_exp_v2(double x, int n) {
    if (n <= 0) return 0.0;

    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double fct = 1.0;
        for (int j = 1; j <= i; j++) {
            fct *= (x / j);
        }
        suma += ((double)(i * i) * fct);
    }
    return suma;
}

// =========================================================================
// Logaritmos (10 - 13) - Con Guardias de Dominio Estrictas
// =========================================================================

double serie_10_ln1plusx_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: -1 < x <= 1
    if (x <= -1.0 || x > 1.0) {
        printf("Error [Serie 10]: Dominio matematico invalido. 'x' debe estar en (-1, 1].\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double pot = 1.0;
        for (int j = 1; j <= i; j++) pot *= x;
        double signo = (i % 2 != 0) ? 1.0 : -1.0;
        suma += (signo * pot / i);
    }
    return suma;
}

double serie_11_variante_log_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: -1 < x < 1
    if (x <= -1.0 || x >= 1.0) {
        printf("Error [Serie 11]: Dominio matematico invalido. 'x' debe estar en (-1, 1).\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double num = 1.0;
        int exp = 2 * i + 1;
        for (int j = 1; j <= exp; j++) num *= x;
        suma += (num / exp);
    }
    return 2.0 * suma;
}

double serie_12_ln_x_v1_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: x > 0
    if (x <= 0.0) {
        printf("Error [Serie 12]: Dominio invalido. 'x' debe ser estrictamente mayor a 0.\n");
        return 0.0;
    }

    double suma = 0.0;
    double val = (x - 1.0) / (x + 1.0);
    for (int i = 0; i < n; i++) {
        double num = 1.0;
        int exp = 2 * i + 1;
        for (int j = 1; j <= exp; j++) num *= val;
        suma += (num / exp);
    }
    return 2.0 * suma;
}

double serie_13_ln_x_v2_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: x >= 1/2
    if (x < 0.5) {
        printf("Error [Serie 13]: Dominio invalido. 'x' debe ser mayor o igual a 1/2.\n");
        return 0.0;
    }

    double suma = 0.0;
    double val = (x - 1.0) / x;
    for (int i = 1; i <= n; i++) {
        double num = 1.0;
        for (int j = 1; j <= i; j++) num *= val;
        suma += (num / i);
    }
    return suma;
}