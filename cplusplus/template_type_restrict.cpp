#include <iostream>
using namespace std;

//This program is written to restrict the type passed to a templated function.
//It will fail if they are different in static assert statement.

template<typename T>
int myfun(T val) {

	static_assert(std::is_same<T,int>() || 
		std::is_same<T, float>() ||
		std::is_same<T, double>() ||
		std::is_same<T, long>(),
		"Sorry, wrong type is used in template, fix it");

	std::cout<<" Hurray, type check passed"<<std::endl;
	return 0;
}

int main() {
	
	auto k =3;
	myfun<int>(3);    //pass
	myfun<long>(34);   //pass
	myfun<float>(4.5);  //pass
	myfun<double>(2.3);  //pass
	myfun<string>("Surbhi");   //Compile file failure

	return 0;

}