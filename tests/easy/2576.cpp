#include <iostream>
using namespace std;

int main() {
	int t;
	long long n, sum;
	cin >> t;
	while (t--) {
		cin >> n;
		sum = n * (n + 1) / 2 % (20090524 * 3);
		sum = sum * (n + 2) / 3 % 20090524;
		cout << sum << endl; 
	}
	return 0;
} 
