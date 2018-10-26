#include <iostream>
using namespace std;

int main() {
	int c, n, b;
	cin >> c;
	while (c--) {
		cin >> n;
		b = 0;
		while (n > 0) {
			if (n % 2) {
				b++;
				n /= 2;	
			} else
				n /= 2;	
		}
		cout << b << endl;
	}	
	return 0;
} 
