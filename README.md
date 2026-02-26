# Estructura del Proyecto: Práctica 1 - Cálculo de Series en C

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
