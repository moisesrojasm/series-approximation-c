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

## Catálogo de las 33 Funciones

A continuación se listan las series matemáticas que componen este proyecto, las cuales serán implementadas y analizadas en tres niveles de optimización algorítmica:

* **Nivel 1**: Solución directa $O(n^2)$
* **Nivel 2**: Estabilización y validación
* **Nivel 3**: Optimización por recurrencia $O(n)$

Las funciones a implementar son:

1.  **Logaritmo natural de 2**: $\ln(2) = 1 - \frac{1}{2} + \frac{1}{3} - \frac{1}{4} + \dots$
2.  **Pi cuartos**: $\frac{\pi}{4} = 1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \dots$
3.  **Pi cuadrado sobre 6**: $\frac{\pi^{2}}{6} = 1 + \frac{1}{2^{2}} + \frac{1}{3^{2}} + \dots$ 
4.  **Pi cuadrado sobre 8**: $\frac{\pi^{2}}{8} = 1 + \frac{1}{3^{2}} + \frac{1}{5^{2}} + \dots$ 
5.  **Serie para 1/2**: $\sum_{n=0}^{\infty} \frac{1}{(2n+1)(2n+3)}$ 
6.  **Serie para 3/4**: $\sum_{n=1}^{\infty} \frac{1}{n(n+2)}$ 
7.  **Función exponencial**: $e^{x} = 1 + x + \frac{x^{2}}{2!} + \frac{x^{3}}{3!} + \dots$ 
8.  **Serie para $xe^{x}$**: $x + \frac{2x^{2}}{2!} + \frac{3x^{3}}{3!} + \dots$ 
9.  **Serie para $(x+x^{2})e^{x}$**: $x + \frac{4x^{2}}{2!} + \frac{9x^{3}}{3!} + \dots$ 
10. **Logaritmo natural de $1+x$**: $\ln(1+x) = x - \frac{x^{2}}{2} + \frac{x^{3}}{3} - \dots$ para $-1 < x \le 1$ 
11. **Variante Logarítmica**: $\frac{1}{2}\ln(\frac{1+x}{1-x}) = x + \frac{x^{3}}{3} + \frac{x^{5}}{5} + \dots$ para $-1 < x < 1$ 
12. **Logaritmo de $x$ (Forma 1)**: $2 \{ (\frac{x-1}{x+1}) + \frac{1}{3}(\frac{x-1}{x+1})^{3} + \dots \}$ para $x > 0$ 
13. **Logaritmo de $x$ (Forma 2)**: $(\frac{x-1}{x}) + \frac{1}{2}(\frac{x-1}{x})^{2} + \dots$ para $x \ge \frac{1}{2}$ 
14. **Teorema del Binomio**: $(1+x)^{\alpha} = \binom{\alpha}{0} + \binom{\alpha}{1}x + \binom{\alpha}{2}x^{2} + \dots$ para $|x| < 1$ 
15. **Función potencia $a^x$**: $a^{x} = 1 + x \ln a + \frac{(x \ln a)^{2}}{2!} + \dots$ para $a > 0$ 
16. **Números de Bernoulli ($B_k$)**: $B_{k} = -\sum_{i=0}^{k-1} \binom{k}{i} \frac{B_{i}}{k+1-i}$ 
17. **Números de Euler ($E_k$)**: $E_{k} = \frac{2^{2k+2}(2k)!}{\pi^{2k+1}} \{1 - \frac{1}{3^{2k+1}} + \frac{1}{5^{2k+1}} - \dots \}$ 
18. **Números de Euler ($E_{2k}$)**: $E_{2k} = i \sum_{m=1}^{2k+1} \sum_{j=0}^{m} \binom{m}{j} \frac{(-1)^{j}(m-2j)^{2k+1}}{2^{m}i^{m}m}$ 
19. **Seno**: $\sin x = x - \frac{x^{3}}{3!} + \frac{x^{5}}{5!} - \dots$ 
20. **Coseno**: $\cos x = 1 - \frac{x^{2}}{2!} + \frac{x^{4}}{4!} - \dots$ 
21. **Tangente**: $\tan x$ (con coeficientes $B_{2n}$) para $|x| < \frac{\pi}{2}$ 
22. **Secante**: $\sec x$ (con coeficientes $E_{2n}$) para $|x| < \frac{\pi}{2}$ 
23. **Cosecante**: $\csc x$ para $0 < |x| < \pi$ 
24. **Arcoseno**: $\arcsin x = x + \frac{1}{2}\frac{x^{3}}{3} + \frac{1}{2}\frac{3}{4}\frac{x^{5}}{5} + \dots$ para $|x| < 1$ 
25. **Arcocoseno**: $\arccos x = \frac{\pi}{2} - \arcsin x$ para $|x| < 1$
26. **Arcotangente**: $\arctan x$ (Series distintas para $|x| < 1$ y $|x| \ge 1$) 
27. **Seno hiperbólico**: $\sinh x = x + \frac{x^{3}}{3!} + \frac{x^{5}}{5!} + \dots$ 
28. **Coseno hiperbólico**: $\cosh x = 1 + \frac{x^{2}}{2!} + \frac{x^{4}}{4!} + \dots$ 
29. **Tangente hiperbólica**: $\tanh x$ para $|x| < \frac{\pi}{2}$ 
30. **Arcoseno hiperbólico**: $\text{arcsenh } x = x - \frac{1}{6}x^{3} + \frac{3}{40}x^{5} - \dots$ para $|x| < 1$
31. **Arcotangente hiperbólica**: $\text{arctanh } x = x + \frac{x^{3}}{3} + \frac{x^{5}}{5} + \dots$ para $|x| < 1$ 
32. **Serie combinada**: $\frac{\ln(1+x)}{1+x} = x - (1+\frac{1}{2})x^{2} + (1+\frac{1}{2}+\frac{1}{3})x^{3} - \dots$ 
33. **Exponencial del seno**: $e^{\sin x} = 1 + x + \frac{x^{2}}{2} - \frac{x^{4}}{8} - \dots$ 

---