//Author: Jacob Gamble

#include "FinancialCompany.hpp"

FinancialCompany::FinancialCompany(int AssetsHeld, 
			int NumberOfAccounts,
			float AverageROR,
			float Debt,
			int NumberOfEmployees,
			std::string Name)
{
	this->SetAssetsHeld(AssetsHeld);
	this->SetNumberOfAccounts(NumberOfAccounts);
	this->SetAverageROR(AverageROR);
	this->SetDebt(Debt);
	this->SetNumberOfEmployees(NumberOfEmployees);
	this->SetName(Name);
}

std::string FinancialCompany::ToString() const
{
	std::string ret = Company::ToString();
	ret += "Assets Held: " + std::to_string(this->GetAssetsHeld()) + "\n";
	ret += "NumberOfAccounts: " + std::to_string(this->GetNumberOfAccounts()) + "\n";
	ret += "AverageROR: " + std::to_string(this->GetAverageROR()) + "\n";
	return ret;
}

float FinancialCompany::GetTotalRevenue() const
{
	return AssetsHeld*AverageROR/NumberOfAccounts;
}


int FinancialCompany::GetAssetsHeld() const
{
	return this->AssetsHeld;
}
int FinancialCompany::GetNumberOfAccounts() const
{
	return this->NumberOfAccounts;
}
float FinancialCompany::GetAverageROR() const
{
	return this->AverageROR;
}

void FinancialCompany::SetAssetsHeld(int value)
{
	this->AssetsHeld = value;
}
void FinancialCompany::SetNumberOfAccounts(int value)
{
	this->NumberOfAccounts = value;
}
void FinancialCompany::SetAverageROR(float value)
{
	this->AverageROR = value;
}
