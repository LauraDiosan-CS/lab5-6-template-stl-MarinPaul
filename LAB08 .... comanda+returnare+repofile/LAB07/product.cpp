#include "product.h"

Product::Product()
{
	name = NULL;
	price = 0;
	no = 0;
}

Product::Product(const char* new_name, const int new_price, const int new_no)
{
	setName(new_name);
	setPrice(new_price);
	setNo(new_no);
}

Product::Product(const Product& p)
{
	setName(p.name);
	setPrice(p.price);
	setNo(p.no);
}

Product::~Product()
{
	if (name)
		delete[] name;
	name = NULL;
	price = 0;
	no = 0;
}
Product& Product::operator=(const Product& p)
{
	setName(p.name);
	setPrice(p.price);
	setNo(p.no);
	return *this;
}

bool Product::operator==(const Product& p) const
{
	return (strcmp(name, p.name) == 0);
}

bool Product::operator!=(const Product& p) const
{
	return !(operator==(p));
}

bool Product::operator<(const Product& p) const
{
	return (strcmp(name, p.name) < 0);
}

bool Product::operator<=(const Product& p) const
{
	return (strcmp(name, p.name) <= 0);
}

bool Product::operator>(const Product& p) const
{
	return (strcmp(name, p.name) > 0);
}

bool Product::operator>=(const Product& p) const
{
	return (strcmp(name, p.name) >= 0);
}

ostream& operator<<(ostream& os, Product& p)
{
	os << p.name << " " << p.price << " " << p.no << endl;
	return os;
}

istream& operator>>(istream& is, Product& p)
{
	char* name = new char[30];
	int price, no;
	is >> name >> price >> no;
	if (strcmp(name, "") == 0)
	{
		p = def;
		return is;
	}
	p.setName(name);
	p.setPrice(price);
	p.setNo(no);
	delete[] name;
	return is;
}

char* Product::getName() { return name; }

int Product::getPrice() { return price; }

int Product::getNo() { return no; }

void Product::setName(const char* new_name)
{
	name = new char[strlen(new_name) + 1];
	strcpy_s(name, strlen(new_name) + 1, new_name);
}

void Product::setPrice(const int new_price)
{
	price = new_price;
}

void Product::setNo(const int new_no)
{
	no = new_no;
}
