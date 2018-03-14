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
std::string BasicEmployee::getFirstName()
{
	return FirstName;
}
std::string BasicEmployee::getLastName()
{
	return LastName;
}
