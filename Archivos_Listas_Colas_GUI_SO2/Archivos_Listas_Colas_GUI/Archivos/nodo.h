#ifndef nodo_H
#define nodo_H

template< typename Tipo > class cola;
template< typename Tipo > class lista;
template< typename Tipo >
class nodo{
    friend class cola<Tipo>;
    friend class lista<Tipo>;
    friend class cframe;
public:
    nodo( const Tipo & );
    Tipo obtenerDatos() const;
private:
    Tipo datos;
    nodo<Tipo> *SigPtr;
};

// constructor
template< typename Tipo >
nodo<Tipo>::nodo( const Tipo &datos )
    : datos( datos ), SigPtr( 0 ){ }

// devuelve una copia de los datos en el nodo
template<typename Tipo>
Tipo nodo<Tipo>::obtenerDatos() const
{
    return datos;
}
#endif
