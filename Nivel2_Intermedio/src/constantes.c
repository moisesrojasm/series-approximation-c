//
// Created by Moisés Rojas on 01/03/2026.
//

// Implementacion Nivel 2 (Prevencion de Overflow y Producto Incremental)

#include <stdio.h>
#include <math.h>
#include "../include/series_v2.h" // Vinculacion con el contrato

// =========================================================================
// Constantes y Fracciones (01 - 06)
// =========================================================================

double serie_01_ln2_v2(int n) {
    if (n <= 0) {
        printf("Error [Serie 01]: El numero de terminos debe ser mayor a 0.\n");
        return 0.0;
    }
    double ln2 = 0.0;
    for (int i = 1; i <= n; i++) {
        double signo = (i % 2 != 0) ? 1.0 : -1.0;
        ln2 += (signo / i);
    }
    return ln2;
}

double serie_02_pi4_v2(int n) {
    if (n <= 0) {
        printf("Error [Serie 02]: El numero de terminos debe ser mayor a 0.\n");
        return 0.0;
    }
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += (signo / (2.0 * i + 1.0));
    }
    return suma;
}

double serie_03_pi2_6_v2(int n) {
    if (n <= 0) {
        printf("Error [Serie 03]: El numero de terminos debe ser mayor a 0.\n");
        return 0.0;
    }
    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        suma += (1.0 / (double)(i * i));
    }
    return suma;
}

double serie_04_pi2_8_v2(int n) {
    if (n <= 0) {
        printf("Error [Serie 04]: El numero de terminos debe ser mayor a 0.\n");
        return 0.0;
    }
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double d = 2.0 * i + 1.0;
        suma += (1.0 / (d * d));
    }
    return suma;
}

double serie_05_un_medio_v2(int n) {
    if (n <= 0) {
        printf("Error [Serie 05]: El numero de terminos debe ser mayor a 0.\n");
        return 0.0;
    }
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += 1.0 / ((2.0 * i + 1.0) * (2.0 * i + 3.0));
    }
    return suma;
}

double serie_06_tres_cuartos_v2(int n) {
    if (n <= 0) {
        printf("Error [Serie 06]: El numero de terminos debe ser mayor a 0.\n");
        return 0.0;
    }
    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        suma += 1.0 / (double)(i * (i + 2));
    }
    return suma;
}

// =========================================================================
// Teoremas Especiales y Numeros de Bernoulli/Euler (14 - 18)
// =========================================================================

double serie_14_binomio_v2(double x, double alpha, int n) {
    if (n <= 0) return 0.0;

    if (x <= -1.0 || x >= 1.0) {
        printf("Error [Serie 14]: El valor de 'x' debe estar en el dominio (-1, 1).\n");
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double comb = 1.0, pot = 1.0;
        // Producto Incremental (Nivel 2)
        for (int j = 1; j <= i; j++) {
            comb *= (alpha - j + 1.0) / j;
            pot *= x;
        }
        suma += (comb * pot);
    }
    return suma;
}

double serie_15_a_potencia_x_v2(double a, double x, int n) {
    if (n <= 0) return 0.0;

    if (a <= 0.0) {
        printf("Error [Serie 15]: La base 'a' debe ser estrictamente mayor a 0.\n");
        return 0.0;
    }

    double lna = log(a);
    double val = x * lna;
    return serie_07_exp_v2(val, n);
}

double serie_16_bernoulli_v2(int k) {
    if (k < 0) return 0.0;

    if (k > 15) { // Guardia ligeramente expandida gracias al producto incremental
        printf("Alerta [Serie 16]: k=%d excedera la memoria por recursion. Abortando.\n", k);
        return 0.0;
    }

    if (k == 0) return 1.0;

    double suma = 0.0;
    for (int i = 0; i < k; i++) {
        // NIVEL 2: Producto incremental de la combinatoria k! / (i! * (k-i)!)
        double comb = 1.0;
        for (int p = 1; p <= i; p++) {
            comb *= (double)(k - p + 1) / p;
        }

        suma += comb * (serie_16_bernoulli_v2(i) / (k + 1.0 - i));
    }

    return -suma;
}

double serie_17_euler_Ek_v2(int k) {
    if (k < 0) return 0.0;

    if (k > 20) {
        printf("Alerta [Serie 17]: Limite computacional excedido.\n");
        return 0.0;
    }

    double pi = 3.14159265358979323846;

    // NIVEL 2: Producto incremental. Desaparece el (2k)!
    // factor_externo = (4/pi) * prod_{j=1}^{2k} (2j / pi)
    double factor_externo = 4.0 / pi;
    for (int j = 1; j <= 2 * k; j++) {
        factor_externo *= (2.0 * j) / pi;
    }

    double suma_infinita = 0.0;
    for (int n = 0; n < 50; n++) {
        double signo = (n % 2 == 0) ? 1.0 : -1.0;
        double base = 2.0 * n + 1.0;

        double den = 1.0;
        for(int j = 1; j <= (2 * k + 1); j++) den *= base;

        suma_infinita += (signo / den);
    }

    return factor_externo * suma_infinita;
}

double serie_18_euler_E2k_v2(int k) {
    if (k < 0) return 0.0;

    if (k > 15) {
        printf("Alerta [Serie 18]: Limite computacional excedido.\n");
        return 0.0;
    }

    double suma_exterior = 0.0;

    for (int m = 1; m <= 2 * k + 1; m++) {
        if (m % 2 == 0) continue;

        double signo_imaginario = (m % 4 == 1) ? 1.0 : -1.0;
        double suma_interior = 0.0;

        for (int j = 0; j <= m; j++) {
            // NIVEL 2: Producto incremental de la combinatoria
            double comb = 1.0;
            for (int p = 1; p <= j; p++) {
                comb *= (double)(m - p + 1) / p;
            }

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

    return suma_exterior;
}