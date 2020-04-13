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
}

void RepoFileTests()
{
	RepoFile<Product> repo1("assert.txt");
	RepoFile<Product> repo2;
	repo2.load("tests.txt");
	Product p1 = *repo2.getAll().begin();
	Product p2 = *(++repo2.getAll().begin());
	assert(strcmp(p1.getName(), "mar") == 0 && p1.getPrice() == 1 && p1.getNo() == 100);
	assert(strcmp(p2.getName(), "tigari") == 0 && p2.getPrice() == 20 && p2.getNo() == 2);
	repo2.save();
	assert(repo1 == repo2);

}

void ServiceTests()
{
	Service service;
	Product p1("mar", 1, 100);
	service.add("mar", 1, 100);
	assert(service.find_by_name("mar") == p1);
	assert(*(service.getAll().begin()) == p1);
	service.add("par", 2, 50);
	assert(service.size() == 2);
	service.del("par");
	assert(service.size() == 1);
	Product p3("para", 3, 1000);
	service.mod("mar", "para", 3, 1000);
	assert(*(service.getAll().begin()) == p3);
	///////customer test
	Customer c;
	Product o1("para", -1, 2);
	assert(c.customer_order(service, o1) == 0);
	Product test1 = *service.getAll().begin();
	assert(test1.getNo() == 998);
	o1.setNo(1000);
	assert(c.customer_order(service, o1) == 1);
	Product test2 = *service.getAll().begin();
	assert(test2.getNo() == 998);
	o1.setName("paul");
	assert(c.customer_order(service, o1) == 2);
	Product test3 = *service.getAll().begin();
	assert(test3.getNo() == 998);
	o1.setName("paul");
	assert(c.customer_return(service, o1) == 1);
	Product test4 = *service.getAll().begin();
	assert(test4.getNo() == 998);
	Product r1("para", -1, 2);
	assert(c.customer_return(service, r1) == 0);
	Product test5 = *service.getAll().begin();
	assert(test5.getNo() == 1000);
}

void tests()
{
	ProductTests();
	RepoTests();
	RepoFileTests();
	ServiceTests();
}