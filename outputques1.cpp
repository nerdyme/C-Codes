 
#include <iostream>
using namespace std;

 int f( const char* a, int n=0){ 

 	return *a ? f( a+1, n <<1 + n <<3) : n;  

         } 



int main() {

	cout << f("Su",1);
	return 0;

}