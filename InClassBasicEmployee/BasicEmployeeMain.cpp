#include "BasicEmployee.hpp"
#include <iostream>


int main(void)
{
	BasicEmployee bob("Bob","Smith");
	std::cout << "Hello " << bob.getFirstName() << " " << bob.getLastName() << std::endl;
	
}
