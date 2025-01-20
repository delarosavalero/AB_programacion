#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Medico {
private:
    int ID;
    string nombre;
    string especialidad;
    static int identificacion;
    bool vacante;

public:
    Medico() : ID(0), nombre(""), especialidad(""), vacante(false) {}
    
    Medico(const string& nombre, const string& especialidad, const string& bool vacante);

    void mostrarMedico() const;

    int getID() const { return ID; }
    string getNombre() const { return nombre; }
    string getEspecialidad() const { return especialidad; }
    bool getVacante() const { return vacante; };

    bool validarNombre(const string& nombre);
    bool validarVacante(const string& vacante);

    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setEspecialidad(const string& nuevaEspecialidad) { especialidad = nuevaEspecialidad; }
    void setVacante(const bool nuevaVacante) { vacante = nuevaVacante; }

    static int generarIdentificacion();

    static void guardarMedico(const Medico& medico);
};

#endif 
