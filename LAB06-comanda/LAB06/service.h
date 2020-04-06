#pragma once
#include "repo.h"

template <class T>
class Service
{
private:
	Repo<T> repo;
public:
	Service() {}
	~Service() {}
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
	int command(const char* name, const int no)
	{
		if (repo.find_by_title(name) != def)
		{
			T old_ent = repo.find_by_title(name);
			if (old_ent.getNo() >= no)
			{
				T new_ent(old_ent.getName(), old_ent.getPrice(), old_ent.getNo() - no);
				repo.mod(old_ent, new_ent);
				return 0;
			}
			return 1;
		}
		return 2;
	}
};