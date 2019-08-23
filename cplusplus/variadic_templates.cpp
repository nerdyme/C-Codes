#include <iostream>

using namespace std;


//Use of funtion overloading and variadic arguments and recursion base case
template<typename T>
T adder(T val) {
	return val;
}

template<typename T, typename...ARGS>
T adder(T val, ARGS...args) {
	return val + adder(args...);
}


int main(int argc, char const *argv[])
{
	//Variadic templates
	cout<< adder(string("S"), string("U"), string("R"))<<std::endl;
	cout<< adder('S','U','R')<<std::endl;
	cout<< adder(2,3,4)<<std::endl;

	return 0;
}