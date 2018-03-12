#include "CalculatorFunctions.h"


int my_basic_math(int operation, int x, int y, float* ans)
{
	//Error if operation out of range
	if (operation < 1 || operation > 5)
	{
		return 1;
	}
	//Do not allow divide by zero
	if (y == 0 && operation == 4) return 2;

	//If the output pointer is null error
	if (ans == 0) return 3;
	switch (operation)
	{
		case 1: //addition
			*ans = x + y;
			break;
		case 2: //subtraction
			*ans = x - y;
			break;
		case 3: //multiplication
			*ans = x*y;
			break;
		case 4: //division
			*ans = (float)x/(float)y;
			break;
		case 5: //exponentiation
			{
				//Start with 1
				float ret = 1;

				//Positive power multiply
				//negative divide
				if (y > 0)
				{
					for (int z = 0; z < y; z++)
					{
						ret *= x;
					}
				}
				else{
					for (int z = 0; z < -y; z++)
					{
						ret /= (float)x;
					}
				}
				*ans = ret;
			}
			break;
	}
	return 0;
}
int my_average(int* array,int length,float* ans)
{
	//Error on null ans pointer
	if (ans == 0) return 3;

	//Error on null array
	if (array == 0) return 2;

	//Error on zero length array
	if (length == 0) return 1;

	//Start with zero
	float average = 0;

	//Sum up the numbers
	for (int x = 0; x < length; x++)
	{
		average += array[x];
	}

	//Divide by the length
	*ans = average/length;

	return 0;
}
int my_find_large_small(int* array,int length,int* max, int* min)
{
	//Error on zero length array
	if (length == 0)
		return 1;

	//Error on null array
	if (array == 0)
		return 2;

	//Error on min max pointers being indistinct
	if (max == min)
		return 3;

	//Error on outputs being null
	if (max == 0)
		return 4;
	if (min == 0)
		return 5;


	//Start with the first number in the array
	*max = array[0];
	*min = array[0];
	for (int x = 1; x < length; x++)
	{
		//Foreach member if the current member is smaller or larger
		//than the record, change the record
		if (*max < array[x])
		{
			*max = array[x];
		}
		if (*min > array[x])
		{
			*min = array[x];
		}
	}

	return 0;
}
int my_series_parallel(int* array,int length,int type,float* ans)
{
	//Error on zero length array
	if (length == 0)
		return 1;
	//Error on null array
	if (array == 0)
		return 2;
	//Error on null output pointer
	if (ans == 0)
		return 3;
	//Error on out of range argument
	if (type != 1 && type != 2)
		return 4;

	//Series
	if (type == 1)
	{
		//Because I am lazy use the average function and multiply by length
		int ret = my_average(array,length,ans);
		*ans *= length;
		return ret;
	}
	//Parallel
	else if (type == 2)
	{
		//Get the reciprical sum and invert
		float denon = 0;
		for (int x = 0; x < length; x++)
		{
			denon += (float)1/(float)array[x];
		}
		*ans = (float)1/denon;
	}

	return 0;
}
