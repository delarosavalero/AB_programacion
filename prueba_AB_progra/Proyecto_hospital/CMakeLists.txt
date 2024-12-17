# CMake mínimo requerido
cmake_minimum_required(VERSION 3.10)

# Nombre de tu proyecto
project(Proyecto_hospital)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añadir la carpeta 'src' y 'include' como directorios de búsqueda
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# Añadir los archivos fuente
set(SOURCE_FILES
    src/main.cpp
    src/Paciente.cpp
    src/Medico.cpp
    src/CitaMedica.cpp
    src/GestorHospital.cpp
)

# Crear el ejecutable final
add_executable(Proyecto_hospital ${SOURCE_FILES})