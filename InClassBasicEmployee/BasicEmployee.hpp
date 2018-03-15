
#ifndef BASIC_EMPLOYEE_HPP
#define BASIC_EMPLOYEE_HPP
#include <string>

class BasicEmployee
{
	public:
		BasicEmployee(std::string FirstName,std::string LastName);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getFullName() const;

		void workHours(int hours);
		void setPay(int pay);
		int getPaycheck();

		virtual ~BasicEmployee();
	private:
		std::string FirstName;
		std::string LastName;
		int hoursWorked;
		int hourlyPay;
};


#endif
