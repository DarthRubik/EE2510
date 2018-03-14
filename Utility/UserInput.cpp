#include "UserInput.hpp"
#include <cstdlib>


bool isInteger(const std::string& str)
{
	if ("" == str) return false;
	char* lastDigit;
	std::strtol(str.c_str(), &lastDigit, 10);
	return *lastDigit == 0;
}
int GetIntFromUser(std::ostream& ostream, std::istream& stream)
{
	std::string str;
	std::getline(stream,str);
	while (!isInteger(str))
	{
		ostream << "Try again" << std::endl;
		std::getline(stream,str);
	}
	return std::strtol(str.c_str(),0,10);
}
void GetIntArrayFromUser(std::ostream &ostream, std::istream &stream,
                         int **array, int *length)
{
	ostream << "Enter array length:" << std::endl;
	*length = GetIntFromUser(ostream,stream);
	*array = new int[*length];

	ostream << std::string("Enter array:") << std::endl;

	for (int x = 0; x < *length; x++)
	{
		(*array)[x] = GetIntFromUser(ostream,stream);
	}
}
