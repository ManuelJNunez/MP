#include <iostream>
#include <string>
#include "funciones.h"
#include "structs.h"

using namespace std;

const int KG_G = 1000, IVA = 21;

// función para devolver los datos de un producto como un string
string productoToString(Producto a)
{
    string rta;
    rta = a.nombre + "\t\t" + to_string(a.peso) + "\t" + to_string(a.precio_kg);
    return rta;
}

// crea una variable de tipo Producto y la devuelve
Producto creaProducto(string nombre, int peso, float precio)
{
	Producto nuevo = {nombre, peso, precio};

	return nuevo;
}

// incrementa el precio de cada producto en un k %
void incrementarPrecios(Compra & c, int k)
{
	for(int i = 0; i < c.MAX; i++)
		c.lista[i].precio_kg += c.lista[i].precio_kg * (k / 100.0);
}

// muestra el listado de productos comprados
void listarCompra(const Compra & c)
{
	for(int i = 0; i < c.MAX; i++)
		cout << productoToString(c.lista[i]) << endl;
}

// función que devuelve el importe total de la compra (sin IVA) y su peso (en kgs)
void obtenerImporteYPeso(const Compra & c, float & precio, float & peso)
{
	precio = peso = 0;

	for(int i = 0; i < c.MAX; i++){
		peso += c.lista[i].peso / (KG_G * 1.0);
		precio += ( c.lista[i].peso / (KG_G * 1.0)) * c.lista[i].precio_kg;
	}


}

// función que muestra el "ticket" de compra según el formato sugerido
void mostrarTicketCompra(const Compra & c)
{
	float peso, precio, iva;

	listarCompra(c);
	obtenerImporteYPeso(c, precio, peso);

	iva = precio * (IVA /100.0);

	cout << "Subtotal:\t\t" << precio << endl;
	cout << "IVA(21%):\t\t" << iva << endl;

	precio += iva;

	cout << "Total de la compra:\t" << precio << endl;
}