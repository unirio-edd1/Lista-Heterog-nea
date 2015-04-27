#include <iostream>
#include "listagen.h"
#include "figura.h"

int main(int argc, char *argv[])
{
    
    listaFig <figura*> Lista;
    
    figura * ret;
    figura * cir;
    figura * tri;
    
    ret = new retangulo(5.0,2.0);
    Lista.insere(ret);
    cir = new circulo(3.0);
    Lista.insere(cir);
    tri = new triangulo(2.0, 3.0);
    Lista.insere(tri);
    ret = new retangulo(4.0,3.0);
    Lista.insere(ret);
    cir = new circulo(2.0);
    Lista.insere(cir);
    ret = new retangulo(2.0,1.0);
    Lista.insere(ret);
    cir = new circulo(1.0);
    Lista.insere(cir);
    tri = new triangulo(4.0, 3.0);
    Lista.insere(tri);
    
    Lista.imprime();
    
    Lista.max_area();
    
    Lista.remove(2);
    Lista.imprime();
    
    Lista.remove(1);
    Lista.imprime();
    
    Lista.remove(4);
    Lista.imprime();
    
    Lista.max_area();
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}