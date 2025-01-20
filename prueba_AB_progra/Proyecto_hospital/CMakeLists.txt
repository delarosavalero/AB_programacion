# CMakeList.txt: proyecto de CMake para AB_programacion, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

# Habilite Recarga activa para los compiladores de MSVC si se admiten.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("prueba_AB_progra")

include_directories(${CMAKE_SOURCE_DIR} ../AB_programacion/include)

# Agregue un origen al ejecutable de este proyecto.
#add_executable (AB_programacion "main.cpp" "AB_programacion.h")
add_executable(prueba_AB_progra
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/Paciente.cpp"
    "${CMAKE_SOURCE_DIR}/src/Medico.cpp"
    "${CMAKE_SOURCE_DIR}/src/CitaMedica.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET prueba_AB_progra PROPERTY CXX_STANDARD 20)
endif()
