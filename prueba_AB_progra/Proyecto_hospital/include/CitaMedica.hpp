#ifndef CITAMEDICA_HPP
#define CITAMEDICA_HPP


#include <string>
#include<iostream>
#include<vector>
#include "Paciente.hpp"
#include "Medico.hpp"

class CitaMedica {
private:
    int ID;                 
    int IDPaciente;         
    int IDMedico;           
    string fechaCita;  
    int nivel;              
    static int Identificacion;         

public:
    
    CitaMedica() : ID(0), IDPaciente(0), IDMedico(0), fechaCita(""), nivel(0) {}

    
    CitaMedica(int IDPaciente, int IDMedico, const string& fechaCita, int nivel);

    
    void mostrarCita() const;

    
    int getID() const { return ID; }
    int getIDPaciente() const { return IDPaciente; }
    int getIDMedico() const { return IDMedico; }
    string getFechaCita() const { return fechaCita; }
    int getNivel() const { return nivel; }

  
    void setIDPaciente(int nuevoIDPaciente) { IDPaciente = nuevoIDPaciente; }
    void setIDMedico(int nuevoIDMedico) { IDMedico = nuevoIDMedico; }
    void setFecha(const string& nuevaFecha) { fechaCita = nuevaFecha; }
    void setNivel(int nuevoNivel) { nivel = nuevoNivel; }

    
    static int generarIdentificacion();

    static void guardarCita(const CitaMedica& citaMedica);

};

#endif
