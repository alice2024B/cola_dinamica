#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>

class persona {
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    float promedioGeneral;
public:
    persona();
    persona(std::string n, std::string c, int m, float p);
    void operator=(const persona& x);
    friend std::ostream& operator<<(std::ostream&, const persona&);
    friend std::istream& operator>>(std::istream&, persona&);
    std::string getNombre() const { return nombre; } // Método para obtener el nombre
};

class Cola {
private:
    struct Nodo {
        persona data;
        Nodo* siguiente;
        Nodo(const persona& d) : data(d), siguiente(nullptr) {}
    };

    Nodo* cabeza;
    Nodo* cola;

public:
    Cola() : cabeza(nullptr), cola(nullptr) {}
    ~Cola();
    bool vacia() const;
    void enqueue(const persona& elem);
    persona dequeue();
};

#endif // COLA_H



