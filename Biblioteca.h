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

void Biblioteca::listar_libros()
{
	if (cantidad == 0)
	{
		cout << "No books registered." << endl;
		return;
	}

	cout << endl << "Pos\tCode\t\tTitle\t\tAuthor\t\tCategory\t\tYear\t\tPrice" << endl;

	for (int i = 0; i < cantidad; i++)
	{
		cout << i << "\t" << libro[i]->getcodigo() << "\t\t" << libro[i]->gettitulo() << "\t\t" << libro[i]->getautor() << "\t\t" << libro[i]->getcategoria() << "\t\t" << libro[i]->getanio() << "\t\t" << libro[i]->getprecio() << endl;
	}
}

Libro* Biblioteca::obtener_libros(int codigo)
{
	for (int i = 0; i < cantidad; i++)
	{
		if (libro[i]->getcodigo() == codigo)
		{
			return libro[i];
		}
	}

	return nullptr;

}

void Biblioteca::reporte_categoria(string categoria)
{
	for (int i = 0; i < cantidad; i++)
	{
		if (libro[i]->getcategoria() == categoria)
		{
			cout << i << "\t" << libro[i]->getcategoria() << endl;
		}

	}
}

void Biblioteca::reporte_anio(int anio)
{
	for (int i = 0; i < cantidad; i++)
	{
		if (libro[i]->getanio() > anio)
		{
			cout << i << "\t" << libro[i]->getanio() << endl;
		}
	}
}