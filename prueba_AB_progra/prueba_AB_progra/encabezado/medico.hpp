#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Medico {
private:
    string nombre;
    string especialidad;
    string identificacion;
    bool disponibilidad;

public:
    Medico(string nom, string esp, string id);
};

#endif // MEDICO_HPP
