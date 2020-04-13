#pragma once
#include "repo.h"

template <class T> class RepoFile : public Repo<T>
{
private:
	char* file;
public:
	RepoFile() { file = NULL; }
	RepoFile(const RepoFile<T>& r):Repo<T>(r) { file = r.file; }
	~RepoFile() { file = NULL; }
	RepoFile(const char* name)
	{
		file = new char[strlen(name) + 1];
		strcpy_s(file, strlen(name) + 1, name);
		ifstream f(file);
		while (!f.eof())
		{
			T ent;
			f >> ent;
			if (ent != def)
				this->elements.insert(ent);
		}
		f.close();
	}
	void load(const char* name)
	{
		file = new char[strlen(name) + 1];
		strcpy_s(file, strlen(name) + 1, name);
		this->elements.clear();
		ifstream f(file);
		while (!f.eof())
		{
			T ent;
			f >> ent;
			if (ent != def)
				this->elements.insert(ent);
		}
		f.close();
	}
	void save()
	{
		ofstream f(file);
		f.clear();
		for (auto it = this->elements.begin(); it != this->elements.end(); ++it)
		{
			T crt = *it;
			f << crt;
		}
		f.close();
	}
	bool is_file() { return !(file == NULL); }
};