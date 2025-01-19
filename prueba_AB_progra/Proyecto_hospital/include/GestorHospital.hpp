#ifndef GESTORHOSPITAL_HPP
#define GESTORHOSPITAL_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"

using namespace std;

class GestorHospital {
private:
    vector<Paciente> listaPacientes;
    vector<Medico> listaMedicos;
    vector<CitaMedica> listaCitas;

public:
    void registrarPaciente(const string& nombre, const string& id, const string& fecha);
    void registrarMedico(const string& nombre, const string& especialidad, const string& id);
    void programarCita(const string& fecha, const string& idPaciente, const string& idMedico, int prioridad);
    
    void listarPacientes() const;
    void listarMedicos() const;
    void listarCitas() const;

    void guardarSistema() const;
    void recuperarSistema();
};

#endif 
