#pragma once
#include "service.h"

class UserInterface
{
private:
	Service<Product> service;
public:
	UserInterface();
	~UserInterface();
	void load();
	void save();
	void add();
	void del();
	void mod();
	void print();
	void no_command();
	void show();
};