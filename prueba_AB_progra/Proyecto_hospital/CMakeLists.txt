# CMake mínimo requerido
cmake_minimum_required(VERSION 3.10)

# Nombre de tu proyecto
project(prueba_AB_progra)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)make

# Añadir la carpeta 'src' y 'include' como directorios de búsqueda
include_directories(include)

# Añadir los archivos fuente
set(SOURCE_FILES
    src/prueba_AB_progra.cpp
    src/Paciente.cpp
    src/Medico.cpp
    src/CitaMedica.cpp
    src/GestorHospital.cpp
)

# Crear el ejecutable final
add_executable(prueba_AB_progra ${SOURCE_FILES})



