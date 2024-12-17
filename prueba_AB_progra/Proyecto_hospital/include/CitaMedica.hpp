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

    void mostrarDetalles() const;
    void cancelarCita();
    void modificarCita(string nuevaFecha, int nuevaPrioridad);

    void guardarDatos(ofstream& outFile) const;
    static CitaMedica recuperarDatos(ifstream& inFile, vector<Paciente>& pacientes, vector<Medico>& medicos);
};

#endif 
