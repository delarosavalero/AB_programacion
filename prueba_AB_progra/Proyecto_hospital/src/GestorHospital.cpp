#include "GestorHospital.hpp"

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
        paciente.mostrarInformacion();
    }
}

void GestorHospital::listarMedicos() const {
    for (const auto& medico : listaMedicos) {
        medico.mostrarInformacion();
    }
}

void GestorHospital::listarCitas() const {
    for (const auto& cita : listaCitas) {
        cita.mostrarDetalles();
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
    while (!pacienteFile.eof()) {
        listaPacientes.push_back(Paciente::recuperarDatos(pacienteFile));
    }
    pacienteFile.close();

    ifstream medicoFile("data/medicos.txt");
    while (!medicoFile.eof()) {
        listaMedicos.push_back(Medico::recuperarDatos(medicoFile));
    }
    medicoFile.close();

    ifstream citaFile("data/citas.txt");
    while (!citaFile.eof()) {
        listaCitas.push_back(CitaMedica::recuperarDatos(citaFile, listaPacientes, listaMedicos));
    }
    citaFile.close();
}
