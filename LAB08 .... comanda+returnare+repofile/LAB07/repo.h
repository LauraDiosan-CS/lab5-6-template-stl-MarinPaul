#pragma once
#include "product.h"
#include <fstream>
#include <set>

using namespace std;

template <class T> class Repo
{
protected:
	set<T> elements;
public:
	Repo() {}

	Repo(const Repo& r) { elements = r.elements; }

	~Repo() {}

	bool operator==(const Repo& r) { return elements == r.elements; }

	void add(const T p) { elements.insert(p); }

	void del(const T p) { elements.erase(p); }

	void mod(const T p1, const T p2) { elements.erase(p1); elements.insert(p2); }

	set<T>& getAll() { return elements; }

	int size() { return elements.size(); }
};