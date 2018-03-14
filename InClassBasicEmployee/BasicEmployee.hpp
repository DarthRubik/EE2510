
#ifndef BASIC_EMPLOYEE_HPP
#define BASIC_EMPLOYEE_HPP
#include <string>

class BasicEmployee
{
	public:
		BasicEmployee(std::string FirstName,std::string LastName);
		std::string getFirstName();
		std::string getLastName();
		virtual ~BasicEmployee();
	private:
		std::string FirstName;
		std::string LastName;
		int hoursWorked;
		int hourlyPay;
};


#endif
