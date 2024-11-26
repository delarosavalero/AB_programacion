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

