//
// Created by Moisés Rojas on 27/02/2026.
//

/**
 * @file main_nivel1.c
 * @brief Implementación de Nivel 1 (Inicial) para las 33 series matemáticas.
 * @details Calcula las aproximaciones usando fuerza bruta O(n^2).
 */

#include <stdio.h>

// 1. PROTOTIPOS DE FUNCIONES

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


// 2. FUNCIÓN PRINCIPAL

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
            case 7:  resultado = serie_07_exp(x, n); break;
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
            case 19: resultado = serie_19_seno(x, n); break;
            case 20: resultado = serie_20_coseno(x, n); break;
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

double serie_01_ln2(int n) {
    double suma = 0;
    for (int i = 1; i <= n; i++) {
        double signo = (i % 2 != 0) ? 1.0 : -1.0;
        suma += (signo / i);
    }
    return suma;
}

double serie_02_pi4(int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += (signo / (2.0 * i + 1.0));
    }
    return suma;
}

double serie_03_pi2_6(int n) {
    double suma = 0;
    for (int i = 1; i <= n; i++) suma += (1.0 / (double)(i * i));
    return suma;
}

double serie_04_pi2_8(int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double d = 2.0 * i + 1.0;
        suma += (1.0 / (d * d));
    }
    return suma;
}

double serie_05_un_medio(int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += 1.0 / ((2.0 * i + 1.0) * (2.0 * i + 3.0));
    }
    return suma;
}

double serie_06_tres_cuartos(int n) {
    double suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += 1.0 / (double)(i * (i + 2));
    }
    return suma;
}

double serie_07_exp(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double num = 1.0, den = 1.0;
        for (int j = 1; j <= i; j++) { num *= x; den *= j; }
        suma += (num / den);
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de x * e^x
 */
double serie_08_x_exp(double x, int n) {
    double suma = 0.0;

    for (int i = 1; i <= n; i++) {
        double num = i;
        double den = 1.0;

        for (int j = 1; j <= i; j++) {
            num *= x;
            den *= j;
        }
        suma += (num / den);
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de (x + x^2) * e^x
 */
double serie_09_x_x2_exp(double x, int n) {
    double suma = 0.0;

    for (int i = 1; i <= n; i++) {
        double num = (double)(i * i);
        double den = 1.0;

        // Calculamos x^i / i!
        for (int j = 1; j <= i; j++) {
            num *= x;
            den *= j;
        }
        suma += (num / den);
    }
    return suma;
}

double serie_10_ln1plusx(double x, int n) {
    double suma = 0;
    for (int i = 1; i <= n; i++) {
        double num = 1.0;
        for (int j = 1; j <= i; j++) num *= x;
        double signo = (i % 2 != 0) ? 1.0 : -1.0;
        suma += (signo * num / i);
    }
    return suma;
}

double serie_11_variante_log(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double num = 1.0;
        int exp = 2 * i + 1;
        for (int j = 1; j <= exp; j++) num *= x;
        suma += (num / exp);
    }
    return 2.0 * suma;
}

double serie_12_ln_x_v1(double x, int n) {
    double suma = 0;
    double val = (x - 1) / (x + 1);
    for (int i = 0; i < n; i++) {
        double num = 1.0;
        int exp = 2 * i + 1;
        for (int j = 1; j <= exp; j++) num *= val;
        suma += (num / exp);
    }
    return 2.0 * suma;
}

double serie_13_ln_x_v2(double x, int n) {
    double suma = 0;
    double val = (x - 1) / x;
    for (int i = 1; i <= n; i++) {
        double num = 1.0;
        for (int j = 1; j <= i; j++) num *= val;
        suma += (num / i);
    }
    return suma;
}

double serie_14_binomio(double x, double alpha, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double comb = 1.0, pot = 1.0;
        for (int j = 1; j <= i; j++) {
            comb *= (alpha - j + 1) / j;
            pot *= x;
        }
        suma += (comb * pot);
    }
    return suma;
}

#include <math.h>

/**
 * @brief Implementacion Nivel 1 de a^x
 * @details Validada. Excelente reutilizacion de codigo.
 */
double serie_15_a_potencia_x(double a, double x, int n) {
    double lna = log(a); // math.h
    double val = x * lna;
    return serie_07_exp(val, n);
}

/**
 * @brief Implementacion Nivel 1 de Bernoulli
 * @details ADVERTENCIA: Complejidad O(k!). Se congelara para k > 12.
 */
double serie_16_bernoulli(int k) {
    // Caso base de la formula
    if (k == 0) return 1.0;

    double suma = 0.0;
    for (int i = 0; i < k; i++) {
        // Combinatoria de fuerza bruta: k! / (i! * (k-i)!)
        double fact_k = 1.0, fact_i = 1.0, fact_ki = 1.0;
        for(int p = 1; p <= k; p++) fact_k *= p;
        for(int p = 1; p <= i; p++) fact_i *= p;
        for(int p = 1; p <= (k - i); p++) fact_ki *= p;
        double comb = fact_k / (fact_i * fact_ki);

        // La funcion se invoca a si misma para obtener B_i
        suma += comb * (serie_16_bernoulli(i) / (k + 1.0 - i));
    }

    return -suma;
}

/**
 * @brief Implementacion Nivel 1 de Euler Ek (Aproximacion Asintotica)
 */
double serie_17_euler_Ek(int k) {
    double pi = 3.14159265358979323846;

    // Multiplicador 1: 2^(2k+2)
    double term_2 = 1.0;
    for(int j = 1; j <= (2 * k + 2); j++) term_2 *= 2.0;

    // Multiplicador 2: (2k)!
    double term_fact = 1.0;
    for(int j = 1; j <= (2 * k); j++) term_fact *= j;

    // Denominador: pi^(2k+1)
    double term_pi = 1.0;
    for(int j = 1; j <= (2 * k + 1); j++) term_pi *= pi;

    double factor_externo = (term_2 * term_fact) / term_pi;

    // Sumatoria infinita aproximada a 50 terminos
    double suma_infinita = 0.0;
    for (int n = 0; n < 50; n++) {
        double signo = (n % 2 == 0) ? 1.0 : -1.0;
        double base = 2.0 * n + 1.0; // Numeros impares: 1, 3, 5...

        double den = 1.0;
        for(int j = 1; j <= (2 * k + 1); j++) den *= base;

        suma_infinita += (signo / den);
    }

    return factor_externo * suma_infinita;
}

/**
 * @brief Implementacion Nivel 1 de Euler E2k (Sumatoria Doble)
 * @details Extrae la parte real del operador imaginario i^{1-m}.
 */
double serie_18_euler_E2k(int k) {
    double suma_exterior = 0.0;

    for (int m = 1; m <= 2 * k + 1; m++) {
        // Si m es par, i^{1-m} es imaginario puro y la sumatoria interna da 0.
        // Solo procesamos los m impares para obtener la parte real.
        if (m % 2 == 0) continue;

        // Si m impar, i^{1-m} oscila entre 1 y -1
        double signo_imaginario = (m % 4 == 1) ? 1.0 : -1.0;

        double suma_interior = 0.0;
        for (int j = 0; j <= m; j++) {
            // Combinatoria (m en j)
            double fact_m = 1.0, fact_j = 1.0, fact_mj = 1.0;
            for(int p = 1; p <= m; p++) fact_m *= p;
            for(int p = 1; p <= j; p++) fact_j *= p;
            for(int p = 1; p <= (m - j); p++) fact_mj *= p;
            double comb = fact_m / (fact_j * fact_mj);

            double signo_j = (j % 2 == 0) ? 1.0 : -1.0;

            // Potencia: (m - 2j)^(2k+1)
            double base = m - 2.0 * j;
            double pot = 1.0;
            for(int p = 1; p <= (2 * k + 1); p++) pot *= base;

            suma_interior += comb * signo_j * pot;
        }

        // Denominador externo: 2^m * m
        double den = 1.0;
        for(int p = 1; p <= m; p++) den *= 2.0;
        den *= m;

        suma_exterior += signo_imaginario * (suma_interior / den);
    }

    return suma_exterior;
}

double serie_19_seno(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double num = 1.0, den = 1.0;
        for (int j = 1; j <= (2 * i + 1); j++) { num *= x; den *= j; }
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += (signo * num / den);
    }
    return suma;
}

double serie_20_coseno(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double num = 1.0, den = 1.0;
        for (int j = 1; j <= (2 * i); j++) { num *= x; den *= j; }
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += (signo * num / den);
    }
    return suma;
}

// 21-23 requieren Bernoulli/Euler. Se implementan invocando dichas funciones.

/**
 * @brief Implementacion Nivel 1 de tan(x)
 */
double serie_21_tangente(double x, int n) {
    double suma = 0.0;

    // La formula general empieza en n=1
    for (int i = 1; i <= n; i++) {
        double B_2i = serie_16_bernoulli(2 * i);

        // Calculamos (-4)^n y 4^n a fuerza bruta
        double pot_neg4 = 1.0, pot_4 = 1.0;
        for (int j = 1; j <= i; j++) {
            pot_neg4 *= -4.0;
            pot_4 *= 4.0;
        }

        // Calculamos x^(2n-1) y (2n)! a fuerza bruta
        double pot_x = 1.0, fact_2i = 1.0;
        for (int j = 1; j <= (2 * i - 1); j++) pot_x *= x;
        for (int j = 1; j <= (2 * i); j++) fact_2i *= j;

        suma += (B_2i * pot_neg4 * (1.0 - pot_4) * pot_x) / fact_2i;
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de sec(x)
 */
double serie_22_secante(double x, int n) {
    double suma = 0.0;

    for (int i = 0; i < n; i++) {
        // En la formula, la sumatoria depende de E_2n.
        // Nuestra funcion serie_18 ya calcula E_2k pasandole k.
        double E_2i = serie_18_euler_E2k(i);
        double signo = (i % 2 == 0) ? 1.0 : -1.0;

        // Calculamos x^(2n) y (2n)! a fuerza bruta
        double pot_x = 1.0, fact_2i = 1.0;
        for (int j = 1; j <= (2 * i); j++) {
            pot_x *= x;
            fact_2i *= j;
        }

        suma += (signo * E_2i * pot_x) / fact_2i;
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de csc(x)
 */
double serie_23_cosecante(double x, int n) {
    double suma = 1.0 / x;

    for (int i = 1; i < n; i++) {
        double B_2i = serie_16_bernoulli(2 * i);

        // Calculamos 2^(2n-1)
        double pot_2 = 1.0;
        for (int j = 1; j <= (2 * i - 1); j++) pot_2 *= 2.0;

        // Calculamos x^(2n-1)
        double pot_x = 1.0;
        for (int j = 1; j <= (2 * i - 1); j++) pot_x *= x;

        // Calculamos (2n)!
        double fact_2i = 1.0;
        for (int j = 1; j <= (2 * i); j++) fact_2i *= j;

        suma += (2.0 * (pot_2 - 1.0) * B_2i * pot_x) / fact_2i;
    }
    return suma;
}

double serie_24_arcsin(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double num = 1.0, den = 1.0;
        // Fuerza bruta: (2i)! / (4^i * (i!)^2 * (2i+1))
        for (int j = 1; j <= (2*i); j++)
            num *= j;
        for (int j = 1; j <= (2*i+1); j++)
            num *= x;
        for (int j = 1; j <= i; j++) {
            den *= 4.0; den *= (j * j);
        }
        den *= (2 * i + 1);
        suma += (num / den);
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de arccos(x)
 * @details Resuelve la sumatoria expandida explicitamente mediante fuerza bruta,
 * calculando factoriales y potencias desde cero en cada iteracion.
 */
double serie_25_arccos(double x, int n) {
    double pi_medios = 1.57079632679489661923;
    double suma_interna = 0.0;

    for (int i = 0; i < n; i++) {
        double num = 1.0, den = 1.0;

        // Calculamos el numerador: (2i)! * x^(2i+1)
        for (int j = 1; j <= (2 * i); j++)
            num *= j;
        for (int j = 1; j <= (2 * i + 1); j++)
            num *= x;

        // Calculamos el denominador: 4^i * (i!)^2 * (2i+1)
        for (int j = 1; j <= i; j++) {
            den *= 4.0;
            den *= (j * j);
        }
        den *= (2 * i + 1);

        // Acumulamos el termino de la sumatoria
        suma_interna += (num / den);
    }

    // Aplicamos la formula exacta del documento: PI/2 - (sumatoria)
    return pi_medios - suma_interna;
}

double serie_26_arctan(double x, int n) {
    double suma = 0.0;
    double pi_medios = 1.57079632679489661923;

    // CASO 1: |x| < 1
    if (x > -1.0 && x < 1.0) {
        for (int i = 0; i < n; i++) {
            double num = 1.0;
            for (int j = 1; j <= (2 * i + 1); j++) num *= x;
            double signo = (i % 2 == 0) ? 1.0 : -1.0;
            suma += (signo * num / (2 * i + 1));
        }
        return suma;
    }

    // CASOS 2 y 3: x >= 1 o x <= -1
    for (int i = 0; i < n; i++) {
        double den_x = 1.0;
        for (int j = 1; j <= (2 * i + 1); j++) den_x *= x; // x^(2i+1)
        double signo = (i % 2 == 0) ? 1.0 : -1.0;

        // Sumamos: (-1)^i / ((2i+1) * x^(2i+1))
        suma += (signo / ((2 * i + 1) * den_x));
    }

    // Retornamos dependiendo del signo de x
    if (x >= 1.0) {
        return pi_medios - suma;
    } else {
        return -pi_medios - suma;
    }
}

double serie_27_senh(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double num = 1.0, den = 1.0;
        for (int j = 1; j <= (2 * i + 1); j++) { num *= x; den *= j; }
        suma += (num / den);
    }
    return suma;
}

double serie_28_cosh(double x, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        double num = 1.0, den = 1.0;
        for (int j = 1; j <= (2 * i); j++) { num *= x; den *= j; }
        suma += (num / den);
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de tanh(x)
 * @details Utiliza la funcion recursiva de Bernoulli (Complejidad masiva).
 */
double serie_29_tanh(double x, int n) {
    double suma = 0.0;

    // La formula (29) arranca su sumatoria en n=1
    for (int i = 1; i <= n; i++) {
        // Obtenemos B_{2n}
        double B_2i = serie_16_bernoulli(2 * i);

        // Calculamos 4^n
        double pot_4 = 1.0;
        for (int j = 1; j <= i; j++) pot_4 *= 4.0;

        // Calculamos x^(2n-1)
        double pot_x = 1.0;
        for (int j = 1; j <= (2 * i - 1); j++) pot_x *= x;

        // Calculamos (2n)!
        double fact_2i = 1.0;
        for (int j = 1; j <= (2 * i); j++) fact_2i *= j;

        // Ensamblamos la bestia: [ B_{2n} * 4^n * (4^n - 1) * x^(2n-1) ] / (2n)!
        suma += (B_2i * pot_4 * (pot_4 - 1.0) * pot_x) / fact_2i;
    }

    return suma;
}

/**
 * @brief Implementacion Nivel 1 de arcsenh(x)
 * @details El denominador requiere la construccion de 4^i * (i!)^2 * (2i+1).
 */
double serie_30_csenh(double x, int n) {
    double suma = 0.0;

    for (int i = 0; i < n; i++) {
        double num = 1.0, den = 1.0;

        // Numerador: (2i)! * x^(2i+1)
        for (int j = 1; j <= (2 * i); j++)
            num *= j;
        for (int j = 1; j <= (2 * i + 1); j++)
            num *= x;

        // Denominador estricto: 4^i * (i!)^2 * (2i+1)
        for (int j = 1; j <= i; j++) {
            den *= 4.0;
            den *= (j * j); // Acumulamos (i!)^2 en cada iteracion
        }
        den *= (2 * i + 1);

        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += (signo * num / den);
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de arctanh(x)
 */
double serie_31_arctanh(double x, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double num = 1.0;
        for (int j = 1; j <= (2 * i + 1); j++) num *= x;
        suma += (num / (2 * i + 1));
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de ln(1+x)/(1+x)
 * @details Utiliza el calculo iterativo de Numeros Armonicos.
 */
double serie_32_serie_combinada(double x, int n) {
    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double h = 0.0;
        for (int j = 1; j <= i; j++)
            h += 1.0 / j;

        double pot = 1.0;
        for (int j = 1; j <= i; j++)
            pot *= x;

        double signo = (i % 2 != 0) ? 1.0 : -1.0;
        suma += (signo * h * pot);
    }
    return suma;
}

/**
 * @brief Implementacion Nivel 1 de e^sen(x)
 * @details Composicion polinomial estatica por falta de termino general.
 */
double serie_33_exp_seno(double x, int n) {
    if (n <= 0)
        return 0.0;

    double suma = 1.0; // Termino 1
    if (n > 1)
        suma += x; // Termino 2
    if (n > 2)
        suma += (x * x) / 2.0; // Termino 3
    // Termino 4 seria x^3, pero su coeficiente es 0
    if (n > 4)
        suma -= (x * x * x * x) / 8.0; // Termino 5
    if (n > 5)
        suma -= (x * x * x * x * x) / 15.0; // Termino 6

    return suma;
}