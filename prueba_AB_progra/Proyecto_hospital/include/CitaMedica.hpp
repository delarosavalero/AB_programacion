#ifndef CITAMEDICA_HPP
#define CITAMEDICA_HPP

#include <string>
#include <fstream>
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
    CitaMedica(const string& fecha, Paciente* paciente, Medico* medico, int prioridad);

    Paciente* getPaciente() const;
    Medico* getMedico() const;

    void cancelarCita();
    void modificarCita(const string& nuevaFecha, int nuevaPrioridad);
    static bool compararPorFecha(const CitaMedica& a, const CitaMedica& b);

    void mostrarDetalles() const;
    void guardarDatos(ofstream& outFile) const;
    static CitaMedica recuperarDatos(ifstream& inFile, vector<Paciente>& pacientes, vector<Medico>& medicos);
};

#endif 
