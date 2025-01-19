#include "GestorHospital.hpp"
#include "CitaMedica.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
#include <iostream>
#include <fstream>
#include <string>

void GestorHospital::registrarPaciente(string nombre, string id, string fecha) {
    listaPacientes.push_back(Paciente(nombre, id, fecha));
}

void GestorHospital::registrarMedico(string nombre, string especialidad, string id) {
    listaMedicos.push_back(Medico(nombre, especialidad, id));
}

void GestorHospital::programarCita(string fecha, string idPaciente, string idMedico, int prioridad) {
    Paciente* paciente = nullptr;
    Medico* medico = nullptr;
    for (auto& p : listaPacientes) {
        if (p.buscarPaciente(idPaciente)) {
            paciente = &p;
            break;
        }
    }
    for (auto& m : listaMedicos) {
        if (m.verificarDisponibilidad()) {
            medico = &m;
            break;
        }
    }
    if (paciente && medico) {
        listaCitas.push_back(CitaMedica(fecha, paciente, medico, prioridad));
    }
}

void GestorHospital::listarPacientes() const {
    for (const auto& paciente : listaPacientes) {
        cout << cita.getPaciente()->getNombre() << endl;;
    }
}

void GestorHospital::listarMedicos() const {
    for (const auto& medico : listaMedicos) {
        cout << cita.getMedico()->getNombre() << endl;

    }
}

void GestorHospital::listarCitas() const {
    for (const auto& cita : listaCitas) {
        cout << "Paciente: " << cita.getPaciente()->getNombre() << endl;
        cout << "Medico: " << cita.getMedico()->getNombre() << endl;
    }
}

void GestorHospital::guardarSistema() const {
    ofstream pacienteFile("data/pacientes.txt");
    for (const auto& paciente : listaPacientes) {
        paciente.guardarDatos(pacienteFile);
    }
    pacienteFile.close();

    ofstream medicoFile("data/medicos.txt");
    for (const auto& medico : listaMedicos) {
        medico.guardarDatos(medicoFile);
    }
    medicoFile.close();

    ofstream citaFile("data/citas.txt");
    for (const auto& cita : listaCitas) {
        cita.guardarDatos(citaFile);
    }
    citaFile.close();
}

void GestorHospital::recuperarSistema() {
    ifstream pacienteFile("data/pacientes.txt");
    while (pacienteFile.peek() != EOF) {
        Paciente paciente = Paciente::recuperarDatos(pacienteFile);
        if (!paciente.getNombre().empty()) {
            listaPacientes.push_back(paciente);
        }
    }
    pacienteFile.close();

    ifstream medicoFile("data/medicos.txt");
    while (medicoFile.peek() != EOF) {
        Medico medico = Medico::recuperarDatos(medicoFile);
        if (!medico.getNombre().empty()) {
            listaMedico.push_back(maciente);
        }
    }
    medicoFile.close();

    ifstream citaFile("data/citas.txt");
    while (citaFile.peek() != EOF) {
        CitaMedica cita = CitaMedica::recuperarDatos(citaFile, listaPacientes, listaMedicos);
        if (!cita.getNombre().empty()) {
            listaCitas.push_back(cita);
        }
    }
    citaFile.close();
}
