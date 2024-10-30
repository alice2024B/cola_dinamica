#include "Cola.h"

// Constructor por defecto de la clase persona
persona::persona() : nombre("Juanito"), carrera(""), materiasAprobadas(0), promedio(0.0) {}

persona::persona(std::string n, std::string c, int m, float p)
    : nombre(n), carrera(c), materiasAprobadas(m), promedio(p) {}

// Constructor de copia
persona::persona(const persona& x) {
    nombre = x.nombre;
    carrera = x.carrera;
    materiasAprobadas = x.materiasAprobadas;
    promedio = x.promedio;
}

// Operador de asignaci�n
persona& persona::operator=(const persona& x) {
    if (this != &x) { // Evitar la auto-asignaci�n
        nombre = x.nombre;
        carrera = x.carrera;
        materiasAprobadas = x.materiasAprobadas;
        promedio = x.promedio;
    }
    return *this; // Retorna el objeto actual
}

std::ostream& operator<<(std::ostream& o, const persona& p) { // Cambiado a const
    o << "Nombre: " << p.nombre << "\tCarrera: " << p.carrera
      << "\tMaterias Aprobadas: " << p.materiasAprobadas
      << "\tPromedio: " << p.promedio;
    return o;
}

std::istream& operator>>(std::istream& o, persona& p) {
    std::cout << "\nInserta nombre: ";
    o >> p.nombre;
    std::cout << "Inserta carrera: ";
    o >> p.carrera;
    std::cout << "Inserta materias aprobadas: ";
    o >> p.materiasAprobadas;
    std::cout << "Inserta promedio: ";
    o >> p.promedio;
    return o;
}

std::string persona::getNombre() const {
    return nombre; // Devuelve el nombre
}

bool Cola::vacia() const {
    return ult == -1;
}

bool Cola::llena() const {
    return ult == TAM - 1;
}

int Cola::ultimo() const {
    return ult;
}

std::ostream& operator<<(std::ostream & o, Cola& L) {
    for (int i = 0; i <= L.ultimo(); i++) {
        o << L.datos[i] << std::endl;
    }
    return o;
}

void Cola::enqueue(persona& elem) {
    inserta(elem, ult + 1);
}

persona Cola::dequeue() {
    if (vacia()) {
        std::cout << "\nLa cola esta vacia" << std::endl;
        return persona(); // Retorna un objeto vac�o en caso de cola vac�a
    }
    persona elem = datos[0];
    elimina(0);
    return elem;
}

bool Cola::elimina(int pos) {
    if (vacia() || pos < 0 || pos > ult) {
        std::cout << "\nError de eliminacion" << std::endl;
        return true;
    }
    for (int i = pos; i < ult; i++) {
        datos[i] = datos[i + 1];
    }
    ult--;
    return false;
}

int Cola::inserta(persona& elem, int pos) {
    if (llena() || pos < 0 || pos > ult + 1) {
        std::cout << "\nError de insercion" << std::endl;
        return 0;
    }
    for (int i = ult + 1; i > pos; i--) {
        datos[i] = datos[i - 1];
    }
    datos[pos] = elem;
    ult++;
    return 1;
}

int Cola::buscarSolicitud(const std::string& nombre) const {
    for (int i = 0; i <= ult; i++) {
        if (datos[i].getNombre() == nombre) {
            return i; // Retorna la posici�n si se encuentra
        }
    }
    return -1; // Retorna -1 si no se encuentra
}

// M�todo para ordenar la cola por nombre
void Cola::ordenar() {
    for (int i = 0; i < ult; i++) {
        for (int j = 0; j < ult - i; j++) {
            if (datos[j].getNombre() > datos[j + 1].getNombre()) {
                std::swap(datos[j], datos[j + 1]);
            }
        }
    }
}

// M�todo de b�squeda binaria
int Cola::buscarSolicitudBinaria(const std::string& nombre) const {
    int izquierda = 0;
    int derecha = ult;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (datos[medio].getNombre() == nombre) {
            return medio; // Se encontr� el elemento
        }
        if (datos[medio].getNombre() < nombre) {
            izquierda = medio + 1; // Buscar en la mitad derecha
        } else {
            derecha = medio - 1; // Buscar en la mitad izquierda
        }
    }
    return -1; // No se encontr�
}
