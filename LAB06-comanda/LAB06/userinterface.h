#pragma once
#include "service.h"

class UserInterface
{
private:
	Service<Product> service;
public:
	UserInterface();
	~UserInterface();
	void add();
	void del();
	void mod();
	void command();
	void print();
	void show();
};