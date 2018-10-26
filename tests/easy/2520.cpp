#include <iostream>
using namespace std;

int f[100000];

int main() {
	int n, m, sum;
	cin >> n;
	f[1] = 1;
	for (int i = 2; i <= 100000; i++)
		f[i] = f[i-1] + 2;
	while (n--) {
		cin >> m;
		sum = 0;
		for (int i = 1; i <= m; i++)
			sum += f[i];
		cout << sum % 10000 << endl;
	}
	return 0;
} 
