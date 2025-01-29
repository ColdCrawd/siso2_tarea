#ifndef ALUMNO_H
#define ALUMNO_H

#include <cstring>
#include <QMainWindow>
using std::string;

class alumno
{
public:
    alumno();
    alumno(string Cuenta, string Nombre, string Celular);
    alumno(char *Cuenta, char *Nombre, char *Celular);
    ~alumno();
    char *getCuenta() const;
    void setCuenta(char *newCuenta);

    char *getNombre() const;
    void setNombre(char *newNombre);

    char *getCelular() const;
    void setCelular(char *newCelular);

private:
    char *Cuenta = new char[8], *Nombre = new char[40], *Celular = new char[14];


};

#endif // ALUMNO_H
