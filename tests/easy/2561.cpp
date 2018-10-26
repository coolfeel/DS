#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int c, n, num[20];
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		sort(num, num + n);
		cout << num[1] << endl;
	} 
	return 0;
}
