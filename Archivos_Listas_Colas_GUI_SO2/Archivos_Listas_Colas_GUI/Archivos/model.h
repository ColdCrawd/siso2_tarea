#ifndef MODEL_H
#define MODEL_H
#include <iostream>
using std::cout;

//template< typename Tipo >
class model{
    friend class cframe;
public:
    model(std::string nombre, int tam, bool disponible);

    std::string getNombre() const;
    void setNombre(const std::string &newNombre);

private:
    std::string nombre;
    int tam;
    bool disponible;
    //Tipo informacion;
};

//template< typename Tipo >
inline model::model(std::string nombre, int tam, bool disponible){
    this->nombre = nombre;
    this->tam = tam;
    this->disponible = disponible;
}

#endif // MODEL_H
