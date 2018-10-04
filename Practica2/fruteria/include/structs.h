#ifndef STRUCTS
#define STRUCTS
#include <string>

using namespace std;

struct Producto
{
    string nombre;
    int peso; // en gramos
    float precio_kg;
};

struct Compra
{
    static const int MAX = 10;
    Producto lista[MAX];
};

#endif