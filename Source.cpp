#include<iostream>
#include<string>
#include "Biblioteca.h"
#include "Libro.h"
using namespace std;

void mostrar_menu()
{
	cout << "::::::::MENU::::::::" << endl;
	cout << "1. Registrar libro" << endl;
	cout << "2. Listar todos los libros" << endl;
	cout << "3. Obtener un libro mediante su codigo" << endl;
	cout << "4. Reporte de libros por categoria" << endl;
	cout << "5. Reporte de libros publicados despues de un anio determinado" << endl;
	cout << "6. Salir" << endl;

	cout << "Elige una opcion: ";
}

int main()
{
	Biblioteca biblioteca;
	
	int opcion;
	
	do
	{
		system("cls");
		mostrar_menu();
		cin >> opcion;

		switch (opcion)
		{
		case 1:
		{
			int codigo;
			string titulo;
			string autor;
			string categoria;
			int anio;
			float precio;

			cout << "Codigo del libro: " << endl;
			cin >> codigo;
			cin.ignore();
			cout << "Titulo del libro: " << endl;
			getline(cin, titulo);
			cout << "Autor del libro: " << endl;
			getline(cin, autor);
			cout << "Categoria del libro: " << endl;
			getline(cin, categoria);
			cout << "Año del libro: " << endl;
			cin >> anio;
			cin.ignore();
			cout << "Precio del libro: " << endl;
			cin >> precio;
			cin.ignore();

			Libro* plibro = new Libro(codigo, titulo, autor, categoria, anio, precio);
			biblioteca.agregar_libro(plibro);
			cout << "Libro agregado." << endl;
			break;

		}
		case 2:
		{
			biblioteca.listar_libros();
			break;
		}

		case 3:
		{
			int codigo;
			cout << "Ingrese el codigo del libro: " << endl;
			cin >> codigo;

			Libro* encontrado = biblioteca.obtener_libros(codigo);

			if (encontrado != nullptr)
			{
				cout << encontrado->getcodigo() << " " << encontrado->gettitulo() << " " << encontrado->getautor() << " " << encontrado->getcategoria() << " " << encontrado->getanio() << " " << encontrado->getprecio() << endl;
			}
			else
			{
				cout << "Libro no encontrado" << endl;
			}

			break;

		}

		}

	}

	while (true);

}