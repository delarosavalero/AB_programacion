#include "Medico.hpp"

Medico::Medico(string nom, string esp, string id)
    : nombre(nom), especialidad(esp), identificacion(id), disponibilidad(true) {}

void Medico::asignarDisponibilidad(bool estado) {
    disponibilidad = estado;
}


