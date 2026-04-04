//
// Created by Moisés Rojas on 01/03/2026.
//

// Implementacion Nivel 2 (Validacion de Dominios y Overflow)

#include <stdio.h>
#include <math.h>
#include "../include/series_v2.h" // Vinculación con el contrato



double serie_07_exp_v2(double x, int n) {
    double exp_suma = 0;
    for (int i = 1; i <=n; i++) {
        double numerador = 1;
        double denominador = 1;
        for (int j = 1; j <= n; j++) {
            numerador *= x;
            denominador *= j;
            exp_suma += (numerador / denominador);
        }
    }
    return exp_suma;
}

double serie_08_x_exp_v2(double x, int n) {
    // TODO Quim: Misma advertencia de desbordamiento (overflow) que la 07.
    return 0.0;
}

double serie_09_x_x2_exp_v2(double x, int n) {
    // TODO Quim: Misma advertencia de desbordamiento que la 07.
    return 0.0;
}

double serie_10_ln1plusx_v2(double x, int n) {
    // TODO Quim: GUARDIA DE DOMINIO REQUERIDA.
    return 0.0;
}

double serie_11_variante_log_v2(double x, int n) {
    // TODO Quim: GUARDIA DE DOMINIO REQUERIDA.
    return 0.0;
}

// Variantes de Logaritmo de x (12 - 13)

double serie_12_ln_x_v1_v2(double x, int n) {
    // TODO JP: GUARDIA DE DOMINIO REQUERIDA.
    return 0.0;
}

double serie_13_ln_x_v2_v2(double x, int n) {
    // TODO JP: GUARDIA DE DOMINIO REQUERIDA.
    return 0.0;
}