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
    Paciente(const string& nombre, const string& id, const string& fecha);

    string getNombre() const;
    
    void modificarDatos(const string& nuevoNombre, const string& nuevaFecha);
    void registrarHistorial(const string& evento);
    
    void mostrarInformacion() const;
    bool buscarPaciente(const string& criterio) const;

    void guardarDatos(ofstream& outFile) const;
    static Paciente recuperarDatos(ifstream& inFile);
};

#endif 
