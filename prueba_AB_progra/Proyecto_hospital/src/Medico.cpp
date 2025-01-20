#include "Medico.hpp"
#include <fstream>
#include <iostream>

int Medico::Identificacion = 1;

Medico::Medico(const string& nombre, const string& especialidad, bool vacante)
    : ID(generarID()), nombre(nombre), especialidad(especialidad), vacante(vacante) {}

void Medico::mostrarMedico() const {
    cout << "ID: " << ID
        << ", Nombre: " << nombre
        << ", Especialidad: " << especialidad
        << ", Vacante: " << (vacante ? "Si" : "No")
        << endl;
}

bool Medico::validarNombre(const string& nombre) {
    return !nombre.empty();
}

bool Medico::validarEspecialidad(const string& especialidad) {
    return !especialidad.empty();
}

int Medico::generarIdentificacion() {
    return Identificacion++;
}

void Medico::guardarMedico(const Medico& medico) {
    ofstream archivo("medicos.txt", ios::app);
    if (archivo) {
        archivo << medico.getID() << ";" << medico.getNombre() << ";" << medico.getEspecialidad() << ";" << (medico.getVacante() ? "Si" : "No") << "\n";
    }
}