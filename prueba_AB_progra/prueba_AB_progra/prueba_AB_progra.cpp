// prueba_AB_progra.cpp: define el punto de entrada de la aplicación.
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

class Medico {
private:
	string nombre;
	string especialidad;
	string identificacion;
	bool disponibilidad;

public:
	Medico(string nom, string esp, string id) : nombre(nom), especialidad(esp), identificacion(id), disponibilidad(true) {}

	void asignarDisponibilidad(bool estado) {
		disponibilidad = estado;
	}

	void mostrarInformacion() {
		cout << "Nombre: " << nombre << ", Especialidad: " << especialidad << ", ID: " << identificacion << endl;
	}

	bool verificarDisponibilidad() {
		return disponibilidad;
	}
};

class CitaMedica {
private:
	string fecha;
	Paciente* paciente;
	Medico* medico;
	int prioridad;

public:
	CitaMedica(string fecha, Paciente* pac, Medico* med, int prio) : fecha(fecha), paciente(pac), medico(med), prioridad(prio) {}

	void mostrarDetalles() {
		cout << "Cita: " << fecha << ", Prioridad: " << prioridad << endl;
		paciente->mostrarInformacion();
		medico->mostrarInformacion();
	}

	void cancelarCita() {
		cout << "Cita cancelada." << endl;
		
	}

	void modificarCita(string nuevaFecha, int nuevaPrioridad) {
		fecha = nuevaFecha;
		prioridad = nuevaPrioridad;
	}
};