#include "Cola.h"

// Constructor por defecto
persona::persona() : nombre("Juanito"), carrera("Informatica"), materiasAprobadas(0), promedioGeneral(0.0) {}

persona::persona(std::string n, std::string c, int m, float p) : nombre(n), carrera(c), materiasAprobadas(m), promedioGeneral(p) {}

void persona::operator=(const persona& x) {
    nombre = x.nombre;
    carrera = x.carrera;
    materiasAprobadas = x.materiasAprobadas;
    promedioGeneral = x.promedioGeneral;
}

std::ostream& operator<<(std::ostream& o, const persona& p) {
    o << "Nombre: " << p.nombre
      << "\tCarrera: " << p.carrera
      << "\tMaterias Aprobadas: " << p.materiasAprobadas
      << "\tPromedio: " << p.promedioGeneral << std::endl;
    return o;
}

std::istream& operator>>(std::istream& o, persona& p) {
    std::cout << "Inserta nombre: ";
    o >> p.nombre;
    std::cout << "Inserta carrera: ";
    o >> p.carrera;
    std::cout << "Inserta materias aprobadas: ";
    o >> p.materiasAprobadas;
    std::cout << "Inserta promedio: ";
    o >> p.promedioGeneral;
    return o;
}

// Métodos de la clase Cola
bool Cola::vacia() const {
    return cabeza == nullptr;
}

void Cola::enqueue(const persona& elem) {
    Nodo* nuevo = new Nodo(elem);
    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
}

persona Cola::dequeue() {
    if (vacia()) {
        std::cerr << "La cola esta vacia." << std::endl;
        return persona(); // Retorna un objeto persona vacío
    }
    Nodo* temp = cabeza;
    cabeza = cabeza->siguiente;
    persona data = temp->data;
    delete temp;
    return data;
}

Cola::~Cola() {
    while (!vacia()) {
        dequeue();
    }
}



