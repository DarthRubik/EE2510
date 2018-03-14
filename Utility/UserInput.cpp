#include "UserInput.hpp"
#include <cstdlib>


//If the string is an integer then return true (else false)
bool isInteger(const std::string& str)
{
	//Blank strings are not integers
	if ("" == str) return false;

	char* lastDigit;
	//strtol will set "lastDigit" to the char it stopped parsing at
	std::strtol(str.c_str(), &lastDigit, 10);


	//If the last parsed char it parsed the whole string
	return *lastDigit == 0;
}
int GetIntFromUser(std::ostream& ostream, std::istream& stream)
{
	std::string str;
	std::getline(stream,str);
	//Yell at the user until they enter the correct data
	while (!isInteger(str))
	{
		ostream << "Try again" << std::endl;
		std::getline(stream,str);
	}
	//Convert the string to an int
	return std::strtol(str.c_str(),0,10);
}
void GetIntArrayFromUser(std::ostream &ostream, std::istream &stream,
                         int **array, int *length)
{
	ostream << "Enter array length:" << std::endl;

	//Allocate array the length asked for
	*length = GetIntFromUser(ostream,stream);
	*array = new int[*length];

	//Populate the array
	ostream << std::string("Enter array:") << std::endl;

	for (int x = 0; x < *length; x++)
	{
		(*array)[x] = GetIntFromUser(ostream,stream);
	}
}
