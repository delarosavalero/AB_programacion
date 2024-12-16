#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Paciente {
private:
    string nombre;
    string identificacion;
    string fechaIngreso;
    vector<string> historialClinico;

public:
    Paciente(string nom, string id, string fecha);

    void registrarHistorial(string evento);
    void mostrarInformacion() const;
    bool buscarPaciente(const string& criterio) const;

    void guardarDatos(ofstream& outFile) const;
    static Paciente recuperarDatos(ifstream& inFile);
};

#endif 
