#ifndef lista_H
#define lista_H
#include "model.h"
#include <nodo.h>
#include <iostream>
using std::cout;

template< typename Tipo >class cola;
template< typename Tipo >
class lista{
    friend class cola<Tipo>;
    friend class cframe;
public:
    lista();
    ~lista();
    void insertarAlFrente( const Tipo & );
    void insertarEnPenultimo(const Tipo & );
    void insertarAlFinal( const Tipo & );
    bool eliminarDelFrente( Tipo & );
    bool eliminarDelPenultimo( Tipo & );
    bool eliminarDelFinal( Tipo & );
    bool estaVacia() const;
    void imprimir() const;

    bool eliminar( Tipo & );
private:
    nodo< Tipo > *RaizPtr;
    nodo< Tipo > *FinPtr;
    nodo< Tipo > *obtenerNuevoNodo( const Tipo & );
};

// constructor predeterminado
template< typename Tipo >
lista< Tipo >::lista()
    : RaizPtr( 0 ), FinPtr( 0 ){ }

// destructor
template< typename Tipo >
lista< Tipo >::~lista(){
    if ( !estaVacia() ){
        cout << "Destruyendo nodos ...\n";
        nodo<Tipo> *actPrt = RaizPtr;
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


template< typename Tipo >
void lista< Tipo >::insertarAlFrente( const Tipo &valor ){
    nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor );
    if ( estaVacia() )
        RaizPtr = FinPtr = nuevoPtr;
    else{
        nuevoPtr->SigPtr = RaizPtr;
        RaizPtr = nuevoPtr;
    }
}

template< typename Tipo >
void lista< Tipo >::insertarEnPenultimo( const Tipo &valor ){
    nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor );
    if ( estaVacia() )
        RaizPtr = FinPtr = nuevoPtr;
    else{
        if(RaizPtr == FinPtr){
            nuevoPtr->SigPtr = RaizPtr;
            RaizPtr = nuevoPtr;
        }else if(RaizPtr->SigPtr == FinPtr){
            nuevoPtr->SigPtr = FinPtr;
            RaizPtr->SigPtr = nuevoPtr;
        }else{
            nodo<Tipo>*PenulPtr = RaizPtr;
            while(PenulPtr->SigPtr != FinPtr){
                PenulPtr = PenulPtr->SigPtr;
            }
            nuevoPtr->SigPtr = FinPtr;
            PenulPtr->SigPtr = nuevoPtr;
        }
    }
}

template< typename Tipo >
void lista< Tipo >::insertarAlFinal( const Tipo &valor ){
    nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor );
    if ( estaVacia() )
        RaizPtr = FinPtr = nuevoPtr;
    else{
        FinPtr->SigPtr = nuevoPtr;
        FinPtr = nuevoPtr;
    }
}



template< typename Tipo >
bool lista< Tipo >::eliminarDelFrente( Tipo &valor ){
    if ( estaVacia() )
        return false;
    else{
        nodo< Tipo > *tempPtr = RaizPtr;
        if ( RaizPtr == FinPtr )
            RaizPtr = FinPtr = 0;
        else
            RaizPtr = RaizPtr->SigPtr; // apunta al nodo que antes era el segundo
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}

template< typename Tipo >
bool lista<Tipo>::eliminar(Tipo & valor){

}

template< typename Tipo >
bool lista< Tipo >::eliminarDelPenultimo( Tipo &valor ){
    if ( estaVacia() )
        return false;
    else{
        nodo<Tipo> *tempPtr = RaizPtr;
        if ( RaizPtr == FinPtr )
            RaizPtr = FinPtr = 0;
        else if(RaizPtr->SigPtr == FinPtr){
            RaizPtr = RaizPtr->SigPtr;
        }else{
            nodo< Tipo > *actPrt = RaizPtr;
            while ( actPrt->SigPtr->SigPtr != FinPtr ){
                actPrt = actPrt->SigPtr;
            }
            tempPtr = actPrt->SigPtr;//Penultima
            actPrt->SigPtr = FinPtr;
        } // fin de else
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}

template< typename Tipo >
bool lista< Tipo >::eliminarDelFinal( Tipo &valor ){
    if ( estaVacia() )
        return false;
    else{
        nodo< Tipo > *tempPtr = FinPtr;
        if ( RaizPtr == FinPtr )
            RaizPtr = FinPtr = 0;
        else{
            nodo< Tipo > *actPrt = RaizPtr;
            // localiza el pen�ltimo elemento
            while ( actPrt->SigPtr != FinPtr )
                actPrt = actPrt->SigPtr;
            FinPtr = actPrt;
            actPrt->SigPtr = 0;
        } // fin de else
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}

// �est� la lista vac�a?
template< typename Tipo >
bool lista< Tipo >::estaVacia() const{
    return RaizPtr == 0;
} // fin de la funci�n estaVacia

// devuelve el apuntador al nodo reci�n asignado
template< typename Tipo >
nodo< Tipo > *lista< Tipo >::obtenerNuevoNodo(const Tipo &valor ){
    return new nodo< Tipo >( valor );
} // fin de la funci�n obtenerNuevonodo


template< typename Tipo >
void lista< Tipo >::imprimir() const{
    if ( estaVacia() ) {
        cout << "La lista esta vacia\n\n";
        return;
    }
    nodo< Tipo > *actPrt = RaizPtr;
    cout << "La lista es: ";
    while ( actPrt != 0 ) {
        cout << actPrt->datos << "\t";
        actPrt = actPrt->SigPtr;
    }
    cout << "\n\n";
}
#endif
