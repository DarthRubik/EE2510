#include "CalculatorFunctions.h"


int my_basic_math(int operation, int x, int y, float* ans)
{
	if (operation < 1 || operation > 5)
	{
		return 1;
	}
	if (y == 0 && operation == 4) return 2;
	switch (operation)
	{
		case 1:
			*ans = x + y;
			break;
		case 2:
			*ans = x - y;
			break;
		case 3:
			*ans = x*y;
			break;
		case 4:
			*ans = (float)x/(float)y;
			break;
		case 5:
			{
				float ret = 1;
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
	if (array == 0) return 2;
	if (length == 0) return 1;

	float average = 0;

	for (int x = 0; x < length; x++)
	{
		average += array[x];
	}
	*ans = average/length;

	return 0;
}
