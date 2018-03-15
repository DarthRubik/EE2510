#include "BasicEmployee.hpp"
#include <iostream>


BasicEmployee::BasicEmployee(std::string FirstName, std::string LastName) : FirstName(FirstName), LastName(LastName), hoursWorked(0), hourlyPay(0) 
{
	std::cout << "***BasicEmployee constructor***" << std::endl;
}
BasicEmployee::~BasicEmployee()
{
	std::cout << "***BasicEmployee destructor***" << std::endl;
}
std::string BasicEmployee::getFirstName() const
{
	return FirstName;
}
std::string BasicEmployee::getLastName() const
{
	return LastName;
}
std::string BasicEmployee::getFullName() const
{
	return FirstName + ' ' + LastName;
}
void BasicEmployee::setPay(int pay)
{
	this->hourlyPay = pay;
}
void BasicEmployee::workHours(int hours)
{
	this->hoursWorked += hours;
}
int BasicEmployee::getPaycheck()
{
	int ret = this->hoursWorked * this->hourlyPay;

	this->hoursWorked = 0;

	return ret;

}
