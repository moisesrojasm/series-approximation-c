# Estructura del Proyecto: Cálculo de Series en C

Implementación y análisis numérico de series matemáticas en C usando estructuras de control (for, while, do-while). Incluye estudio de convergencia, métricas de error de aproximación y comparación de rendimiento entre estrategias iterativas.

```plaintext
series-approximation-c/
│
├── .gitignore
├── README.md 
│
├── docs/                    # RECURSOS Y ENTREGABLES NO RELACIONADOS CON CÓDIGO.
|   ├── Reporte_Final.pdf    # Reporte con tablas, discusión de convergencia y capturas.
|   ├── diagramas/           # Diagramas de flujo manuales o exportados de Doxygen.
|   └── doxygen_output/      # Documentación HTML/LaTeX generada automáticamente por Doxygen.
│
├── Nivel1_Inicial/          # NIVEL 1: SOLUCIÓN DIRECTA (FUERZA BRUTA).
|   └── main_nivel1.c        # Un solo archivo con las 33 series implementadas de forma simple, O(n²).
|                            # Se recalcula potencia y factorial en cada iteración.
│
├── Nivel2_Intermedio/       # NIVEL 2: ESTABILIZACIÓN Y VALIDACIÓN.
│   ├── include/             # Archivos de cabecera (.h).
│   │   └── series_v2.h      # Declaración de las 33 series y macros de validación.
|    ├── src/                 # Implementación modular de las 33 series (.c).
|    │   ├── trigonometricas.c # Series 19-26 (sen, cos, tan, etc.).
|    │   ├── exponenciales.c   # Series 7-13 (e^x, ln, etc.).
|    │   └── constantes_pi.c   # Series 1-6 y 27-33 (Series de Pi, hiperbólicas y fracciones).
|    └── main_nivel2.c        # Menú interactivo, validación de dominio (error si x está fuera de rango).
|                             # Genera tablas con n={2,4,8,16,32,64,128,256}.
│
└── Nivel3_Avanzado/         # NIVEL 3: OPTIMIZACIÓN Y DOCUMENTACIÓN (PRODUCCIÓN).
    ├── Doxyfile             # Archivo de configuración para Doxygen (HAVE_DOT=YES).
    ├── include/             # Headers documentados con estándares Doxygen (/** @brief ... */).
    │   └── series_v3.h      # Prototipos optimizados.
    ├── src/                 # Implementación con RECURRENCIA (O(n)).
    │   ├── trig_exp_opt.c   # Se aprovecha el término anterior para calcular el siguiente.
    │   └── especial_opt.c   # Optimización de Bernoulli y Euler.
    └── main_nivel3.c        # Cálculo de métricas: Delta_n (diferencia) y Error de Aproximación.
                             # Comparación de eficiencia entre ciclos for, while y do-while.
```

---

## Catálogo Detallado de las 33 Funciones

A continuación se listan las series matemáticas que componen este proyecto, las cuales serán implementadas y analizadas en tres niveles de optimización algorítmica:

* **Nivel 1**: Solución directa $O(n^2)$
* **Nivel 2**: Estabilización y validación
* **Nivel 3**: Optimización por recurrencia $O(n)$

1.  **Logaritmo natural de 2**: $\ln(2) = 1 - \frac{1}{2} + \frac{1}{3} - \frac{1}{4} + \dots$
2.  **Pi cuartos**: $\frac{\pi}{4} = 1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \dots$
3.  **Pi cuadrado sobre 6**: $\frac{\pi^2}{6} = 1 + \frac{1}{2^2} + \frac{1}{3^2} + \dots$ (Problema de Basilea)
4.  **Pi cuadrado sobre 8**: $\frac{\pi^2}{8} = 1 + \frac{1}{3^2} + \frac{1}{5^2} + \dots$
5.  **Serie para 1/2**: $\sum_{n=0}^{\infty} \frac{1}{(2n+1)(2n+3)}$
6.  **Serie para 3/4**: $\sum_{n=1}^{\infty} \frac{1}{n(n+2)}$
7.  **Función exponencial**: $e^x = \sum_{n=0}^{\infty} \frac{x^n}{n!}$
8.  **Serie para $xe^x$**: $\sum_{n=0}^{\infty} \frac{(n+1)x^{n+1}}{n!}$
9.  **Serie para $(x+x^2)e^x$**: $\sum_{n=0}^{\infty} \frac{(n+1)^2x^{n+1}}{n!}$
10. **Logaritmo natural de $1+x$**: $\ln(1+x) = \sum_{n=1}^{\infty} \frac{(-1)^{n+1}x^n}{n}$
11. **Arctanh(x) (Variante)**: $x + \frac{x^3}{3} + \frac{x^5}{5} + \dots$
12. **Logaritmo natural de $x$**: $2 \sum_{n=0}^{\infty} \frac{1}{2n+1} \left(\frac{x-1}{x+1}\right)^{2n+1}$
13. **Función potencia $a^x$**: $a^x = \sum_{n=0}^{\infty} \frac{(x \ln a)^n}{n!}$
14. **Números de Bernoulli ($B_k$)**
15. **Números de Euler ($E_k$)**
16. **Euler $E_{2k}$ (Primera forma)**
17. **Euler $E_{2k}$ (Segunda forma)**
18. **Identidad de Euler**: $e^{i\pi} + 1 = 0$
19. **Seno**: $\sin x = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{(2n+1)!}$
20. **Coseno**: $\cos x = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n}}{(2n)!}$
21. **Tangente**: $\tan x$ (usando números de Bernoulli)
22. **Secante**: $\sec x$ (usando números de Euler)
23. **Cosecante**: $\csc x$
24. **Arcoseno**: $\arcsin x$
25. **Arcocoseno**: $\arccos x$
26. **Arcotangente**: $\arctan x = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{2n+1}$
27. **Seno hiperbólico**: $\sinh x = \sum_{n=0}^{\infty} \frac{x^{2n+1}}{(2n+1)!}$
28. **Coseno hiperbólico**: $\cosh x = \sum_{n=0}^{\infty} \frac{x^{2n}}{(2n)!}$
29. **Tangente hiperbólica**: $\tanh x$
30. **Cosecante hiperbólica**: $\text{csch } x$
31. **Arcotangente hiperbólica**: $\text{arctanh } x = \sum_{n=0}^{\infty} \frac{x^{2n+1}}{2n+1}$
32. **Serie combinada**: $\frac{\ln(1+x)}{1+x}$
33. **Exponencial del seno**: $e^{\sin x}$

---