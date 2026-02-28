cmake_minimum_required(VERSION 3.20)
project(Practica1_Series C)

set(CMAKE_C_STANDARD 11)

link_libraries(m)

# Se incluyen las carpetas de cabeceras para que el compilador encuentre los archivos .h
include_directories(Nivel2_Intermedio/include Nivel3_Avanzado/include)

# EJECUTABLE NIVEL 1
add_executable(Nivel1 Nivel1_Inicial/main_nivel1.c)


# EJECUTABLE NIVEL 2
# add_executable(Nivel2
#     Nivel2_Intermedio/main_nivel2.c
#     Nivel2_Intermedio/src/trigonometricas.c
#     Nivel2_Intermedio/src/exponenciales.c
# )

# EJECUTABLE NIVEL 3
# add_executable(Nivel3
#     Nivel3_Avanzado/main_nivel3.c
#     Nivel3_Avanzado/src/trig_exp_opt.c
# )
