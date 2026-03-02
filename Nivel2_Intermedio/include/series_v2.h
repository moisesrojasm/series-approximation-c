#ifndef SERIES_V2_H
#define SERIES_V2_H


// QUIM: Constantes, Fracciones y Exponenciales Iniciales (01 - 11)

double serie_01_ln2_v2(int n);
double serie_02_pi4_v2(int n);
double serie_03_pi2_6_v2(int n);
double serie_04_pi2_8_v2(int n);
double serie_05_un_medio_v2(int n);
double serie_06_tres_cuartos_v2(int n);

/**
 * @brief Funciones Exponenciales y Logaritmicas (Nivel 2: Validacion de Dominio)
 */
double serie_07_exp_v2(double x, int n);
double serie_08_x_exp_v2(double x, int n);
double serie_09_x_x2_exp_v2(double x, int n);
double serie_10_ln1plusx_v2(double x, int n);
double serie_11_variante_log_v2(double x, int n);


// JP: Logaritmos, Especiales y Trigonométricas Iniciales (12 - 22)

/**
 * @brief Variantes del Logaritmo (Nivel 2: Validacion x > 0 o x >= 1/2)
 */
double serie_12_ln_x_v1_v2(double x, int n);
double serie_13_ln_x_v2_v2(double x, int n);

/**
 * @brief Teoremas y Numeros Especiales (Requieren parametros extra o k)
 */
double serie_14_binomio_v2(double x, double alpha, int n);
double serie_15_a_potencia_x_v2(double a, double x, int n);
double serie_16_bernoulli_v2(int k);
double serie_17_euler_Ek_v2(int k);
double serie_18_euler_E2k_v2(int k);

/**
 * @brief Funciones Trigonometricas Base (Nivel 2: Reduccion de Argumento)
 */
double serie_19_seno_v2(double x, int n);
double serie_20_coseno_v2(double x, int n);
double serie_21_tangente_v2(double x, int n);
double serie_22_secante_v2(double x, int n);


// MOY: Trigonométricas Restantes, Hiperbólicas y Varias (23 - 33)

/**
 * @brief Funciones Inversas y Restantes (Nivel 2: Validacion de Dominio [-1, 1])
 */
double serie_23_cosecante_v2(double x, int n);
double serie_24_arcsin_v2(double x, int n);
double serie_25_arccos_v2(double x, int n);
double serie_26_arctan_v2(double x, int n);

/**
 * @brief Funciones Hiperbolicas y Combinadas (Nivel 2: Control de Crecimiento)
 */
double serie_27_senh_v2(double x, int n);
double serie_28_cosh_v2(double x, int n);
double serie_29_tanh_v2(double x, int n);
double serie_30_csenh_v2(double x, int n);
double serie_31_arctanh_v2(double x, int n);
double serie_32_serie_combinada_v2(double x, int n);
double serie_33_exp_seno_v2(double x, int n);

#endif 