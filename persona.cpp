#include <iostream>
#include "persona.hpp"

using namespace std;

Persona::Persona() : alumno(), codigo("") {}

Name Persona::getAlumno() const {
    return alumno;
}

string Persona::getCodigo() const {
    return codigo;
}

string Persona::toString() const {
    string result;

    result += "|Codigo: ";
    result += codigo;
    result.resize(20, ' ');
    result += "|Alumno: ";
    result += alumno.toString();
    result.resize(60, ' ');
    result += " |";

    return result;
}

void Persona::setAlumno(const Name& al) {
    alumno = al;
}

void Persona::setCodigo(const std::string& c) {
    codigo = c;
}

//bool Persona::operator==(const Persona& a) const {
//    return codigo == a.codigo;
//}
//
//bool Persona::operator!=(const Persona& a) const {
//      return !(*this == a);
//}
//
//bool Persona::operator>(const Persona& a) const {
//    return !(*this <= a);
//}
//
//bool Persona::operator>=(const Persona& a) const {
//    return !(*this < a);
//}
//
//bool Persona::operator<(const Persona& a) const {
//    return codigo < a.codigo;
//}
//
//bool Persona::operator<=(const Persona& a) const {
//    return *this < a or *this == a;
//}

bool Persona::operator==(const Persona& a) const {
    return alumno.toString() == a.alumno.toString();
}

bool Persona::operator!=(const Persona& a) const {
      return !(*this == a);
}

bool Persona::operator>(const Persona& a) const {
    return !(*this <= a);
}

bool Persona::operator>=(const Persona& a) const {
    return !(*this < a);
}

bool Persona::operator<(const Persona& a) const {
    return alumno.toString() < a.alumno.toString();
}

bool Persona::operator<=(const Persona& a) const {
    return *this < a or *this == a;
}


int Persona::compareByPerson(const Persona& a, const Persona& b) {
    return a.alumno.toString().compare(b.alumno.toString());
}

int Persona::compareByCode(const Persona& a, const Persona& b) {
    return a.codigo.compare(b.codigo);
}

ostream& operator << (ostream& os, const Persona &p) {
  os << p.alumno << '|'
     << p.codigo << '*' << endl;
  return os;
  }

istream& operator >> (istream& is, Persona& p) {
  is >> p.alumno;
  getline(is, p.codigo, '*');
  return is;
  }

