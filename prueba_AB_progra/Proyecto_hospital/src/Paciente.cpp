#include "Paciente.hpp"

Paciente::Paciente(string nom, string id, string fecha)
    : nombre(nom), identificacion(id), fechaIngreso(fecha) {}

void Paciente::registrarHistorial(string evento) {
    historialClinico.push_back(evento);
}

void Paciente::mostrarInformacion() const {
    cout << "Nombre: " << nombre << endl;
    cout << "ID: " << identificacion << endl;
    cout << "Fecha de Ingreso: " << fechaIngreso << endl;
    cout << "Historial Clinico: " << endl;
    for (const auto& evento : historialClinico) {
        cout << "- " << evento << endl;
    }
}

bool Paciente::buscarPaciente(const string& criterio) const {
    return nombre == criterio || identificacion == criterio;
}

void Paciente::guardarDatos(ofstream& outFile) const {
    outFile << nombre << "," << identificacion << "," << fechaIngreso << endl;
    for (const auto& evento : historialClinico) {
        outFile << evento << endl;
    }
}

Paciente Paciente::recuperarDatos(ifstream& inFile) {
    string nombre, id, fecha;
    getline(inFile, nombre, ',');
    getline(inFile, id, ',');
    getline(inFile, fecha);
    Paciente paciente(nombre, id, fecha);
    string evento;
    while (getline(inFile, evento)) {
        if (!evento.empty()) {
            paciente.registrarHistorial(evento);
        }
    }
    return paciente;
}
