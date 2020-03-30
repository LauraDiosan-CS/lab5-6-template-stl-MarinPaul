#pragma once
#include "product.h"
#include <set>

using namespace std;

class Repo
{
private:
	set<Product> products;
public:
	Repo();
	~Repo();
	void add(const Product);
	set<Product>& getAll();
	int size();
};