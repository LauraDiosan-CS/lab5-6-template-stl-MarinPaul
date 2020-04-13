#pragma once
#include "service.h"
#include "customer.h"
#include <vector>

class UserInterface
{
private:
	Service service;
	void load();
	void save();
	void add();
	void del();
	void mod();
	void customer_order();
	void customer_return();
	void customer();
	void print();
	void no_command();
public:
	UserInterface();
	~UserInterface();
	void show();
};