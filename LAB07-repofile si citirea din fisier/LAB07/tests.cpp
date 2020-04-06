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
	Repo<Product> products;
	products.add(p1);
	products.add(p2);
	products.add(p3);
	assert(products.size() == 2);
	Product p4("suc", 4, 100);
	products.del(p3);
	assert(products.size() == 1);
	products.mod(p1, p4);
	assert(*(products.getAll().begin()) == p4);
	products.add(p3);
	assert(products.find_by_title("para") == p3);
}

void ServiceTests()
{
	Service<Product> service;
	Product p1("mar", 1, 100);
	service.add("mar", 1, 100);
	assert(*(service.getAll().begin()) == p1);
	service.add("par", 2, 50);
	assert(service.size() == 2);
	service.del("par");
	assert(service.size() == 1);
	Product p3("para", 3, 1000);
	service.mod("mar", "para", 3, 1000);
	assert(*(service.getAll().begin()) == p3);
}

void tests()
{
	ProductTests();
	RepoTests();
	ServiceTests();
}