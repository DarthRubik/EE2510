#include <iostream>
#include <sstream>
#include <string>

int GetIntFromUser(std::ostream& ostream,std::istream &stream);
bool isInteger(const std::string &str);
void GetIntArrayFromUser(std::ostream &ostream, std::istream &stream,
                         int **array, int *length);
