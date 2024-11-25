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

class GestorHospital {
private:
	vector<Paciente> listaPacientes;
	vector<Medico> listaMedicos;
	vector<CitaMedica> listaCitas;

public:
	void registrarPaciente(string nombre, string id, string fecha) {
		listaPacientes.push_back(Paciente(nombre, id, fecha));
	}

	void registrarMedico(string nombre, string especialidad, string id) {
		listaMedicos.push_back(Medico(nombre, especialidad, id));
	}

	void programarCita(string fecha, string idPaciente, string idMedico, int prioridad) {
		Paciente* paciente = nullptr;
		Medico* medico = nullptr;
		for (auto& p : listaPacientes) {
			if (p.buscarPaciente(idPaciente)) {
				paciente = &p;
				break;
			}
		}
		for (auto& m : listaMedicos) {
			if (m.verificarDisponibilidad() && m.verificarDisponibilidad()) {
				medico = &m;
				break;
			}
		}
		if (paciente && medico) {
			listaCitas.push_back(CitaMedica(fecha, paciente, medico, prioridad));
		}
	}

	void listarPacientes() {
		for (auto& paciente : listaPacientes) {
			paciente.mostrarInformacion();
		}
	}

	void listarMedicos() {
		for (auto& medico : listaMedicos) {
			medico.mostrarInformacion();
		}
	}

	void listarCitas() {
		for (auto& cita : listaCitas) {
			cita.mostrarDetalles();
		}
	}
};

int main() {
	GestorHospital gestor;
	gestor.registrarPaciente("Juan Perez", "12345", "2024-11-25");
	gestor.registrarMedico("Dr. Smith", "Cardiología", "67890");

	gestor.programarCita("2024-11-26 10:00", "12345", "67890", 1);

	gestor.listarPacientes();
	gestor.listarMedicos();
	gestor.listarCitas();

	return 0;
}