#include <iostream>

int pow(int x, int n) {

	if(n==0) return 1;
	if(n==1) return x;
	if(n%2==0) {
		int t= pow(x,n/2);
		return t*t;
	} else {
		return x*pow(x, n-1);
	}
}


int main() {

	std::cout<<pow(5,7) << std::endl;
	return 0;

}