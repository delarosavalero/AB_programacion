#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Medico {
private:
    string nombre;
    string especialidad;
    string identificacion;
    bool disponibilidad;

public:
    Medico(string& nombre, string& especialidad, string& id);

    string getNombre() const;

    void modificarDatos(const string& nuevaEspecialidad);
    void asignarDisponibilidad(bool estado);
    void mostrarInformacion() const;
    bool verificarDisponibilidad() const;

    void guardarDatos(ofstream& outFile) const;
    static Medico recuperarDatos(ifstream& inFile);
};

#endif 
