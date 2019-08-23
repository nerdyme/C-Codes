#include <iostream>

int main() {


	int g = 0x12345678;
	char c = (*(char*)(&g));

	std::cout<< c << std::endl;
	if (c == 0x78)
		std::cout << " little endian";

	return 0;



}