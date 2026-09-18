#pragma once
#include<iostream>
using namespace std;

class Libro
{
private:
	int codigo;
	string titulo;
	string autor;
	string categoria;
	int anio;
	float precio;
public:
	Libro(int pcodigo, string ptitulo, string pautor, string pcategoria, int panio, float pprecio);
	~Libro();

	int getcodigo();
	string gettitulo();
	string getautor();
	string getcategoria();
	int getanio();
	float getprecio();

	void setcodigo(int pcodigo);
	void settitulo(string ptitulo);
	void setautor(string pautor);
	void setcategoria(string pcategoria);
	void setanio(int panio);
	void setprecio(float pprecio);
};

Libro::Libro(int pcodigo, string ptitulo, string pautor, string pcategoria, int panio, float pprecio)
{
	codigo = pcodigo;
	titulo = ptitulo;
	autor = pautor;
	categoria = pcategoria;
	anio = panio;
	precio = pprecio;
}

Libro::~Libro()
{
}

int Libro::getcodigo()
{
	return codigo;
}

string Libro::gettitulo()
{
	return titulo;
}

string Libro::getautor()
{
	return autor;
}

string Libro::getcategoria()
{
	return categoria;
}

int Libro::getanio()
{
	return anio;
}

float Libro::getprecio()
{
	return precio;
}

void Libro::setcodigo(int pcodigo)
{
	codigo = pcodigo;
}

void Libro::settitulo(string ptitulo)
{
	titulo = ptitulo;
}

void Libro::setautor(string pautor)
{
	autor = pautor;
}

void Libro::setcategoria(string pcategoria)
{
	categoria = pcategoria;
}

void Libro::setanio(int panio)
{
	anio = panio;
}

void Libro::setprecio(float pprecio)
{
	precio = pprecio;
}