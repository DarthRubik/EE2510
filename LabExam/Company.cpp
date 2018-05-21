//Author: Jacob Gamble

#include "Company.hpp"

Company::~Company()
{
}

bool Company::operator<(const Company& other) const
{
	return this->GetComparison() < other.GetComparison();
}

float Company::GetComparison() const
{
	float ret = this->GetTotalRevenue();
	ret -= Debt;
	ret /= NumberOfEmployees;
	return ret;
}

std::string Company::ToString() const
{
	std::string ret = "";
	ret += "Name: " + this->GetName() + "\n";
	ret += "Debt: " + std::to_string(this->GetDebt()) + "\n";
	ret += "NumberOfEmployees: " + std::to_string(this->GetNumberOfEmployees()) + "\n";
	ret += "Comparison: " + std::to_string(this->GetComparison()) + "\n";
	return ret;
}

float Company::GetDebt() const
{
	return this->Debt;
}
int Company::GetNumberOfEmployees() const
{
	return this->NumberOfEmployees;
}
std::string Company::GetName() const
{
	return this->Name;
}

void Company::SetDebt(float value)
{
	this->Debt = value;
}
void Company::SetNumberOfEmployees(float value)
{
	this->NumberOfEmployees = value;
}
void Company::SetName(std::string value)
{
	this->Name = value;
}
