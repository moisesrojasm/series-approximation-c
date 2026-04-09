//
// Created by Moisés Rojas on 01/03/2026.
//

// Implementacion Nivel 2 (Reduccion de argumento, estabilizacion y producto incremental)

#include <stdio.h>
#include <math.h>
#include "../include/series_v2.h" // Vinculacion con el contrato

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// =========================================================================
// Trigonometricas (19 - 23)
// =========================================================================

double serie_19_seno_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // MAGIA NIVEL 2: Reducimos x al rango de [-2PI, 2PI] para evitar overflow
    x = fmod(x, 2.0 * M_PI);

    double sx = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        // Producto incremental: evita calcular el factorial (2i+1)! explícitamente
        for (int j = 1; j <= (2 * i + 1); j++) {
            fct *= (x / j);
        }
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        sx += (signo * fct);
    }
    return sx;
}

double serie_20_coseno_v2(double x, int n) {
    if (n <= 0) return 0.0;

    x = fmod(x, 2.0 * M_PI);

    double cx = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        // Producto incremental
        for (int j = 1; j <= (2 * i); j++) {
            fct *= (x / j);
        }
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        cx += (signo * fct);
    }
    return cx;
}

double serie_21_tangente_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: |x| < PI/2
    if (fabs(x) >= M_PI / 2.0) {
        printf("Error [Serie 21]: Dominio invalido. |x| debe ser menor a PI/2.\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double B_2i = serie_16_bernoulli_v2(2 * i);
        double pot_neg4 = 1.0, pot_4 = 1.0;
        for (int j = 1; j <= i; j++) { pot_neg4 *= -4.0; pot_4 *= 4.0; }

        // Producto incremental para x^(2i-1) / (2i)!
        double fct = 1.0;
        for(int j = 1; j <= (2 * i); j++) {
            if (j <= 2 * i - 1) fct *= (x / j);
            else fct *= (1.0 / j);
        }
        suma += (B_2i * pot_neg4 * (1.0 - pot_4) * fct);
    }
    return suma;
}

double serie_22_secante_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: |x| < PI/2
    if (fabs(x) >= M_PI / 2.0) {
        printf("Error [Serie 22]: Dominio invalido. |x| debe ser menor a PI/2.\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double E_2i = serie_18_euler_E2k_v2(i);
        double signo = (i % 2 == 0) ? 1.0 : -1.0;

        double fct = 1.0;
        for (int j = 1; j <= (2 * i); j++) fct *= (x / j);

        suma += (signo * E_2i * fct);
    }
    return suma;
}

double serie_23_cosecante_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: 0 < |x| < PI
    if (x == 0.0 || fabs(x) >= M_PI) {
        printf("Error [Serie 23]: Dominio invalido. 0 < |x| < PI.\n");
        return 0.0;
    }

    double suma = 1.0 / x;
    for (int i = 1; i < n; i++) {
        double B_2i = serie_16_bernoulli_v2(2 * i);
        double pot_2 = 1.0;
        for (int j = 1; j <= (2 * i - 1); j++) pot_2 *= 2.0;

        double fct = 1.0;
        for(int j = 1; j <= (2 * i); j++) {
           if (j <= 2 * i - 1) fct *= (x / j);
           else fct *= (1.0 / j);
        }
        suma += (2.0 * (pot_2 - 1.0) * B_2i * fct);
    }
    return suma;
}

// =========================================================================
// Inversas, Hiperbolicas y Varias (24 - 33)
// =========================================================================

double serie_24_arcsin_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: |x| < 1
    if (x <= -1.0 || x >= 1.0) {
        printf("Error [Serie 24]: Dominio invalido. |x| debe ser menor a 1.\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        // Producto incremental para el factor combinado: (2i)! / (4^i * i!^2)
        for (int j = 1; j <= i; j++) {
            fct *= (double)(2 * j - 1) / (2.0 * j);
        }

        double pot_x = x;
        for (int j = 1; j <= 2 * i; j++) pot_x *= x;

        suma += (fct * pot_x) / (2.0 * i + 1.0);
    }
    return suma;
}

double serie_25_arccos_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: |x| < 1
    if (x <= -1.0 || x >= 1.0) {
        printf("Error [Serie 25]: Dominio invalido. |x| debe ser menor a 1.\n");
        return 0.0;
    }

    double pi_medios = 1.57079632679489661923;
    double suma_interna = 0.0;

    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        // Producto incremental Nivel 2
        for (int j = 1; j <= i; j++) {
            fct *= (double)(2 * j - 1) / (2.0 * j);
        }

        double pot_x = x;
        for (int j = 1; j <= 2 * i; j++) pot_x *= x;

        suma_interna += (fct * pot_x) / (2.0 * i + 1.0);
    }
    return pi_medios - suma_interna;
}

double serie_26_arctan_v2(double x, int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    double pi_medios = 1.57079632679489661923;

    if (x > -1.0 && x < 1.0) {
        for (int i = 0; i < n; i++) {
            double num = 1.0;
            for (int j = 1; j <= (2 * i + 1); j++) num *= x;
            double signo = (i % 2 == 0) ? 1.0 : -1.0;
            suma += (signo * num / (2 * i + 1));
        }
        return suma;
    }

    for (int i = 0; i < n; i++) {
        double den_x = 1.0;
        for (int j = 1; j <= (2 * i + 1); j++) den_x *= x;
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += (signo / ((2 * i + 1) * den_x));
    }

    if (x >= 1.0) return pi_medios - suma;
    else return -pi_medios - suma;
}

double serie_27_senh_v2(double x, int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        for (int j = 1; j <= (2 * i + 1); j++) fct *= (x / j);
        suma += fct;
    }
    return suma;
}

double serie_28_cosh_v2(double x, int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        for (int j = 1; j <= (2 * i); j++) fct *= (x / j);
        suma += fct;
    }
    return suma;
}

double serie_29_tanh_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: |x| < PI/2
    if (fabs(x) >= M_PI / 2.0) {
        printf("Error [Serie 29]: Dominio invalido. |x| debe ser menor a PI/2.\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double B_2i = serie_16_bernoulli_v2(2 * i);
        double pot_4 = 1.0;
        for (int j = 1; j <= i; j++) pot_4 *= 4.0;

        double fct = 1.0;
        for(int j = 1; j <= (2 * i); j++) {
            if (j <= 2 * i - 1) fct *= (x / j);
            else fct *= (1.0 / j);
        }
        suma += (B_2i * pot_4 * (pot_4 - 1.0) * fct);
    }
    return suma;
}

double serie_30_csenh_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: |x| < 1
    if (x <= -1.0 || x >= 1.0) {
        printf("Error [Serie 30]: Dominio invalido. |x| debe ser menor a 1.\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        // Producto incremental
        for (int j = 1; j <= i; j++) {
            fct *= (double)(2 * j - 1) / (2.0 * j);
        }

        double pot_x = x;
        for (int j = 1; j <= 2 * i; j++) pot_x *= x;

        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += (signo * fct * pot_x) / (2.0 * i + 1.0);
    }
    return suma;
}

double serie_31_arctanh_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: |x| < 1
    if (x <= -1.0 || x >= 1.0) {
        printf("Error [Serie 31]: Dominio invalido. |x| debe ser menor a 1.\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double num = 1.0;
        for (int j = 1; j <= (2 * i + 1); j++) num *= x;
        suma += (num / (2 * i + 1));
    }
    return suma;
}

double serie_32_serie_combinada_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // GUARDIA DE DOMINIO: |x| < 1
    if (x <= -1.0 || x >= 1.0) {
        printf("Error [Serie 32]: Dominio invalido. |x| debe ser menor a 1.\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double h = 0.0;
        for (int j = 1; j <= i; j++) h += 1.0 / j;

        double pot = 1.0;
        for (int j = 1; j <= i; j++) pot *= x;

        double signo = (i % 2 != 0) ? 1.0 : -1.0;
        suma += (signo * h * pot);
    }
    return suma;
}

double serie_33_exp_seno_v2(double x, int n) {
    if (n <= 0) return 0.0;

    // Al depender del seno, estabilizamos el periodo
    x = fmod(x, 2.0 * M_PI);

    double suma = 1.0;
    if (n > 1) suma += x;
    if (n > 2) suma += (x * x) / 2.0;
    if (n > 4) suma -= (x * x * x * x) / 8.0;
    if (n > 5) suma -= (x * x * x * x * x) / 15.0;
    return suma;
}