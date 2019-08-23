#include <iostream>

using namespace std;

constexpr auto calcfactorialcompiletime(int k) {
	int ans = 1;
	for( int i=1; i <=k; ++i) {
		ans = ans*i;

	}
	return ans;
}

int main() {

	int k;
	cin>>k;
	const auto ans = calcfactorialcompiletime(k);
	cout<<ans;
	//ans = 9;
	return 0;
	
}