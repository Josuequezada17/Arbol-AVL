#ifndef PERSONA_HPP_INCLUDED
#define PERSONA_HPP_INCLUDED

#include <iostream>

#include "name.hpp"

class Persona{
private:
    Name alumno;
    std::string codigo;

public:
    Persona();

    Name getAlumno()const;
    std::string getCodigo()const;

    std::string toString()const;

    void setAlumno(const Name&);
    void setCodigo(const std::string&);

    bool operator == (const Persona&) const;
    bool operator != (const Persona&) const;
    bool operator >  (const Persona&) const;
    bool operator >= (const Persona&) const;
    bool operator <  (const Persona&) const;
    bool operator <= (const Persona&) const;

    static int compareByPerson(const Persona&, const Persona&);
    static int compareByCode  (const Persona&, const Persona&);

    friend std::ostream& operator << (std::ostream&, const Persona&);
    friend std::istream& operator >> (std::istream&, Persona&);


};

#endif // PERSONA_HPP_INCLUDED
