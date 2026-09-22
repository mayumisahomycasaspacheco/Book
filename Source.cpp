#include<iostream>
#include<string>
#include <Windows.h>
#include "Biblioteca.h"
#include "Libro.h"
using namespace std;
using namespace System;

void libro(int x, int y)
{
	string lineas[11] = {

"       .--.                   .---.",
"   .---|__|           .-.     |~~~|",
".--|===|--|           |_|     |~~~|--.",
".--|===|--|_          |_|     |~~~|--.",
"|  |===|  |'\\     .---!~|  .--|   |--|",
"|%%|   |  |.'\\    |===| |--|%%|   |  |",
"|%%|   |  |\\.'\\   |   | |__|  |   |  |",
"|  |   |  | \\  \\  |===| |==|  |   |  |",
"|  |   |__|  \\.'\\ |   |_|__|  |~~~|__|",
"|  |===|--|   \\.'\\|===|~|--|%%|~~~|--|",
"^--^---'--^    `--'---^-^--^--^---'--'"

	};

	Console::SetCursorPosition(x, y);
	cout << lineas[0];
	Console::SetCursorPosition(x, y + 1);
	cout << lineas[1];
	Console::SetCursorPosition(x, y + 2);
	cout << lineas[2];
	Console::SetCursorPosition(x, y + 3);
	cout << lineas[3];
	Console::SetCursorPosition(x, y + 4);
	cout << lineas[4];
	Console::SetCursorPosition(x, y + 5);
	cout << lineas[5];
	Console::SetCursorPosition(x, y + 6);
	cout << lineas[6];
	Console::SetCursorPosition(x, y + 7);
	cout << lineas[7];
	Console::SetCursorPosition(x, y + 8);
	cout << lineas[8];
	Console::SetCursorPosition(x, y + 9);
	cout << lineas[9];
	Console::SetCursorPosition(x, y + 10);
	cout << lineas[10];
}

void mostrar_menu()
{
	SetConsoleOutputCP(65001);

	cout << "█▀▀▀▀▀▀▀▀▀▄   ▄▀▀▀▀▀▀▀▀▄   ▄▀▀▀▀▀▀▀▀▄  █▀▀▀▀█ ▓▀▀▀█" << endl;
	cout << "▀    ▄▄ .  █ ▀    ▄▄ .  █ ▀    ▄▄ .  █ ▀    ▓ ▒ ∙ █" << endl;
	cout << "▓    ▓ ▌   ▓ ▓    ▓ ▌   ▓ ▓    ▓ ▌   ▓ ▓    ▓▄░   ▓" << endl;
	cout << "▒  · ▀▀▀ ▀▄  ▒  · ▒ ▓   ▒ ▒  · ▒ ▓   ▒ ▒   ·▄▄▄  ▀▄" << endl;
	cout << "░    █▀▄·. ░ ░    ░▄░·. ░ ░    ░▄░·. ░ ░ .  ░ ░  .░" << endl;
	cout << "█   .▓▄▓   █ █   .      █ █   .      █ █    █ █∙  █" << endl;
	cout << "█▄▄▄▄▄▄▄▄▄▄█  ▀▄▄▄▄▄▄▄▄▀   ▀▄▄▄▄▄▄▄▄▀  █▄▄▄▄█ █▄▄▄█" << endl;

	cout << " " << endl;

	cout << "Imagine this: you're the most beloved librarian in your city, with endless shelves" << endl; 
	cout << "and a mess that only you understand... until now." << endl; 
	cout << "Book is here to save you." << endl; 
	cout << "Okay, you don't need to be a librarian to use it. In fact, it works for anyone" << endl; 
	cout << "who wants to organize their books without losing their mind." << endl; 
	cout << "But let's be honest: if you are one, this feels like a superpower." << endl;

	cout << " " << endl;

	cout << "============================MENU==============================" << endl;
	cout << "1. Register a book" << endl; 
	cout << "2. List all books" << endl; 
	cout << "3. Find a book by its code" << endl; 
	cout << "4. Report books by category" << endl; 
	cout << "5. Report books published after a given year" << endl; 
	cout << "6. Exit" << endl;

	cout << "Choose an option: ";

	int cursorX = Console::CursorLeft;
	int cursorY = Console::CursorTop;

	libro(72, 18);

	Console::SetCursorPosition(cursorX, cursorY);

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
			system("cls");

			int codigo;
			string titulo;
			string autor;
			string categoria;
			int anio;
			float precio;

			cout << "Book code: " << endl;
			cin >> codigo;
			cin.ignore();
			cout << "Book title: " << endl;
			getline(cin, titulo);
			cout << "Book author: " << endl;
			getline(cin, autor);
			cout << "Book category: " << endl;
			getline(cin, categoria);
			cout << "Book year: " << endl;
			cin >> anio;
			cin.ignore();
			cout << "Book price: " << endl;
			cin >> precio;
			cin.ignore();

			Libro* plibro = new Libro(codigo, titulo, autor, categoria, anio, precio);
			biblioteca.agregar_libro(plibro);
			cout << "Book added." << endl;

			system("pause");

			break;

		}
		case 2:
		{
			system("cls");

			biblioteca.listar_libros();

			system("pause");

			break;
		}

		case 3:
		{
			system("cls");

			int codigo;
			cout << "Enter the book code: " << endl;
			cin >> codigo;

			Libro* encontrado = biblioteca.obtener_libros(codigo);

			if (encontrado != nullptr)
			{
				cout << encontrado->getcodigo() << " " << encontrado->gettitulo() << " " << encontrado->getautor() << " " << encontrado->getcategoria() << " " << encontrado->getanio() << " " << encontrado->getprecio() << endl;
			}
			else
			{
				cout << "Book not found." << endl;
			}

			system("pause");

			break;

		}

		case 4:
		{
			system("cls");

			string categoria;
			cout << "Category to search for: " << endl;
			cin.ignore();
			getline(cin, categoria);

			biblioteca.reporte_categoria(categoria);

			system("pause");

			break;
		}

		case 5:
		{
			system("cls");

			int anio;
			cout << "Year to search for (later years will be shown): " << endl;
			cin >> anio;

			biblioteca.reporte_anio(anio);

			system("pause");

			break;
		}

		case 6:
		{
			cout << "Closing the program..." << endl;

			system("pause");

			break;
		}

		}

	}

	while (opcion != 6);

	return 0;

}