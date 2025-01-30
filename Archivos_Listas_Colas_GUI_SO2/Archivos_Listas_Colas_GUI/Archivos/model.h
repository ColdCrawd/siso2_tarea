#ifndef MODEL_H
#define MODEL_H
#include <iostream>
using std::cout;

//template< typename Tipo >
class model{
    friend class cframe;
public:
    model();
    model(std::string nombre, int tam, bool disponible);

    std::string getNombre() const;
    void setNombre(const std::string &newNombre);

    int getTam() const;
    void setTam(int newTam);

    bool getDisponible() const;
    void setDisponible(bool newDisponible);

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

inline int model::getTam() const
{
    return tam;
}

inline void model::setTam(int newTam)
{
    tam = newTam;
}

inline bool model::getDisponible() const
{
    return disponible;
}

inline void model::setDisponible(bool newDisponible)
{
    disponible = newDisponible;
}

#endif // MODEL_H
