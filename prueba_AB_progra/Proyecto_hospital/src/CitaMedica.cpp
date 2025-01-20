#include "CitaMedica.hpp"
#include <iostream>
#include <fstream>

int CitaMedica::Identificacion = 1;

CitaMedica::CitaMedica(int IDPaciente, int IDMedico, const string& fechaCita, int nivel)
    : ID(generarID()), IDPaciente(IDPaciente), IDMedico(IDMedico), fechaCita(fechaCita), nivel(nivel) {}

void CitaMedica::mostrarCita() const {
    cout << "ID: " << ID
        << ", Paciente ID: " << IDPaciente
        << ", Médico ID: " << IDMedico
        << ", Fecha: " << fechaCita
        << ", Nivel: " << nivel << endl;
}

bool CitaMedica::validarFecha(const string& fecha) {
    return fecha.size() == 10 && fecha[2] == '-' && fecha[5] == '-' &&
        all_of(fecha.begin(), fecha.end(), [](char c, int i = 0) {
        return (i == 2 || i == 5) ? c == '-' : isdigit(c);
            });
}

bool CitaMedica::validarNivel(int nivel) {
    return nivel >= 1 && nivel <= 10;
}

bool CitaMedica::validarID(int ID, const vector<int>& lista) {
    return find(lista.begin(), lista.end(), ID) != lista.end();
}

int CitaMedica::generarID() {
    return identificacion++;
}

void CitaMedica::guardarCita(const CitaMedica& cita) {
    ofstream archivo("citas.txt", ios::app);
    if (archivo) {
        archivo << cita.ID << ";" << cita.IDPaciente << ";" << cita.IDMedico << ";" << cita.fechaCita << ";" << cita.nivel << "\n";
    }
}
