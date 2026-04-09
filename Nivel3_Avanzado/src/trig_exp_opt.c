//
// Created by Moisés Rojas on 02/03/2026.
//

// Implementacion Nivel 3 (Optimizacion O(n) por Recurrencia)
// Para series Exponenciales, Trigonometricas e Hiperbolicas.

#include <stdio.h>
#include <math.h>
#include "../include/series_v3.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// =========================================================================
// Exponenciales Puras (07 - 09)
// =========================================================================

double serie_07_exp_v3(double x, int n) {
    if (n <= 0) return 0.0;
    double exp_sum = 1.0;
    double termino_anterior = 1.0;
    for (int i = 1; i < n; i++) {
        termino_anterior = termino_anterior * (x / i);
        exp_sum += termino_anterior;
    }
    return exp_sum;
}

double serie_08_x_exp_v3(double x, int n) {
    if (n <= 0) return 0.0;
    double suma = x;
    double t = x;
    for (int i = 2; i <= n; i++) {
        t *= (x / i);
        suma += (i * t);
    }
    return suma;
}

double serie_09_x_x2_exp_v3(double x, int n) {
    if (n <= 0) return 0.0;
    double suma = x;
    double t = x;
    for (int i = 2; i <= n; i++) {
        t *= (x / i);
        suma += ((double)(i * i) * t);
    }
    return suma;
}

// =========================================================================
// Trigonometricas Base (19 - 22)
// =========================================================================

double serie_19_seno_v3(double x, int n) {
    if (n <= 0) return 0.0;
    x = fmod(x, 2.0 * M_PI);

    double t = x; // Termino 0
    double suma = t;
    double x2 = x * x;

    for (int i = 1; i < n; i++) {
        // Recurrencia de salto doble (solo impares)
        t = -t * x2 / ((2.0 * i) * (2.0 * i + 1.0));
        suma += t;
    }
    return suma;
}

double serie_20_coseno_v3(double x, int n) {
    if (n <= 0) return 0.0;
    x = fmod(x, 2.0 * M_PI);

    double cx = 1.0;
    double termino_anterior = 1.0;
    double x_cuadrada = x * x;

    for (int i = 1; i < n; i++) {
        double divisor = (2.0 * i - 1.0) * (2.0 * i);
        termino_anterior = -termino_anterior * x_cuadrada / divisor;
        cx += termino_anterior;
    }
    return cx;
}

double serie_21_tangente_v3(double x, int n) {
    if (n <= 0 || fabs(x) >= M_PI / 2.0) return 0.0;

    double suma = 0.0;
    double pot_neg4 = -4.0;
    double pot_4 = 4.0;
    double inv_fact = 0.5; // 1 / 2!
    double pot_x = x;      // x^1
    double x2 = x * x;

    for (int i = 1; i <= n; i++) {
        double B_2i = serie_16_bernoulli_v3(2 * i); // Super rapido por Memoization
        suma += B_2i * pot_neg4 * (1.0 - pot_4) * pot_x * inv_fact;

        // Actualizacion O(n) para la siguiente iteracion
        pot_neg4 *= -4.0;
        pot_4 *= 4.0;
        pot_x *= x2;
        inv_fact /= ((2.0 * i + 1.0) * (2.0 * i + 2.0));
    }
    return suma;
}

double serie_22_secante_v3(double x, int n) {
    if (n <= 0 || fabs(x) >= M_PI / 2.0) return 0.0;

    double suma = 1.0; // i=0
    double inv_fact = 1.0;
    double pot_x = 1.0;
    double x2 = x * x;

    for (int i = 1; i < n; i++) {
        double E_2i = serie_18_euler_E2k_v3(i);
        double signo = (i % 2 == 0) ? 1.0 : -1.0;

        pot_x *= x2;
        inv_fact /= ((2.0 * i - 1.0) * (2.0 * i));

        suma += signo * E_2i * pot_x * inv_fact;
    }
    return suma;
}

// =========================================================================
// Inversas e Hiperbolicas (23 - 31, 33)
// =========================================================================

double serie_23_cosecante_v3(double x, int n) {
    if (n <= 0 || x == 0.0 || fabs(x) >= M_PI) return 0.0;

    double suma = 1.0 / x;
    double pot_2 = 2.0;
    double inv_fact = 0.5;
    double pot_x = x;
    double x2 = x * x;

    for (int i = 1; i < n; i++) {
        double B_2i = serie_16_bernoulli_v3(2 * i);
        suma += 2.0 * (pot_2 - 1.0) * B_2i * pot_x * inv_fact;

        pot_2 *= 4.0; // Salta en potencias de 2^(2i-1)
        pot_x *= x2;
        inv_fact /= ((2.0 * i + 1.0) * (2.0 * i + 2.0));
    }
    return suma;
}

double serie_24_arcsin_v3(double x, int n) {
    if (n <= 0 || x <= -1.0 || x >= 1.0) return 0.0;

    double t = x; // i=0
    double suma = t;
    double x2 = x * x;

    for (int i = 1; i < n; i++) {
        // Recurrencia magistral del Arcoseno
        double num = (2.0 * i - 1.0) * (2.0 * i - 1.0);
        double den = (2.0 * i) * (2.0 * i + 1.0);
        t = t * x2 * (num / den);
        suma += t;
    }
    return suma;
}

double serie_25_arccos_v3(double x, int n) {
    if (n <= 0 || x <= -1.0 || x >= 1.0) return 0.0;
    // Truco de ingenieria directo O(n)
    return (M_PI / 2.0) - serie_24_arcsin_v3(x, n);
}

double serie_26_arctan_v3(double x, int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    double x2 = x * x;

    if (x > -1.0 && x < 1.0) {
        double t = x;
        suma = t;
        for (int i = 1; i < n; i++) {
            // Recurrencia: t_i = -t_{i-1} * x^2 * (2i-1)/(2i+1)
            t = -t * x2 * (2.0 * i - 1.0) / (2.0 * i + 1.0);
            suma += t;
        }
        return suma;
    }

    // Para |x| >= 1
    double inv_x2 = 1.0 / x2;
    double t = 1.0 / x;
    suma = t;
    for (int i = 1; i < n; i++) {
        t = -t * inv_x2 * (2.0 * i - 1.0) / (2.0 * i + 1.0);
        suma += t;
    }
    return (x >= 1.0) ? (M_PI / 2.0) - suma : (-M_PI / 2.0) - suma;
}

double serie_27_senh_v3(double x, int n) {
    if (n <= 0) return 0.0;
    double t = x;
    double suma = t;
    double x2 = x * x;
    for (int i = 1; i < n; i++) {
        // Identica al seno, pero sin el negativo
        t = t * x2 / ((2.0 * i) * (2.0 * i + 1.0));
        suma += t;
    }
    return suma;
}

double serie_28_cosh_v3(double x, int n) {
    if (n <= 0) return 0.0;
    double t = 1.0;
    double suma = t;
    double x2 = x * x;
    for (int i = 1; i < n; i++) {
        // Identica al coseno, pero sin el negativo
        t = t * x2 / ((2.0 * i - 1.0) * (2.0 * i));
        suma += t;
    }
    return suma;
}

double serie_29_tanh_v3(double x, int n) {
    if (n <= 0 || fabs(x) >= M_PI / 2.0) return 0.0;

    double suma = 0.0;
    double pot_4 = 4.0;
    double inv_fact = 0.5;
    double pot_x = x;
    double x2 = x * x;

    for (int i = 1; i <= n; i++) {
        double B_2i = serie_16_bernoulli_v3(2 * i);
        suma += B_2i * pot_4 * (pot_4 - 1.0) * pot_x * inv_fact;

        pot_4 *= 4.0;
        pot_x *= x2;
        inv_fact /= ((2.0 * i + 1.0) * (2.0 * i + 2.0));
    }
    return suma;
}

double serie_30_csenh_v3(double x, int n) {
    if (n <= 0 || x <= -1.0 || x >= 1.0) return 0.0;
    double t = x;
    double suma = t;
    double x2 = x * x;
    for (int i = 1; i < n; i++) {
        // Arcsin hiperbolico: Salto identico al arcsin pero alternando signo
        double num = (2.0 * i - 1.0) * (2.0 * i - 1.0);
        double den = (2.0 * i) * (2.0 * i + 1.0);
        t = -t * x2 * (num / den);
        suma += t;
    }
    return suma;
}

double serie_31_arctanh_v3(double x, int n) {
    if (n <= 0 || x <= -1.0 || x >= 1.0) return 0.0;
    double t = x;
    double suma = t;
    double x2 = x * x;
    for (int i = 1; i < n; i++) {
        // Arctan hiperbolico: Identica al arctan pero sin el negativo
        t = t * x2 * (2.0 * i - 1.0) / (2.0 * i + 1.0);
        suma += t;
    }
    return suma;
}

double serie_33_exp_seno_v3(double x, int n) {
    if (n <= 0) return 0.0;
    x = fmod(x, 2.0 * M_PI);
    double x2 = x * x;
    double suma = 1.0;
    if (n > 1) suma += x;
    if (n > 2) suma += x2 / 2.0;
    if (n > 4) suma -= (x2 * x2) / 8.0;
    if (n > 5) suma -= (x2 * x2 * x) / 15.0;
    return suma;
}