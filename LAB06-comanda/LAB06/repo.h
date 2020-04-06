#pragma once
#include "product.h"
#include <set>

using namespace std;

template <class T>
class Repo
{
private:
	set<T> elements;
public:
	Repo() {}
	~Repo() {}
	void add(const T p) { elements.insert(p); }
	void del(const T p) { elements.erase(p); }
	void mod(const T p1, const T p2) { elements.erase(p1); elements.insert(p2); }
	set<T>& getAll() { return elements; }
	int size() { return elements.size(); }
	T find_by_title(const char* title)
	{
		for (auto it = elements.begin(); it != elements.end(); ++it)
		{
			T crt = *it;
			if (strcmp(crt.getName(), title) == 0)
				return crt;
		}
		return def;
	}
};
