#ifndef GESTORHOSPITAL_HPP
#define GESTORHOSPITAL_HPP

#include <vector>
#include <fstream>
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
    void registrarPaciente(string nombre, string id, string fecha);
    void registrarMedico(string nombre, string especialidad, string id);
    void programarCita(string fecha, string idPaciente, string idMedico, int prioridad);
    void listarPacientes() const;
    void listarMedicos() const;
    void listarCitas() const;

    void guardarSistema() const;
    void recuperarSistema();
};

#endif 
