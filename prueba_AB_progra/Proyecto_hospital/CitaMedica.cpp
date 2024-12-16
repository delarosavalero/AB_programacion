#include "CitaMedica.hpp"

CitaMedica::CitaMedica(string fecha, Paciente* pac, Medico* med, int prio)
    : fecha(fecha), paciente(pac), medico(med), prioridad(prio) {}

void CitaMedica::mostrarDetalles() const {
    cout << "Cita: " << fecha << ", Prioridad: " << prioridad << endl;
    paciente->mostrarInformacion();
    medico->mostrarInformacion();
}

void CitaMedica::cancelarCita() {
    cout << "Cita cancelada." << endl;
}

void CitaMedica::modificarCita(string nuevaFecha, int nuevaPrioridad) {
    fecha = nuevaFecha;
    prioridad = nuevaPrioridad;
}

void CitaMedica::guardarDatos(ofstream& outFile) const {
    outFile << fecha << "," << prioridad << endl;
}

CitaMedica CitaMedica::recuperarDatos(ifstream& inFile, vector<Paciente>& pacientes, vector<Medico>& medicos) {
    string fecha;
    int prioridad;
    getline(inFile, fecha, ',');
    inFile >> prioridad;
    inFile.ignore(); 

    Paciente* paciente = &pacientes[0]; 
    Medico* medico = &medicos[0];        

    return CitaMedica(fecha, paciente, medico, prioridad);
}
