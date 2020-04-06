#pragma once
#include "repo.h"

template <class T> class Service
{
private:
	RepoFile<T> repo;
public:
	Service() {}
	~Service() {}
	void load(char* fileName)
	{
		repo.load(fileName);
	}
	void save()
	{
		if (repo.is_file())
			repo.save();
	}
	void add(const char* name, const int price, const int no)
	{
		T ent(name, price, no);
		repo.add(ent);
	}
	void del(const char* name)
	{
		T ent(repo.find_by_title(name));
		if (ent != def)
			repo.del(ent);
	}
	void mod(const char* name, const char* newName, const int newPrice, const int newNo)
	{
		T ent(repo.find_by_title(name));
		if (ent != def)
		{
			T newEnt(newName, newPrice, newNo);
			if (strcmp(newEnt.getName(), "-1") == 0)
				newEnt.setName(ent.getName());
			if (newEnt.getPrice() == -1)
				newEnt.setPrice(ent.getPrice());
			if (newEnt.getNo() == -1)
				newEnt.setNo(ent.getNo());
			repo.mod(ent, newEnt);
		}
	}

	set<T>& getAll() { return repo.getAll(); }

	int size() { return repo.size(); }
};