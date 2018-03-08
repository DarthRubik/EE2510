/*
 * CalculatorFunctions.h
 *
 * Functions that need to be implemented as a part of EE2510 Lab 1 assignment.
 *
 *  Created on: Feb 22, 2017
 *      Author: Joshua D. Carl, PhD
 */

#ifndef CALCULATORFUNCTIONS_H_
#define CALCULATORFUNCTIONS_H_


// Name: 		my_basic_math
// Purpose: 	Performs basic math operations.
// Return: 		0 if successful
//		   		not-0 if error
// Parameters:	int - input - operation to perform:
//							  1 - addition
//							  2 - subtraction
//							  3 - multiplication
//							  4 - division
//							  5 - exponent
//				int - input - first operand
//				int - input - second operand
//				float* - output - pointer to memory where
//								  result can be stored
int my_basic_math(int, int, int, float*);


// Name: 		my_average
// Purpose: 	Averages the values in an array.
// Return: 		0 if successful
//		   		not-0 if error
// Parameters:	int[] - input - array of data
//				int - input - length of array
//				float* - output - pointer to memory where
//								  result can be stored
int my_average(int[], int, float*);


// Name: 		my_find_large_small
// Purpose: 	Finds the largest and smallest values in an array.
// Return: 		0 if successful
//		   		not-0 if error
// Parameters:	int[] - input - array of data
//				int - input - length of array
//				int* - output - pointer to memory where largest
//								value in array can be stored
//				int* - output - pointer to memory where smallest
//								value in array can be stored
int my_find_large_small(int[], int, int*, int*);


// Name: 		my_series_parallel
// Purpose: 	Finds the equivalent resistance of a series or parallel
//				sequence of resistors.
// Return: 		0 if successful
//		   		not-0 if error
// Parameters:  int[] - input - array of resistor values
//				int - input - length of array
//				int - input - resistor configuration
//							  1 = series
//							  2 = parallel
//				float* - output - pointer to memory where equivalent resistance
//								  value can be stored
int my_series_parallel(int[], int, int, float*);



#endif /* CALCULATORFUNCTIONS_H_ */
