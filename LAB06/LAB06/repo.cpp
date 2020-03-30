#pragma once
#include "repo.h"

Repo::Repo() {}

Repo::~Repo() {}

void Repo::add(const Product p)
{
	products.insert(p);
}

set<Product>& Repo::getAll()
{
	return products;
}

int Repo::size()
{
	return products.size();
}