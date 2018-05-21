//Author: Jacob Gamble

#include "ManufacturingCompany.hpp"



ManufacturingCompany::ManufacturingCompany(int ComponentsProduced, 
			float AverageIncomePerComponent,
			float Debt,
			int NumberOfEmployees,
			std::string Name)
{
	this->SetComponentsProduced(ComponentsProduced);
	this->SetAverageIncomePerComponent(AverageIncomePerComponent);
	this->SetDebt(Debt);
	this->SetNumberOfEmployees(NumberOfEmployees);
	this->SetName(Name);
}

std::string ManufacturingCompany::ToString() const
{
	std::string ret = Company::ToString();
	ret += "ComponentsProduced: " + std::to_string(this->GetComponentsProduced()) + "\n";
	ret += "AverageIncomePerComponent: " + std::to_string(this->GetAverageIncomePerComponent()) + "\n";
	return ret;
}


float ManufacturingCompany::GetTotalRevenue() const
{
	return this->GetComponentsProduced() * this->GetAverageIncomePerComponent();
}

int ManufacturingCompany::GetComponentsProduced() const
{
	return this->ComponentsProduced;
}
float ManufacturingCompany::GetAverageIncomePerComponent() const
{
	return this->AverageIncomePerComponent;
}

void ManufacturingCompany::SetComponentsProduced(int value)
{
	this->ComponentsProduced = value;
}
void ManufacturingCompany::SetAverageIncomePerComponent(float value)
{
	this->AverageIncomePerComponent = value;
}
