#include "BasicEmployee.hpp"
#include <iostream>
#include <tuple>


void PrintPay(BasicEmployee& emp)
{
	std::cout << emp.getFullName() << " is payed " << emp.getPaycheck() << std::endl;
}
int main(void)
{
	BasicEmployee emp1("Arthur","Dent");
	BasicEmployee emp2("Zaphod", "Beeblebrox");
	emp1.setPay(15);
	emp2.setPay(132);


	emp1.workHours(50);
	emp2.workHours(100);


	std::cout << "You have employees: " 
		  << emp1.getFullName() << " and " 
		  << emp2.getFullName() << std::endl;
	PrintPay(emp1);
	PrintPay(emp2);
}
