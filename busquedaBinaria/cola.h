#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>
#include <algorithm> // Para std::swap

const int TAM = 100;

//***************************Definicion de la clase persona*************************
class persona {
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    float promedio;
public:
    persona();
    persona(std::string n, std::string c, int m, float p);
    persona(const persona& x); // Constructor de copia
    persona& operator=(const persona& x); // Operador de asignación
    friend std::ostream& operator<<(std::ostream&, const persona&); // Cambiado a const
    friend std::istream& operator>>(std::istream&, persona&);
    std::string getNombre() const; // Getter para el nombre
};

//***********************************************************************************

//****************************Definicion de la clase Cola***************************
class Cola {
private:
    persona datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(persona& elem, int pos);
public:
    Cola() : ult(-1) {}
    bool vacia() const;
    bool llena() const;
    int ultimo() const;
    friend std::ostream& operator<<(std::ostream & o, Cola& L);
    void enqueue(persona& elem);
    persona dequeue();
    int buscarSolicitud(const std::string& nombre) const; // Búsqueda lineal
    void ordenar(); // Método para ordenar
    int buscarSolicitudBinaria(const std::string& nombre) const; // Búsqueda binaria
};
//*************************************************************************************

#endif // COLA_H
