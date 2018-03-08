#include <iostream>
#include <stdint.h>
#include "FindFunction.hpp"


void getValues(int* x, int* y)
{
	std::cout << "Enter two values: " << std::endl;
	std::cin >> *x;
	std::cin >> *y;
}

int main(void)
{
	//Console I/O
	std::cout << "Test" << std::endl;

	float favorite;

	std::cout << "Enter your favorite number: ";
	std::cin >> favorite;
	std::cout << "Your favorite number is: " << favorite << std::endl;

	//Arrays
	const size_t array_size = 5;
	int array1[array_size] = {2,10,6,8,10};
	int array2[] = {5,10,15,20,25};
	static_assert(array_size == sizeof(array2)/sizeof(int),"");

	std::cout << "The arrays are:" << std::endl;

	for (size_t x = 0; x < array_size; x++)
	{
		std::cout << array1[x] << '\t' << array2[x] << std::endl;
	}

	std::cout << "The index of 10 in the first array is: " << index_of(array1,array_size,10) << std::endl;
	std::cout << "The last index of 10 in the first array is: " << last_index_of(array1,array_size,10) << std::endl;


	//Dynamic Memory
	int* array3;
	size_t len;
	std::cout << "How long should the array be: ";
	std::cin >> len;
	array3 = new (std::nothrow) int[len];
	std::cout << "Enter the array values: " << std::endl;
	for (size_t x = 0; x < len; x++)
	{
		std::cin >> array3[x];
	}
	std::cout << "The array is: " << std::endl;
	for (size_t x = 0; x < len; x++)
	{
		std::cout << array3[x] << std::endl;
	}
	delete[] array3;

	//Pointers
	int val1;
	int val2;
	getValues(&val1,&val2);
	std::cout << "You entered: " << val1 << " " << val2 << std::endl;

	return 0;
}
