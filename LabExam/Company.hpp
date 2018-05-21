//Author: Jacob Gamble

#ifndef COMPANY_HPP
#define COMPANY_HPP
#include <string>

class Company
{
	float Debt;
	int NumberOfEmployees;
	std::string Name;

protected:
	virtual float GetTotalRevenue() const = 0;
public:
	virtual std::string ToString() const;

	float GetComparison() const; 

	bool operator<(const Company& other) const;
	virtual ~Company();

	float GetDebt() const;
	int GetNumberOfEmployees() const;
	std::string GetName() const;
	void SetDebt(float value);
	void SetNumberOfEmployees(float value);
	void SetName(std::string value);
};

#endif
