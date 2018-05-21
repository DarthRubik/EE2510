//Author: Jacob Gamble

#include "Company.hpp"
#include "ManufacturingCompany.hpp"
#include "FinancialCompany.hpp"
#include <iostream>
#include <memory>
#include <vector>

int main()
{
	std::vector<std::unique_ptr<Company>> companies;
	companies.push_back(
		std::make_unique<ManufacturingCompany>(100000,.10,0,23,"Widget Maker")
	);
	companies.push_back(
		std::make_unique<ManufacturingCompany>(100,20,200,2,"Gamble Industries")
	);
	companies.push_back(
		std::make_unique<FinancialCompany>(100,3,.12,0,10,"Smart Accounting")
	);
	companies.push_back(
		std::make_unique<FinancialCompany>(1,100,.01,10000,1,"TRU$T US")
	);

	Company* best = companies[0].get();
	for (auto& comp: companies)
	{
		std::cout << comp->ToString() << std::endl;
		if (*best < *comp)
		{
			best = comp.get();
		}
	}

	std::cout << "The best option is:" << std::endl;
	std::cout << best->GetName() << std::endl;
}
