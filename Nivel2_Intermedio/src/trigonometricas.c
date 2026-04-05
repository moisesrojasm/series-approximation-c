//
// Created by Moisés Rojas on 01/03/2026.
//

// Implementacion Nivel 2 (Reduccion de argumento y estabilizacion)

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * @brief Implementacion Nivel 2 de sen(x)
 * @details Utiliza fmod() para reduccion de argumento y estabilizacion de memoria.
 * @param x Valor en radianes
 * @param n Numero de terminos
 * @return Aproximacion estabilizada del seno
 */
double serie_19_seno_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // MAGIA NIVEL 2: Reducimos x al rango de [-2PI, 2PI]
    // Si x es 1000, le quitamos todas las vueltas completas y deja solo lo util
    x = fmod(x, 2.0 * M_PI);

    double sx = 0.0;

    for (int i = 0; i < n; i++) {
        double signo = (i % 2 != 0) ? -1.0 : 1.0;
        double numerador = 1.0;
        double denominador = 1.0;

        for (int j = 1; j <= (2 * i + 1); j++) {
            numerador *= x;
            denominador *= j;
        }

        sx += (signo * numerador / denominador);
    }
    return sx;
}

/**
 * @brief Implementacion Nivel 2 de cos(x)
 * @details Utiliza fmod() para reduccion de argumento.
 */
double serie_20_coseno_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // Reduccion estricta de Nivel 2
    x = fmod(x, 2.0 * M_PI);

    double cx = 0.0;

    for (int i = 0; i < n; i++) {
        double signo = (i % 2 != 0) ? -1.0 : 1.0;
        double numerador = 1.0;
        double denominador = 1.0;

        for (int j = 1; j <= (2 * i); j++) {
            numerador *= x;
            denominador *= j;
        }

        cx += (signo * numerador / denominador);
    }

    return cx;
}

double serie_21_tangente_v2(double x, int n) {
    // TODO JP: Tangente tiene asíntotas. Validar que x no sea múltiplo de PI/2.
    return 0.0;
}

double serie_22_secante_v2(double x, int n) {
    // TODO JP: Validar dominio similar a la tangente.
    return 0.0;
}

// Inversas, Hiperbolicas y Varias (23 - 33)

double serie_23_cosecante_v2(double x, int n) {
    // TODO Moy: Validar que x no sea múltiplo de PI (divisiones entre cero).
    return 0.0;
}

double serie_24_arcsin_v2(double x, int n) {
    // TODO Moy: Validar dominio matemático: -1 <= x <= 1
    return 0.0;
}

double serie_25_arccos_v2(double x, int n) {
    // TODO Moy: Validar dominio matemático: -1 <= x <= 1
    return 0.0;
}

double serie_26_arctan_v2(double x, int n) {
    // TODO Moy: Validar dominio matemático: -1 <= x <= 1
    return 0.0;
}

double serie_27_senh_v2(double x, int n) {
    // TODO Moy: Funcion no periodica (crece muy rápido).
    // La protección viene de limitar 'n' y 'x' en el main.
    return 0.0;
}

double serie_28_cosh_v2(double x, int n) {
    return 0.0;
}

double serie_29_tanh_v2(double x, int n) {
    return 0.0;
}

double serie_30_csenh_v2(double x, int n) {
    return 0.0;
}

double serie_31_arctanh_v2(double x, int n) {
    // TODO Moy: Validar dominio estricto: -1 < x < 1
    return 0.0;
}

double serie_32_serie_combinada_v2(double x, int n) {
    return 0.0;
}

double serie_33_exp_seno_v2(double x, int n) {
    return 0.0;
}