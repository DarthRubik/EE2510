#include "cstdint"
#include "Date.hpp"
#include <iostream>

using namespace std;


int main(int ac, char** av)
{
	// Test Date class.
	cout << "***Test Date Class***" << endl;
	Date d1(2016,1,31);
	Date d2(0,0,31);
	Date d3(2017,9,1);
	Date d4(0,5,12);
	Date d5(0,5,11);
	Date d6(2000,3,1);
	Date d7(0,0,1);
	Date d8(1000,1,30);
	cout << "d1: " << d1.to_string() << endl;
	cout << "d2: " << d2.to_string() << endl;
	cout << "d3: " << d3.to_string() << endl;
	cout << "d4: " << d4.to_string() << endl;
	cout << "d5: " << d5.to_string() << endl;
	cout << "d6: " << d6.to_string() << endl;
	cout << "d7: " << d7.to_string() << endl;
	cout << "d8: " << d8.to_string() << endl;

	Date dTest = d1 + d2;
	cout << "d1 + d2: " << dTest.to_string() << endl;
	dTest = d3 - d1;
	cout << "d3 - d1: " << dTest.to_string() << endl;
	dTest = d3 + d4;
	cout << "d3 + d4: " << dTest.to_string() << endl;
	dTest = d6 - d7;
	cout << "d6 - d7: " << dTest.to_string() << endl;
	dTest = d8 + d8;
	cout << "d8 + d8: " << dTest.to_string() << endl;
	cout << "d1 > d2: ";
	if(d1 > d2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "d1 < d2: ";
	if(d1 < d2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "d4 == d5: ";
	if(d4 == d5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "d4 != d5: ";
	if(d4 != d5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
}

