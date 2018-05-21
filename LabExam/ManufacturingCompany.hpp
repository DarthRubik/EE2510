//Author: Jacob Gamble

#ifndef MANUFACTURING_COMPANY_HPP
#define MANUFACTURING_COMPANY_HPP
#include "Company.hpp"

class ManufacturingCompany : public Company
{
	int ComponentsProduced;
	float AverageIncomePerComponent;
protected:
	float GetTotalRevenue() const;
public:
	ManufacturingCompany(int ComponentsProduced, 
			float AverageIncomePerComponent,
			float Debt,
			int NumberOfEmployees,
			std::string Name);
	std::string ToString() const;

	int GetComponentsProduced() const;
	float GetAverageIncomePerComponent() const;

	void SetComponentsProduced(int value);
	void SetAverageIncomePerComponent(float value);
};


#endif
