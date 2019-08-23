#include <iostream>
using namespace std;

//This program is written to check the type deduced by auto during the compilation time.
//It will fail if they are different in static assert statement
int main() {
	
	auto k =3;
	static_assert(is_same<decltype(k),int>(), " Oops, different types");

}