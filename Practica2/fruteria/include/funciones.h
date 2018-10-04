#ifndef FUNCIONES
#define FUNCIONES
#include <string>
#include "structs.h"

using namespace std;

string productoToString(Producto a);
Producto creaProducto(string nombre, int peso, float precio);
void incrementarPrecios(Compra & c, int k);
void listarCompra(const Compra & c);
void obtenerImporteYPeso(const Compra & c, float & precio, float & peso);
void mostrarTicketCompra(const Compra & c);

#endif