#include "userinterface.h"

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void UserInterface::load()
{
	char* fileName = new char[sizeof "products.txt" + 1];
	strcpy_s(fileName, sizeof "products.txt" + 1, "products.txt");
	service.load(fileName);
	cout << "Incarcat!" << endl;
	print();
	delete[] fileName;
}

void UserInterface::save()
{
	service.save();
	cout << "Salvat!" << endl;
	print();
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
	delete[] name;
	cout << "Adaugat!" << endl;
}

void UserInterface::del()
{
	char* name = new char[30];
	cout << "Introduceti numele: ";
	cin >> name;
	service.del(name);
	delete[] name;
	cout << "Sters!" << endl;
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
	delete[] name;
	delete[] newName;
	cout << "Modificat!" << endl;
}

void UserInterface::customer_order()
{
	int n;
	vector<Product> cart;
	Customer c;
	cout << "Cate produse doriti sa cumparati?" << endl << "Introduceti: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char* name = new char[20];
		int no;
		cout << "Introduceti numele: ";
		cin >> name;
		cout << "Introduceti numarul de bucati: ";
		cin >> no;
		Product p(name, 0, no);
		cart.push_back(p);
		delete[] name;
	}
	cout << endl;
	int response = 0;
	for (auto it = cart.begin(); it != cart.end(); ++it)
	{
		Product crt = *it;
		response += c.customer_order_verify(service, crt);
		if (response == 1)
			break;
		if (response == 2)
			break;
	}
	if (response == 0)
	{
		for (auto it = cart.begin(); it != cart.end(); ++it)
		{
			Product crt = *it;
			c.customer_order(service, crt);
		}
		cout << "   Felicitari ca ti-ai cumparat facut cumparaturile la noi!" << endl;
	}
	else
		for (auto it = cart.begin(); it != cart.end(); ++it)
		{
			Product crt = *it;
			int response = c.customer_order_verify(service, crt);
			if (response == 1)
				cout << "   Mai usor cu " << crt.getName() << ". N-avem atat!";
			if (response == 2)
				cout << "   Nu avem " << crt.getName() << "!";
			cout << endl;
		}
}

void UserInterface::customer_return()
{
	Customer c;
	char* name = new char[20];
	int no;
	cout << "Introduceti numele: ";
	cin >> name;
	cout << "Introduceti numarul de bucati: ";
	cin >> no;
	Product p(name, 0, no);
	delete[] name;
	int response = c.customer_return(service, p);
	if (response == 0)
		cout << "   Felicitari, ai returnat " << p.getName() << "!";
	if (response == 1)
	{
		cout << "   Nu avem " << p.getName() << "! Ai gresit magazinul fratele meu!";
		char op;
		cout << endl << "   Mai incerci? 1-Da 2-Nu" << endl << "    Introduceti: ";
		cin >> op;
		if (op == '1')
			customer_return();
	}
	cout << endl;
}

void UserInterface::customer()
{
	char op;
	cout << endl;
	cout << " 1.Tur" << endl << " 2.Retur" << endl << " 3.Ups! Am gresit numarul!" << endl << " Introduceti: ";
	cin >> op;
	switch (op)
	{
	default: { no_command(); break; }
	case '1': { customer_order(); break; }
	case '2': { customer_return(); break; }
	case '3': { return; }
	}
}

void UserInterface::print()
{
	cout << "Produse: " << endl;
	for (auto it = service.getAll().begin(); it != service.getAll().end(); ++it)
	{
		Product crt = *it;
		cout << crt;
	}
}

void UserInterface::no_command()
{
	cout << "Comanda invalida" << endl;
}

void UserInterface::show()
{
	char op;
	cout << "Doriti sa incarcati din fisier? 1-Da  2-Nu" << endl << "Introduceti: ";
	cin >> op;
	if (op == '1')
		load();
	do
	{
		cout << endl << "1.Adaugare" << endl << "2.Stergere" <<
			endl << "3.Modificare" << endl << "4.Afisare" <<
			endl << "5.Incarcare din fisier" << endl << "6.Salvare" <<
			endl << "7.Sunt client! Scoate-ma de-aici!" <<
			endl << "8.Inchidere" << endl << "Hotel? Trivago" <<
			endl << "Introduceti: ";
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
		case '7': { customer(); break; }
		case '8': return;
		}
	} while (op);
}