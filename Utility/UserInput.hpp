#ifndef UTILITY_USERINPUT_HPP
#define UTILITY_USERINPUT_HPP
#include <iostream>
#include <sstream>
#include <string>

//Gets a single integer from the user
int GetIntFromUser(std::ostream& ostream,std::istream &stream);

//Returns whether or not the string is an integer
bool isInteger(const std::string &str);

//Get an array from the user
void GetIntArrayFromUser(std::ostream &ostream, std::istream &stream,
                         int **array, int *length);
#endif
