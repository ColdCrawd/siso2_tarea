#ifndef COLA_H
#define COLA_H
#include <lista.h>

template<typename Tipo>
class cola : public lista<Tipo> 
{
public:
    cola();
    ~cola();
    void Encolar(const Tipo &);
    bool Desencolar(Tipo &);
    bool ColaVacia()const;
    void imprimir()const;
};

template<typename Tipo>
cola<Tipo>::cola():lista<Tipo> ()
{}

template<typename Tipo>
cola<Tipo>::~cola()
{
    if ( !ColaVacia() ){
        cout << "Destruyendo nodos ...\n";
        nodo<Tipo> *actPrt = lista<Tipo>::RaizPtr;
        nodo<Tipo> *tempPtr;
        while ( actPrt != 0 ){
            tempPtr = actPrt;
            cout << tempPtr->datos << "\t";
            actPrt = actPrt->SigPtr;
            delete tempPtr;
        }
    }
    cout << "Se destruyeron todos los nodos\n\n";
}

template<typename Tipo>
void cola<Tipo>::Encolar(const Tipo &valor)
{
    lista<Tipo>::insertarAlFinal(valor);
}

template<typename Tipo>
bool cola<Tipo>::Desencolar(Tipo &valor)
{
    return lista<Tipo>::eliminarDelFrente(valor);
}

template<typename Tipo>
bool cola<Tipo>::ColaVacia() const
{
    return lista<Tipo>::estaVacia();
}

template<typename Tipo>
void cola<Tipo>::imprimir() const
{
    lista<Tipo>::imprimir();
}

#endif // COLA_H
