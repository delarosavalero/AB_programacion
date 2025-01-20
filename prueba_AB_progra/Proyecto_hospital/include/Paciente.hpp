#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Paciente {
private:
    int ID;
    string nombre;
    string fechaIngreso;
    static int Identificacion;

public:
    Paciente() : ID(0), nombre(""), fechaIngreso("") {}

    Paciente(const string& nombre, const string& fechaIngreso);
    
    void mostrarPaciente() const;

    int getID() const { return ID; }
    bool validarFecha(const string& fecha);
    bool validarNombre(const string& nombre);

    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setFechaIngreso(const string& nuevaFecha) { fechaIngreso = nuevaFecha; }

    static int generarID();

    static void guardarPaciente(const Paciente& paciente);
};

#endif 
