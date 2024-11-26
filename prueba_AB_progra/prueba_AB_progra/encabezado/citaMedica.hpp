#ifndef CITAMEDICA_HPP
#define CITAMEDICA_HPP

#include <string>
#include "Paciente.hpp"
#include "Medico.hpp"

using namespace std;

class CitaMedica {
private:
    string fecha;
    Paciente* paciente;
    Medico* medico;
    int prioridad;

public:
    CitaMedica(string fecha, Paciente* pac, Medico* med, int prio);
}

#endif // CITAMEDICA_HPP
