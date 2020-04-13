#pragma once
#include "repofile.h"

class Service 
{
	friend class Customer;
private:
	RepoFile<Product> repo;
public:
	Service();
	Service(const Service&);
	~Service();
	void load(char*);
	void save();
	void add(const char*, const int, const int);
	void del(const char*);
	void mod(const char*, const char*, const int, const int);
	Product find_by_name(const char*);
	set<Product>& getAll();
	int size();
};