#include "CitaMedica.hpp"

CitaMedica::CitaMedica(string fecha, Paciente* pac, Medico* med, int prio)
    : fecha(fecha), paciente(pac), medico(med), prioridad(prio) {}

void CitaMedica::mostrarDetalles() const {
    cout << "Cita: " << fecha << ", Prioridad: " << prioridad << endl;
    paciente->mostrarInformacion();
    medico->mostrarInformacion();
}

}
