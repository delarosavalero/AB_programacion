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


