#include <iostream>
#include "CalculatorFunctions.h"
#include "UserInput.hpp"


int main()
{
	while (1)
	{
		//Ask the user what they want
		std::cout << "1) Basic Math\n"
			  << "2) Average\n"
			  << "3) Max and Min\n"
			  << "4) Resistor Operations\n"
			  << "Enter your choice (-1) to quit:" << std::endl;
		int choice = GetIntFromUser(std::cout,std::cin);
		//If this is null at the end we do not delete it 
		int* array = 0;
		int array_length;

		//Places to hold the answers
		float answer;
		int max,min;

		//If the error is still zero at the end then no error occured
		int error = 0;

		switch (choice)
		{
			case 1:
				{
					//Ask the user what they want
					std::cout << "1) Addition\n"
						  << "2) Subtraction\n"
						  << "3) Multiplication\n"
						  << "4) Division\n"
						  << "5) Exponentiation\n" 
						  << "Enter your choice: " << std::endl;

					int op = GetIntFromUser(std::cout,std::cin);

					//Get the operands
					std::cout << "Enter the operands: " << std::endl;
					int op1 = GetIntFromUser(std::cout,std::cin);
					int op2 = GetIntFromUser(std::cout,std::cin);
					error = my_basic_math(op,op1,op2,&answer);
				}
				break;
			case 2:
				GetIntArrayFromUser(std::cout,std::cin,&array,&array_length);
				error = my_average(array,array_length,&answer);
				break;
			case 3:
				GetIntArrayFromUser(std::cout,std::cin,&array,&array_length);
				error = my_find_large_small(array,array_length,&max,&min);
				break;
			case 4:
				{
					GetIntArrayFromUser(std::cout,std::cin,&array,&array_length);
					std::cout << "1) Series\n"
						<< "2) Parallel\n"
						<< "Enter your choice: " << std::endl;
					int choice = GetIntFromUser(std::cout,std::cin);
					error = my_series_parallel(array,array_length,choice,&answer);
				}
				break;
			default:
				return 0;
		}
		//If we got an array delete it
		if (array != 0) delete[] array;

		//If there is no error print the answers
		if (!error)
		{
			//For a max and min we have two answers to display
			if (choice == 3)
			{
				std::cout << "Max: " << max << " Min: " << min << std::endl;
			}
			else
			{
				std::cout << "The answer is: " << answer << std::endl;
			}
		}
		//An error occured
		else
		{
			std::cout << "An error occured, please try again...." << std::endl;
		}
	}
}
