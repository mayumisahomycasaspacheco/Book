#pragma once
#include "Libro.h"
#include<iostream>
using namespace std;

class Biblioteca
{
private:
	Libro** libro;
	int cantidad;
public:
	Biblioteca();
	~Biblioteca();

	void agregar_libro(Libro* plibro);
	void listar_libros();
	Libro* obtener_libros(int codigo);//Mediante codigo
	void reporte_categoria(string categoria);
	void reporte_anio(int anio);
};

Biblioteca::Biblioteca()
{
	libro = nullptr;
	cantidad = 0;
}

Biblioteca::~Biblioteca()
{
	for (int i = 0; i < cantidad; i++)
	{
		delete libro[i];
	}

	if (libro != nullptr)
	{
		delete[] libro;
	}
}

void Biblioteca::agregar_libro(Libro* plibro)
{
	Libro** temporal = new Libro * [cantidad + 1];

	for (int i = 0; i < cantidad; i++)
	{
		temporal[i] = libro[i];
	}

	temporal[cantidad] = plibro;

	cantidad = cantidad + 1;

	if (libro != nullptr)
	{
		delete[] libro;
	}

	libro = temporal;

}