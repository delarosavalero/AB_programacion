#include "Medico.hpp"

Medico::Medico(string nom, string esp, string id)
    : nombre(nom), especialidad(esp), identificacion(id), disponibilidad(true) {}

void Medico::asignarDisponibilidad(bool estado) {
    disponibilidad = estado;
}

void Medico::mostrarInformacion() const {
    cout << "Nombre: " << nombre << ", Especialidad: " << especialidad << ", ID: " << identificacion << endl;
}

bool Medico::verificarDisponibilidad() const {
    return disponibilidad;
}




