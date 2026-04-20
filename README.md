# Estructura del Proyecto: Cálculo de Series en C

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![Doxygen](https://img.shields.io/badge/Doxygen-%234A2E8B.svg?style=for-the-badge&logo=doxygen&logoColor=white)

Implementación y análisis numérico de series matemáticas en C usando estructuras de control (for, while, do-while). Incluye estudio de convergencia, métricas de error de aproximación y comparación de rendimiento entre estrategias iterativas.

```plaintext
series-approximation-c/
│
├── .gitignore               
├── CMakeLists.txt           # Configuración principal de compilación para el proyecto.
├── LICENSE                  
├── README.md       
├── Reporte_Practica_1.pdf             
│
├── Nivel1_Inicial/          # NIVEL 1: SOLUCIÓN DIRECTA.            
│   └── main_nivel1.c        # Un solo archivo con las 33 series implementadas de forma simple, O(n²).
│                            
├── Nivel2_Intermedio/       # NIVEL 2: ESTABILIZACIÓN Y VALIDACIÓN.
│   ├── include/             
│   │   └── series_v2.h      # Declaración de las 33 series y macros de validación.
│   ├── src/                 
│   │   ├── constantes.c     # Series 1-6 y 27-33.
│   │   ├── exponenciales.c  # Series 7-13.
│   │   └── trigonometricas.c # Series 19-26.            
│   └── main_nivel2.c        # Validación de dominio. Genera tablas con n={2,4,8,16,32,64,128,256}.
│
└── Nivel3_Avanzado/         # NIVEL 3: OPTIMIZACIÓN Y DOCUMENTACIÓN.
    ├── html/                # Documentación web interactiva generada automáticamente por Doxygen.
    ├── include/             
    │   └── series_v3.h      # Headers documentados con estándares Doxygen.
    ├── latex/               # Documentación en formato PDF/LaTeX generada por Doxygen.
    ├── src/                 
    │   ├── especial_opt.c   # Implementación optimizada de funciones especiales.
    │   └── trig_exp_opt.c   # Funciones trigonométricas y exponenciales por recurrencia O(n).            
    └── main_nivel3.c        # Cálculo de métricas: Delta_n (diferencia) y Error de Aproximación.
                             
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

## Instrucciones de Compilación y Ejecución

Este proyecto utiliza **CMake** como sistema de construcción para garantizar la portabilidad del código entre distintos sistemas operativos (Windows, macOS, Linux).

### Requisitos Previos
* Un compilador de C estándar (GCC, MinGW, Clang o MSVC).
* **CMake** (versión 3.10 o superior).

### Método 1: Compilación Automatizada (Recomendado)
Abre una terminal en la raíz del proyecto y ejecuta los siguientes comandos para compilar el Nivel 3:

```bash
# 1. Crear un directorio aislado para los binarios
mkdir build
cd build

# 2. Generar los archivos de configuración
cmake ..

# 3. Compilar el código fuente
cmake --build .

# 4. Ejecutar el programa principal
./Nivel3_Avanzado/main_nivel3    # En sistemas Unix/Mac
.\Nivel3_Avanzado\Debug\main_nivel3.exe  # En sistemas Windows
```


### Método 2: Compilación Manual
Si no se dispone de CMake, el proyecto puede compilarse de forma tradicional usando gcc.

Desde la raíz del repositorio, ejecuta:
```bash
# Compilar enlazando las librerías matemáticas (-lm)
gcc Nivel3_Avanzado/src/*.c Nivel3_Avanzado/main_nivel3.c -I Nivel3_Avanzado/include -o main_nivel3 -lm

# Ejecutar el binario
./main_nivel3
```