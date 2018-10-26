#include <iostream>

using namespace std;

int main() {
	long t, root[1100];
	for (int i = 1; i < 1005; i++)
		root[i] = i * i * i;
	cin >> t;
	while (t--) {
		int x, sum = 0;
		cin >> x;
		for (int i = 1; i < 1005; i++) {
			sum += root[i];
			if (x <= sum) {
				cout << i << endl;
				break;
			}
		}			
	} 
	return 0;
} 
