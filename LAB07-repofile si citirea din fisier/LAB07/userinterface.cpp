#include "userinterface.h"

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void UserInterface::load()
{
	char* fileName = new char[sizeof "products.txt" + 1];
	strcpy_s(fileName, sizeof "products.txt" + 1, "products.txt");
	service.load(fileName);
	print();
}

void UserInterface::save()
{
	service.save();
	cout << "Salvat!" << endl << endl;
}

void UserInterface::add()
{
	char* name = new char[30];
	int price, no;
	cout << "Introduceti numele: ";
	cin >> name;
	cout << "Introduceti pret: ";
	cin >> price;
	cout << "Introduceti numar de bucati: ";
	cin >> no;
	service.add(name, price, no);
	cout << "Adaugat!" << endl << endl;
	delete[] name;
}

void UserInterface::del()
{
	char* name = new char[30];
	cout << "Introduceti numele: ";
	cin >> name;
	service.del(name);
	cout << "Sters!" << endl << endl;
	delete[] name;
}

void UserInterface::mod()
{
	char* name = new char[30];
	char* newName = new char[30];
	int newPrice, newNo;
	cout << "Introduceti numele: ";
	cin >> name;
	cout << "Introduceti noile date, daca doriti sa nu modificati, introduceti -1!" << endl << "Introduceti noul nume: ";
	cin >> newName;
	cout << "Introduceti noul pret: ";
	cin >> newPrice;
	cout << "Introduceti noul numar de bucati: ";
	cin >> newNo;
	service.mod(name, newName, newPrice, newNo);
	cout << "Modificat!" << endl << endl;
	delete[] name;
	delete[] newName;
}

void UserInterface::print()
{
	cout << "Produse: " << endl;
	for (auto it = service.getAll().begin(); it != service.getAll().end(); ++it)
	{
		Product crt = *it;
		cout << crt;
	}
	cout << endl;
}

void UserInterface::no_command()
{
	cout << "Comanda invalida" << endl << endl;
}

void UserInterface::show()
{
	char op;
	cout << "Doriti sa incarcati din fisier? 1-DA  2-NU" << endl << "Introduceti: ";
	cin >> op;
	if (op == '1')
		load();
	do
	{
		cout << "1.Adaugare;" << endl << "2.Stergere;" << endl
			<< "3.Modificare;" << endl << "4.Afisare;" << endl
			<< "5.Incarcare din fisier;" << endl << "6.Salvare;" << endl
			<< "7.Inchidere." << endl << "Introduceti: ";
		cin >> op;
		switch (op)
		{
		default: { no_command(); break; }
		case '1': { add(); break; }
		case '2': { del(); break; }
		case '3': { mod(); break; }
		case '4': { print(); break; }
		case '5': { load(); break; }
		case '6': { save(); break; }
		case '7': return;
		}
	} while (op);
}