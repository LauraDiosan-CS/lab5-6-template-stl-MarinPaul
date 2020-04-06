#include "userinterface.h"

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

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

void UserInterface::command()
{
	char* name = new char[30];
	int no;
	cout << "Introduceti numele: ";
	cin >> name;
	cout << "Introduceti numarul de bucati: ";
	cin >> no;
	int i = service.command(name, no);
	if (i == 0)
		cout << "Felicitari! ATI REUSIT SA CUMPARATI!!!!!!!!";
	if (i == 1)
		cout << "Mai usor cu hartia igienica, n-avem atat!";
	if (i == 2)
		cout << "Nu avem asa ceva!!";
	cout << endl;
}

void UserInterface::print()
{
	cout << "Produse: " << endl;
	for (auto it = service.getAll().begin(); it != service.getAll().end(); ++it)
		cout << (*it);
	cout << endl;
}

void UserInterface::show()
{
	char op;
	do
	{	
		cout << "1.Adaugare;" << endl << "2.Stergere;" << endl
			<< "3.Modificare;" << endl << "4.Afisare;" << endl
			<< "5.Cumparare;" << endl
			<< "6.Inchidere." << endl << "Introduceti: ";
		cin >> op;
		switch (op)
		{
		default: { cout << "Comanda invalida" << endl << endl; break; }
		case '1': { add(); break; }
		case '2': { del(); break; }
		case '3': { mod(); break; }
		case '4': { print(); break; }
		case '5': { command(); break; }
		case '6': return;
		}
	} while (op);
}
