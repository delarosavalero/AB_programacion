#include "Medico.hpp"

string Medico::getNombre() const
{
    return string();
}

Medico::Medico(string nom, string esp, string id)
    : nombre(nom), especialidad(esp), identificacion(id), disponibilidad(true) {}

string Medico::getNombre() conts {
    return nombre;
}

void Medico::asignarDisponibilidad(bool estado) {
    disponibilidad = estado;
}

void Medico::mostrarInformacion() const {
    cout << "Nombre: " << nombre << ", Especialidad: " << especialidad << ", ID: " << identificacion << endl;
}

bool Medico::verificarDisponibilidad() const {
    return disponibilidad;
}

void Medico::guardarDatos(ofstream& outFile) const {
    outFile << nombre << "," << especialidad << "," << identificacion << "," << disponibilidad << endl;
}

Medico Medico::recuperarDatos(ifstream& inFile) {
    string nombre, especialidad, id;
    bool disponibilidad;
    getline(inFile, nombre, ',');
    getline(inFile, especialidad, ',');
    getline(inFile, id, ',');
    inFile >> disponibilidad;
    inFile.ignore(); 
    return Medico(nombre, especialidad, id);
}
