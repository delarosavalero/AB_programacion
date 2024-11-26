#include <iostream>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"
#include "GestorHospital.hpp"

int main() {
    GestorHospital gestor;

    // Cargar datos previamente guardados
    gestor.recuperarSistema();

    // Realizar operaciones en el sistema
    gestor.registrarPaciente("Juan Perez", "12345", "2024-11-25");
    gestor.registrarMedico("Dr. Smith", "Cardiolog�a", "67890");
    gestor.programarCita("2024-11-26 10:00", "12345", "67890", 1);

    // Listar pacientes, m�dicos y citas
    gestor.listarPacientes();
    gestor.listarMedicos();
    gestor.listarCitas();

    // Guardar los datos despu�s de modificar
    gestor.guardarSistema();

    return 0;
}
