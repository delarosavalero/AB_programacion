# Definir el compilador
CXX = g++
# Definir los flags del compilador
CXXFLAGS = -std=c++11 -Wall

# Definir los archivos fuente
SRC = src/prueba_AB_progra.cpp src/Paciente.cpp src/Medico.cpp src/CitaMedica.cpp src/GestorHospital.cpp
# Definir los archivos de objeto
OBJ = $(SRC:.cpp=.o)
# Definir el nombre del ejecutable
EXEC = bin/proyectoHospital.out

# Regla por defecto (compilar el proyecto)
all: $(EXEC)

# Compilar los archivos fuente a un archivo ejecutable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Compilar cada archivo fuente en un archivo objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar los archivos generados durante la compilación
clean:
	rm -f $(OBJ) $(EXEC)

# Regla para ejecutar el proyecto
run: $(EXEC)
	./$(EXEC)

