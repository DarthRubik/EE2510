//Author: Jacob Gamble

#ifndef FINANCIAL_COMPANY_HPP
#define FINANCIAL_COMPANY_HPP
#include "Company.hpp"

class FinancialCompany : public Company
{
	int AssetsHeld;
	int NumberOfAccounts;
	float AverageROR;
protected:
	float GetTotalRevenue() const;
public:
	FinancialCompany(int AssetsHeld, 
			int NumberOfAccounts,
			float AverageROR,
			float Debt,
			int NumberOfEmployees,
			std::string Name);

	std::string ToString() const;

	int GetAssetsHeld() const;
	int GetNumberOfAccounts() const;
	float GetAverageROR() const;

	void SetAssetsHeld(int value);
	void SetNumberOfAccounts(int value);
	void SetAverageROR(float value);
};


#endif
