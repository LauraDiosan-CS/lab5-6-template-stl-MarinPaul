#pragma once
#include "product.h"
#include <fstream>
#include <set>

/////////////////////REPOFILE ESTE MAI JOS

using namespace std;

template <class T>
class Repo
{
protected:
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


template <class T>
class RepoFile :
	public Repo<Product>
{
private:
	char* file;
public:
	RepoFile();
	~RepoFile();
	RepoFile(char*);
	void load(char*);
	void save();
	bool is_file() { return !(file == NULL); }
};

template <class T> RepoFile<T>::RepoFile() :Repo<T>()
{
	file = NULL;
}

template <class T> RepoFile<T>::~RepoFile()
{
	file = NULL;
}

template <class T> RepoFile<T>::RepoFile(char* name)
{
	file = name;
	ifstream f(file);
	while (!f.eof())
	{
		T ent;
		f >> ent;
		if (ent != def)
			elements.insert(ent);
	}
	f.close();
}

template <class T> void RepoFile<T>::load(char* name)
{
	file = name;
	elements.clear();
	ifstream f(file);
	while (!f.eof())
	{
		T ent;
		f >> ent;
		if (ent != def)
			elements.insert(ent);
	}
	f.close();
}

template <class T> void RepoFile<T>::save()
{
	ofstream f(file);
	f.clear();
	for (auto it = elements.begin(); it != elements.end(); ++it)
	{
		T crt = *it;
		f << crt;
	}
	f.close();
}