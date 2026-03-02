#ifndef SERIES_V3_H
#define SERIES_V3_H

// QUIM: Constantes, Fracciones y Exponenciales Iniciales (01 - 11)

/**
 * @brief [O(n)] Aproximacion de la constante ln(2).
 * @details Evita recalcular denominadores desde cero usando el termino anterior.
 * @param n Numero de terminos maximos.
 * @return Aproximacion optimizada de ln(2).
 */
double serie_01_ln2_v3(int n);

/**
 * @brief [O(n)] Aproximacion de pi/4.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_02_pi4_v3(int n);

/**
 * @brief [O(n)] Aproximacion de pi^2/6.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_03_pi2_6_v3(int n);

/**
 * @brief [O(n)] Aproximacion de pi^2/8.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_04_pi2_8_v3(int n);

/**
 * @brief [O(n)] Aproximacion de la fraccion 1/2.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_05_un_medio_v3(int n);

/**
 * @brief [O(n)] Aproximacion de la fraccion 3/4.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_06_tres_cuartos_v3(int n);

/**
 * @brief [O(n)] Serie de Taylor para e^x.
 * @details t_n = t_{n-1} * (x / n). Elimina la necesidad de la funcion pow() y factoriales.
 * @param x Exponente real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada de e^x.
 */
double serie_07_exp_v3(double x, int n);

/**
 * @brief [O(n)] Serie para x * e^x.
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_08_x_exp_v3(double x, int n);

/**
 * @brief [O(n)] Serie para (x^2 + x) * e^x.
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_09_x_x2_exp_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Mercator para ln(1+x).
 * @param x Valor real (-1 < x <= 1).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_10_ln1plusx_v3(double x, int n);

/**
 * @brief [O(n)] Serie variante de logaritmo.
 * @param x Valor real (-1 < x < 1).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_11_variante_log_v3(double x, int n);


// JP: Logaritmos, Especiales y Trigonométricas Iniciales (12 - 22)

/**
 * @brief [O(n)] Variante 1 para ln(x).
 * @param x Valor real (x > 0).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_12_ln_x_v1_v3(double x, int n);

/**
 * @brief [O(n)] Variante 2 para ln(x).
 * @param x Valor real (x >= 1/2).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_13_ln_x_v2_v3(double x, int n);

/**
 * @brief [O(n)] Serie del Binomio de Newton (1+x)^alpha.
 * @param x Valor base (|x| < 1).
 * @param alpha Exponente fraccionario o negativo.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_14_binomio_v3(double x, double alpha, int n);

/**
 * @brief [O(n)] Serie para la potencia a^x.
 * @param a Base real positiva (a > 0).
 * @param x Exponente real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_15_a_potencia_x_v3(double a, double x, int n);

/**
 * @brief [O(n)] Generador de Numeros de Bernoulli (Optimizacion de Memoria).
 * @param k Limite de la iteracion.
 * @return Numero de Bernoulli B_k.
 */
double serie_16_bernoulli_v3(int k);

/**
 * @brief [O(n)] Generador de Numeros de Euler E_k.
 * @param k Limite de la iteracion.
 * @return Numero de Euler E_k.
 */
double serie_17_euler_Ek_v3(int k);

/**
 * @brief [O(n)] Generador de Numeros de Euler E_{2k}.
 * @param k Limite de la iteracion.
 * @return Numero de Euler alternante.
 */
double serie_18_euler_E2k_v3(int k);

/**
 * @brief [O(n)] Serie de Maclaurin para sen(x).
 * @details t_n = -t_{n-1} * (x^2) / ((2n)(2n+1)). Recurrencia de salto doble.
 * @param x Valor en radianes (rango reducido).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada del seno.
 */
double serie_19_seno_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Maclaurin para cos(x).
 * @param x Valor en radianes (rango reducido).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada del coseno.
 */
double serie_20_coseno_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Maclaurin para tan(x).
 * @param x Valor en radianes.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada de la tangente.
 */
double serie_21_tangente_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Maclaurin para sec(x).
 * @param x Valor en radianes.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada de la secante.
 */
double serie_22_secante_v3(double x, int n);


// MOY: Trigonométricas Restantes, Hiperbólicas y Varias (23 - 33)

/**
 * @brief [O(n)] Serie de Maclaurin para csc(x).
 * @param x Valor en radianes.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada de la cosecante.
 */
double serie_23_cosecante_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Taylor para arcsin(x).
 * @param x Valor real (-1 <= x <= 1).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_24_arcsin_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Taylor para arccos(x).
 * @param x Valor real (-1 <= x <= 1).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_25_arccos_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Taylor para arctan(x).
 * @param x Valor real (-1 <= x <= 1).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_26_arctan_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Maclaurin para senh(x).
 * @details Utiliza recurrencia estricta sin alternancia de signos.
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada del seno hiperbolico.
 */
double serie_27_senh_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Maclaurin para cosh(x).
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_28_cosh_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Maclaurin para tanh(x).
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_29_tanh_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Maclaurin para csenh(x).
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_30_csenh_v3(double x, int n);

/**
 * @brief [O(n)] Serie de Maclaurin para arctanh(x).
 * @param x Valor real (-1 < x < 1).
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_31_arctanh_v3(double x, int n);

/**
 * @brief [O(n)] Resolucion de Serie Combinada.
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_32_serie_combinada_v3(double x, int n);

/**
 * @brief [O(n)] Resolucion de Serie exp_seno(x).
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion optimizada.
 */
double serie_33_exp_seno_v3(double x, int n);

#endif