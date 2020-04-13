#pragma once
#include "service.h"

class Customer
{
public:
	int customer_order_verify(Service& s, Product& p)
	{
		Product oldP = s.find_by_name(p.getName());
		if (oldP != def)
		{
			if (oldP.getNo() >= p.getNo())
				return 0; // sarcina indeplinita
			return 1; // numar de bucati prea mare
		}
		return 2; // produs indisponibil
	}
	int customer_order(Service& s, Product& p)
	{
		Product oldP = s.find_by_name(p.getName());
		if (oldP != def)
		{
			if (oldP.getNo() >= p.getNo())
			{
				p.setPrice(oldP.getPrice());
				p.setNo(oldP.getNo() - p.getNo());
				s.repo.mod(oldP, p);
				return 0; // sarcina indeplinita
			}
			return 1; // numar de bucati prea mare
		}
		return 2; // produs indisponibil
	}
	int customer_return(Service& s, Product& p)
	{
		Product oldP = s.find_by_name(p.getName());
		if (oldP != def)
		{
			p.setPrice(oldP.getPrice());
			p.setNo(oldP.getNo() + p.getNo());
			s.repo.mod(oldP, p);
			return 0; // sarcina indeplinita
		}
		return 1; // produs indisponibil
	}
};