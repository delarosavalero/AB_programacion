#include "CitaMedica.hpp"
#include <iostream>

CitaMedica::CitaMedica(const string& fecha, Paciente* pac, Medico* med, int prioridad)
    : fecha(fecha), paciente(paciente), medico(medico), prioridad(prioridad) {}

Paciente* CitaMedica::getPaciente() const {
    return paciente;
}

Medico* CitaMedica::getMedico() const {
    return medico;
}

void CitaMedica::mostrarDetalles() const {
    cout << "Fecha: " << fecha << ", Prioridad: " << prioridad << endl;
    paciente->mostrarInformacion();
    medico->mostrarInformacion();
}

void CitaMedica::cancelarCita() {
    cout << "Cita cancelada." << endl;
}

void CitaMedica::modificarCita(const string& nuevaFecha, int nuevaPrioridad) {
    this->fecha = nuevaFecha;
    this->prioridad = nuevaPrioridad;
}

void CitaMedica::guardarDatos(ofstream& outFile) const {
    outFile << fecha << "," << prioridad << endl;
}

CitaMedica CitaMedica::recuperarDatos(ifstream& inFile, vector<Paciente>& pacientes, vector<Medico>& medicos) {
    string fecha;
    int prioridad;
    getline(inFile, fecha, ',');
    inFile >> prioridad;
    inFile.ignore(); 

    CitaMedica cita("2024-01-01", paciente, medico, 1);
    cita.modificarCita("2024-01-01", 2);

    Paciente* paciente = nullptr; 
    Medico* medico = nullptr;

    if (!pacientes.empty()) {
        paciente = &pacientes[0];
    }
    else {
        cerr << "Error: No hay pacientes cargados." << endl;
    }

    if (!medicos.empty()) {
        medico = &medicos[0];
    }
    else {
        cerr << "Error: No hay medicos cargados." << endl;
    }

    return CitaMedica(fecha, paciente, medico, prioridad);
}
