#include "tests.h"

void ProductTests()
{
	Product p;
	Product p1;
	Product p2("mar", 1, 100);
	Product p3(p2);
	p = p2;
	assert(p2 == p3);
	assert(p == p2);
	p.setName("para");
	p.setPrice(2);
	p.setNo(5);
	assert(strcmp(p.getName(), "para") == 0 && p.getPrice() == 2 && p.getNo() == 5);
}

void RepoTests()
{
	Product p1("mar", 1, 100);
	Product p2("mar", 2, 50);
	Product p3("para", 3, 1000);
	Repo products;
	products.add(p1);
	products.add(p2);
	products.add(p3);
	assert(products.size() == 2);
}

void tests()
{
	ProductTests();
	RepoTests();
}