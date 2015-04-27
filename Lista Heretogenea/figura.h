#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include <iomanip>

#define PI 3.141592653589

using namespace std;
using std::setw; // permite que um programa configure a largura de um campo
using std::setprecision;
using std::fixed;

class figura
{
public:
    figura(){}
    virtual ~figura(){}
    virtual float area() = 0;
    virtual void imprime();
};

class retangulo : public figura
{
private:
    float b; /* base */
    float h; /* altura */
public:
    retangulo(float base, float altura):
    b(base), h(altura) {}
    virtual ~retangulo(){}
    float area() { return  b * h; }
    void imprime();
};

class circulo : public figura
{
private:
    float r; /* raio */
public:
    circulo(float raio): r(raio) {}
    virtual ~circulo() {}
    float area() { return (PI * r * r); }
    void imprime();
};

class triangulo : public figura
{
private:
    float b; /* base */
    float h; /* altura */
public:
    triangulo(float base, float altura): b(base), h(altura) {}
    virtual ~triangulo() {}
    float area() { return b * h / 2; }
    void imprime();
};
#endif