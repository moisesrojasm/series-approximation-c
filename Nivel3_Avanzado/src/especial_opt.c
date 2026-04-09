//
// Created by Moisés Rojas on 02/03/2026.
//

// Implementacion Nivel 3 (Optimizacion O(n) por Recurrencia y Memoization)
// Para Constantes, Logaritmos, Binomio y Series Especiales.

#include <stdio.h>
#include <math.h>
#include "../include/series_v3.h"

// =========================================================================
// ZONA QUIM: Constantes y Fracciones (01 - 06)
// =========================================================================

double serie_01_ln2_v3(int n) {
    if (n <= 0) return 0.0;
    double ln2 = 1.0;
    double t = 1.0;
    for (int i = 2; i <= n; i++) {
        t = -t * (i - 1.0) / i; // Recurrencia sin operador modulo
        ln2 += t;
    }
    return ln2;
}

double serie_02_pi4_v3(int n) {
    if (n <= 0) return 0.0;
    double suma = 1.0;
    double t = 1.0; // i=0 -> 1/1
    for (int i = 1; i < n; i++) {
        // Recurrencia: t_i = -t_{i-1} * (2i-1) / (2i+1)
        t = -t * (2.0 * i - 1.0) / (2.0 * i + 1.0);
        suma += t;
    }
    return suma;
}

double serie_03_pi2_6_v3(int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 1; i <= n; i++) suma += (1.0 / ((double)i * i));
    return suma;
}

double serie_04_pi2_8_v3(int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double d = 2.0 * i + 1.0;
        suma += (1.0 / (d * d));
    }
    return suma;
}

double serie_05_un_medio_v3(int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < n; i++) suma += 1.0 / ((2.0 * i + 1.0) * (2.0 * i + 3.0));
    return suma;
}

double serie_06_tres_cuartos_v3(int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 1; i <= n; i++) suma += 1.0 / ((double)i * (i + 2));
    return suma;
}

// =========================================================================
// ZONA QUIM: Logaritmos Iniciales (10 - 11)
// =========================================================================

double serie_10_ln1plusx_v3(double x, int n) {
    if (n <= 0 || x <= -1.0 || x > 1.0) return 0.0;
    double t = x; // t_1
    double suma = t;
    for (int i = 2; i <= n; i++) {
        // TODO Quim resuelto: Recurrencia O(n) estricta
        t = -t * x * (i - 1.0) / i;
        suma += t;
    }
    return suma;
}

double serie_11_variante_log_v3(double x, int n) {
    if (n <= 0 || x <= -1.0 || x >= 1.0) return 0.0;
    double t = x; // t_0
    double suma = t;
    double x2 = x * x; // Constante para evitar multiplicar x * x en el ciclo
    for (int i = 1; i < n; i++) {
        // Recurrencia: t_i = t_{i-1} * x^2 * (2i-1)/(2i+1)
        t = t * x2 * (2.0 * i - 1.0) / (2.0 * i + 1.0);
        suma += t;
    }
    return 2.0 * suma;
}

// =========================================================================
// ZONA JP: Logaritmos, Binomio, Bernoulli y Euler (12 - 18)
// =========================================================================

double serie_12_ln_x_v1_v3(double x, int n) {
    if (n <= 0 || x <= 0.0) return 0.0;
    double val = (x - 1.0) / (x + 1.0);
    double val2 = val * val;
    double t = val;
    double suma = t;
    for (int i = 1; i < n; i++) {
        t = t * val2 * (2.0 * i - 1.0) / (2.0 * i + 1.0);
        suma += t;
    }
    return 2.0 * suma;
}

double serie_13_ln_x_v2_v3(double x, int n) {
    if (n <= 0 || x < 0.5) return 0.0;
    double val = (x - 1.0) / x;
    double t = val; // t_1
    double suma = t;
    for (int i = 2; i <= n; i++) {
        t = t * val * (i - 1.0) / i;
        suma += t;
    }
    return suma;
}

double serie_14_binomio_v3(double x, double alpha, int n) {
    if (n <= 0 || x <= -1.0 || x >= 1.0) return 0.0;
    double t = 1.0; // t_0
    double suma = t;
    for (int i = 1; i < n; i++) {
        // TODO JP resuelto: Binomio en O(n)
        t = t * x * (alpha - i + 1.0) / i;
        suma += t;
    }
    return suma;
}

double serie_15_a_potencia_x_v3(double a, double x, int n) {
    if (n <= 0 || a <= 0.0) return 0.0;
    // Se apoya en la serie e^x que estara en el otro archivo
    double val = x * log(a);
    return serie_07_exp_v3(val, n);
}

double serie_16_bernoulli_v3(int k) {
    if (k < 0 || k > 50) return 0.0;
    // TODO JP resuelto: Programacion Dinamica (Memoization).
    // Mantiene los valores calculados en RAM.
    static double B[51] = {0};
    static int computado_hasta = 0;

    if (computado_hasta == 0) { B[0] = 1.0; computado_hasta = 1; }
    if (k < computado_hasta) return B[k]; // O(1) si ya se calculo

    for (int m = computado_hasta; m <= k; m++) {
        double suma = 0.0;
        for (int i = 0; i < m; i++) {
            double comb = 1.0;
            for (int p = 1; p <= i; p++) comb *= (double)(m - p + 1) / p;
            suma += comb * (B[i] / (m + 1.0 - i));
        }
        B[m] = -suma;
    }
    computado_hasta = k + 1;
    return B[k];
}

double serie_17_euler_Ek_v3(int k) {
    if (k < 0 || k > 20) return 0.0;
    // Memoization para evitar recalcular la asintotica
    static double E[21] = {0};
    static int calculado[21] = {0};

    if (calculado[k]) return E[k];

    double pi = 3.14159265358979323846;
    double factor = 4.0 / pi;
    for (int j = 1; j <= 2 * k; j++) factor *= (2.0 * j) / pi;

    double suma = 0.0;
    for (int n = 0; n < 30; n++) {
        double signo = (n % 2 == 0) ? 1.0 : -1.0;
        double base = 2.0 * n + 1.0;
        double den = 1.0;
        for(int j = 1; j <= (2 * k + 1); j++) den *= base;
        suma += (signo / den);
    }

    E[k] = factor * suma;
    calculado[k] = 1;
    return E[k];
}

double serie_18_euler_E2k_v3(int k) {
    if (k < 0 || k > 15) return 0.0;
    static double E2[16] = {0};
    static int calculado[16] = {0};

    if (calculado[k]) return E2[k];

    double suma_exterior = 0.0;
    for (int m = 1; m <= 2 * k + 1; m += 2) {
        double signo_imaginario = (m % 4 == 1) ? 1.0 : -1.0;
        double suma_interior = 0.0;
        for (int j = 0; j <= m; j++) {
            double comb = 1.0;
            for (int p = 1; p <= j; p++) comb *= (double)(m - p + 1) / p;
            double signo_j = (j % 2 == 0) ? 1.0 : -1.0;
            double base = m - 2.0 * j;
            double pot = 1.0;
            for(int p = 1; p <= (2 * k + 1); p++) pot *= base;
            suma_interior += comb * signo_j * pot;
        }
        double den = 1.0;
        for(int p = 1; p <= m; p++) den *= 2.0;
        den *= m;
        suma_exterior += signo_imaginario * (suma_interior / den);
    }
    E2[k] = suma_exterior;
    calculado[k] = 1;
    return E2[k];
}

// =========================================================================
// ZONA MOY: Series Combinadas Restantes (32)
// =========================================================================

double serie_32_serie_combinada_v3(double x, int n) {
    if (n <= 0 || x <= -1.0 || x >= 1.0) return 0.0;

    double h = 1.0;     // Numero armonico H_1
    double pot_x = x;   // x^1
    double suma = h * pot_x;

    // TODO Moy resuelto: H_i = H_{i-1} + 1/i, pot = -pot * x
    for (int i = 2; i <= n; i++) {
        h += 1.0 / i;
        pot_x = -pot_x * x; // Signo alternante implicito en la potencia
        suma += (h * pot_x);
    }
    return suma;
}