/* Listagen.h */
#ifndef LISTA_H
#define LISTA_H
#include "figura.h"
#include <iostream>

using namespace std;

template<class T> class listaFig{
protected:
    struct elo{
        T info;
        elo* prox;
        ~elo(){ delete info; }
        elo(const T& pInfo, elo* pProx = NULL )
        { info = pInfo; prox = pProx; }
    };
    elo * ini;  /* ponteiro para primeiro elemento */
public:
    listaFig(): ini(NULL) {};
    virtual ~listaFig();
    bool vazia();
    void insere(const T& novo);
    bool remove(const int n);
    void max_area() const;
    void imprime();
};

/* Testa se lista est� vazia */
template<class T> bool listaFig<T>::vazia(){
    return ( ini == NULL );
}

/* Insere elemento no in�cio da lista. */
template<class T> void listaFig<T>::insere(const T& novo){
    ini = new elo (novo, ini);
}

/* Remove da lista o n-esimo elemento. Ret. true se removeu. */
template<class T> bool listaFig<T>::remove(const int n){
    elo * anterior;
    elo * p;
    int k;
    
    for(p=ini, k=1; p!=NULL && k<n; p=p->prox, k++){
        anterior = p;
        // Achou
        if (k==n) {
            // É o primeiro
            if (p==ini){
                ini = p->prox;
            }
            else{
                anterior->prox = p->prox;
            }
            delete p;
            return true;
        }
    }
    return false;
}

/* Imprime a maior area */
template<class T> void listaFig<T>::max_area() const {
    float maior = 0;
    figura * figm;
    elo * p;
    int k, nmaior;
    figura * f;
    
    for( p = ini, k = 1; p!= NULL; p = p->prox, k++ ){
        f = p->info;
        if (f->area() > maior ){
            maior = f->area();
            figm = f;
            nmaior = k; 
        } 
    }
    
    cout << "Maior AREA: Figura " << nmaior << " ";
    figm->imprime();
}

/* Imprime todos os elementos da lista */
template<class T> void listaFig<T>::imprime() {
    elo * p;
    int k;
    
    for(p=ini, k=1; p!=NULL; p=p->prox, k++){
        figura * f = p->info;
        cout << "Figura " << k << " do tipo ";
        f->imprime();
    }
}

template<class T> listaFig<T>::~listaFig(){
    elo *p = ini;
    while(ini != NULL)
    {
        p = ini->prox;
        delete ini;
        ini = p;
    }
}

#endif