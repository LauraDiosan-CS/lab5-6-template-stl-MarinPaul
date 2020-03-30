#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Product
{
private:
	char* name;
	int price;
	int no;
public:
	Product();
	Product(const char*, const int, const int);
	Product(const Product&);
	~Product();
	Product& operator=(const Product&);
	bool operator==(const Product&) const;
	bool operator!=(const Product&) const;
	bool operator<(const Product&) const;
	bool operator<=(const Product&) const;
	bool operator>(const Product&) const;
	bool operator>=(const Product&) const;
	friend ostream& operator<<(ostream&, const Product&);
	char* getName();
	int getPrice();
	int getNo();
	void setName(const char*);
	void setPrice(const int);
	void setNo(const int);
};