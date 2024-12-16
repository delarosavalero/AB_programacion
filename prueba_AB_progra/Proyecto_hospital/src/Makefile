CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = src/main.cpp src/Paciente.cpp src/Medico.cpp src/CitaMedica.cpp src/GestorHospital.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = proyectoHospital.out

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
