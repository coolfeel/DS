#include <iostream>
using namespace std;

int add(int a) {
	int sum = 0;
	for (int i = 1; i<=a; i++)
		sum += i; 
	return sum;
}

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << add(n) * add(m) <<endl;
	}
	return 0;
}
