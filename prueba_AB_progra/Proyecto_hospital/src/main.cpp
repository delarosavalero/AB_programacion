#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "main.hpp"
#include "Medico.hpp"
#include "Paciente.hpp"
#include "CitaMedica.hpp"

void cargarPacientes(std::vector<Paciente>& pacientes) {
    std::ifstream archivo("pacientes.txt");
    std::string linea;

    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre, fechaIngreso;

        getline(ss, nombre, ';');
        getline(ss, fechaIngreso, ';');

        Paciente paciente(nombre, fechaIngreso);
        pacientes.push_back(paciente);
    }
    archivo.close();
}

void cargarMedicos(std::vector<Medico>& medicos) {
    std::ifstream archivo("medicos.txt");
    std::string linea;

    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre, especialidad, vacante;

        getline(ss, nombre, ';');
        getline(ss, especialidad, ';');
        getline(ss, vacante, ';');

        bool estaVacante = (vacante == "Si");
        Medico medico(nombre, especialidad, estaVacante);
        medicos.push_back(medico);
    }
    archivo.close();
}

void cargarCitas(std::vector<CitaMedica>& citas) {
    std::ifstream archivo("citas.txt");
    std::string linea;

    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string IDPacienteStr, IDMedicoStr, fechaCita, nivelStr;

        getline(ss, IDPacienteStr, ';');
        getline(ss, IDMedicoStr, ';');
        getline(ss, fechaCita, ';');
        getline(ss, nivelStr, ';');

        int IDPaciente = std::stoi(IDPacienteStr);
        int IDMedico = std::stoi(IDMedicoStr);
        int nivel = std::stoi(nivelStr);

        CitaMedica cita(IDPaciente, IDMedico, fechaCita, nivel);
        citas.push_back(cita);
    }
    archivo.close();
}

void mostrarMenu() {
    std::cout << "\n--- Menu ---\n";
    std::cout << "1. Pacientes\n";
    std::cout << "2. Medicos\n";
    std::cout << "3. Citas\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<CitaMedica> citas;

    // Cargar los datos desde los archivos
    cargarPacientes(pacientes);
    cargarMedicos(medicos);
    cargarCitas(citas);

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::cout << "\n--- Pacientes ---\n";
            for (const auto& paciente : pacientes) {
                paciente.mostrarPaciente();
            }
            break;
        }
        case 2: {
            std::cout << "\n--- Medicos ---\n";
            for (const auto& medico : medicos) {
                medico.mostrarMedico();
            }
            break;
        }
        case 3: {
            std::cout << "\n--- Citas ---\n";
            for (const auto& cita : citas) {
                cita.mostrarCita();
            }
            break;
        }
        case 0:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion no valida. Intente nuevamente.\n";
            break;
        }
    } while (opcion != 0);

    // Guardar los datos en los archivos
    std::ofstream archivoPacientes("pacientes.txt");
    for (const auto& paciente : pacientes) {
        Paciente::guardarPaciente(paciente);
    }

    std::ofstream archivoMedicos("medicos.txt");
    for (const auto& medico : medicos) {
        Medico::guardarMedico(medico);
    }

    std::ofstream archivoCitas("citas.txt");
    for (const auto& cita : citas) {
        CitaMedica::guardarCita(cita);
    }

    return 0;
}
