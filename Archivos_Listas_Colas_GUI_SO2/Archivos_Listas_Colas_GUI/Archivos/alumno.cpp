#include "alumno.h"

alumno::alumno()
{
    strcpy(this->Cuenta, "");
    strcpy(this->Nombre, "");
    strcpy(this->Celular, "");
}

alumno::alumno(string Cuenta, string Nombre, string Celular)
{
    strcpy(this->Cuenta, Cuenta.c_str());
    strcpy(this->Nombre, Nombre.c_str());
    strcpy(this->Celular, Celular.c_str());
}

alumno::alumno(char *Cuenta, char *Nombre, char *Celular)
{
    strcpy(this->Cuenta, Cuenta);
    strcpy(this->Nombre, Nombre);
    strcpy(this->Celular, Celular);
}

alumno::~alumno()
{
    delete this->Cuenta;
    delete this->Nombre;
    delete this->Celular;
}

char *alumno::getCuenta() const
{
    return Cuenta;
}

void alumno::setCuenta(char *newCuenta)
{
    Cuenta = newCuenta;
}

char *alumno::getNombre() const
{
    return Nombre;
}

void alumno::setNombre(char *newNombre)
{
    Nombre = newNombre;
}

char *alumno::getCelular() const
{
    return Celular;
}

void alumno::setCelular(char *newCelular)
{
    Celular = newCelular;
}
