#include "service.h"


Service::Service() {}

Service::Service(const Service& s) { repo = s.repo; }

Service::~Service() {}

void Service::load(char* fileName)
{
	repo.load(fileName);
}

void Service::save()
{
	if (repo.is_file())
		repo.save();
}

void Service::add(const char* name, const int price, const int no)
{
	Product p(name, price, no);
	repo.add(p);
}

void Service::del(const char* name)
{
	Product p(find_by_name(name));
	if (p != def)
		repo.del(p);
}

void Service::mod(const char* name, const char* newName, const int newPrice, const int newNo)
{
	Product oldP(find_by_name(name));
	if (oldP != def)
	{
		Product newP(newName, newPrice, newNo);
		if (strcmp(newP.getName(), "-1") == 0)
			newP.setName(oldP.getName());
		if (newP.getPrice() == -1)
			newP.setPrice(oldP.getPrice());
		if (newP.getNo() == -1)
			newP.setNo(oldP.getNo());
		repo.mod(oldP, newP);
	}
}

Product Service::find_by_name(const char* name)
{
	for (auto it = getAll().begin(); it != getAll().end(); ++it)
	{
		Product crt = *it;
		if (strcmp(crt.getName(), name) == 0)
			return crt;
	}
	return def;
}

set<Product>& Service::getAll() { return repo.getAll(); }

int Service::size() { return repo.size(); }