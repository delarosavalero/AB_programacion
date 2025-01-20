#include "Paciente.hpp"
#include <iostream>
#include <fstream>

int Paciente::Identificacion = 1;

Paciente::Paciente(const string& nombre, const string& fechaIngreso)
    : ID(generarID()), nombre(nombre), fechaIngreso(fechaIngreso) {}


void Paciente::mostrarPaciente() const {
    cout << "ID: " << ID
        << ", Nombre: " << nombre
        << ", Fecha de Ingreso: " << fechaIngreso << endl;
}

bool Paciente::validarFecha(const string& fecha) {
    return fecha.size() == 10 && fecha[2] == '-' && fecha[5] == '-' &&
        all_of(fecha.begin(), fecha.end(), [](char c, int i = 0) {
        return (i == 2 || i == 5) ? c == '-' : isdigit(c);
            });
}

bool Paciente::validarNombre(const string& nombre) {
    return !nombre.empty();
}

int Paciente::generarID() {
    return Identificacion++;
}

void Paciente::guardarPaciente(const Paciente& paciente) {
    ofstream archivo("pacientes.txt", ios::app);
    if (archivo) {
        archivo << paciente.getID() << ";" << paciente.getNombre() << ";" << paciente.getFechaIngreso() << "\n";
    }
}
