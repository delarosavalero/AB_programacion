#include <iostream>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"
#include "GestorHospital.hpp"

int main() {
    GestorHospital gestor;

    gestor.recuperarSistema();

    
    gestor.registrarPaciente("Juan Perez", "12345", "2024-11-25");
    gestor.registrarMedico("Dr. Smith", "Cardiología", "67890");
    gestor.programarCita("2024-11-26 10:00", "12345", "67890", 1);

    
    gestor.listarPacientes();
    gestor.listarMedicos();
    gestor.listarCitas();

    
    gestor.guardarSistema();

    return 0;
}
