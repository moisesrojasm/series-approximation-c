//
// Created by Moisés Rojas on 02/03/2026.
//

// Implementacion Nivel 3 (Optimizacion O(n) por Recurrencia)
// Para series Exponenciales, Trigonometricas e Hiperbolicas.

#include <stdio.h>
#include <math.h>
#include "../include/series_v3.h"

// Exponenciales Puras (07 - 09)

/**
 * @brief [O(n)] Serie de Taylor para e^x.
 * @details Utiliza recurrencia: t_i = t_{i-1} * (x / i).
 * @param x Exponente real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada de e^x.
 */
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
    // TODO Quim: Similar a la 07, pero no olvides el multiplicador 'x' inicial.
    return 0.0;
}

double serie_09_x_x2_exp_v3(double x, int n) {
    // TODO Quim: Agrupa terminos inteligentemente para mantener el O(n).
    return 0.0;
}


// Trigonometricas Base (19 - 22)

double serie_19_seno_v3(double x, int n) {
    // TODO JP: Recurrencia de salto doble (solo impares).
    return 0.0;
}

/**
 * @brief [O(n)] Serie de Maclaurin para cos(x).
 * @details Recurrencia de salto doble par.
 */
double serie_20_coseno_v3(double x, int n) {
    if (n <= 0) return 0.0;

    x = fmod(x, 2.0 * M_PI);

    // El termino 0 del coseno siempre es 1 (x^0 / 0!)
    double cx = 1.0;
    double termino_anterior = 1.0;
    double x_cuadrada = x * x;

    // Motor O(n). Arrancamos en i = 1 porque ya tenemos el termino 0
    for (int i = 1; i < n; i++) {
        // Los denominadores del salto doble par
        double divisor = (2.0 * i - 1.0) * (2.0 * i);

        // Recurrencia directa
        termino_anterior = -termino_anterior * x_cuadrada / divisor;

        cx += termino_anterior;
    }

    return cx;
}

double serie_21_tangente_v3(double x, int n) {
    // TODO JP: La serie de la tangente usa Numeros de Bernoulli.
    return 0.0;
}

double serie_22_secante_v3(double x, int n) {
    // TODO JP: La secante depende de los Numeros de Euler.
    return 0.0;
}


// Inversas e Hiperbolicas (23 - 31, 33)

double serie_23_cosecante_v3(double x, int n) {
    // TODO Moy: Usa Bernoulli nuevamente. Coordinar con JP.
    return 0.0;
}

double serie_24_arcsin_v3(double x, int n) {
    // TODO Moy: La recurrencia aqui es una bestia hermosa.
    return 0.0;
}

double serie_25_arccos_v3(double x, int n) {
    // TODO Moy: TRUCO DE INGENIERIA -> arccos(x) = PI/2 - arcsin(x).
    return 0.0;
}

double serie_26_arctan_v3(double x, int n) {
    // TODO Moy: Recurrencia para la arcotangente.
    return 0.0;
}

double serie_27_senh_v3(double x, int n) {
    // TODO Moy: Identica a la recurrencia de tu Seno(19),
    return 0.0;
}

double serie_28_cosh_v3(double x, int n) {
    // TODO Moy: Identica a la recurrencia del Coseno(20) de JP,
    return 0.0;
}

double serie_29_tanh_v3(double x, int n) {
    // TODO Moy: Usa Numeros de Bernoulli. Coordinar con JP.
    return 0.0;
}

double serie_30_csenh_v3(double x, int n) {
    return 0.0;
}

double serie_31_arctanh_v3(double x, int n) {
    // TODO Moy: Identica al arctan(26), pero sin alternancia de signos.
    return 0.0;
}

double serie_33_exp_seno_v3(double x, int n) {
    return 0.0;
}