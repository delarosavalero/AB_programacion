#ifndef MAIN_HPP
#define MAIN_HPP

#include <vector>
#include <string>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"

void cargarPacientes(std::vector<Paciente>& pacientes);
void cargarMedicos(std::vector<Medico>& medicos);
void cargarCitas(std::vector<CitaMedica>& citas);

void mostrarMenu();

#endif