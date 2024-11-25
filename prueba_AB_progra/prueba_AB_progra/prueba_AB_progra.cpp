﻿// prueba_AB_progra.cpp: define el punto de entrada de la aplicación.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paciente {
private:
	string nombre;
	string indentificacion;
	string fechaIngreso;
	vector<string> historialClinico;

public:
	Paciente(string nom, string id, string fecha) : nombre(nom), indentificacion(id), fechaIngreso(fecha) {}


	void registrarHistorial(string evento) {
		historialClinico.push_back(evento);
	}

	void mostrarInformacion() {
		cout << "Nombre: " << nombre << endl;
		cout << "ID: " << indentificacion << endl;
		cout << "Fecha de Ingreso: " << fechaIngreso << endl;
		cout << "Historial Clinico: " << endl;
		for (const auto& evento : historialClinico) {
			cout << "- " << evento << endl;
		}
	}

	bool buscarPaciente(string criterio) {
		return nombre == criterio || indentificacion == criterio;
	}
};

