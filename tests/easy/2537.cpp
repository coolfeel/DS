#include <iostream>

using namespace std;

int main() {
	int n;
	char str[20];
	while (cin >> n && n) {
		cin >> str;
		int r = 0, y = 0;
		for (int i = 0; i < n - 1; i++) {
			if (str[i] == 'R')
				r++;
			if (str[i] == 'Y')
				y++;
		}
		if (str[n - 1] == 'B') {
			if (r == 7)
				cout << "Red" << endl;
			else
				cout << "Yellow" << endl;
		}
		if (str[n - 1] == 'L') {
			if (y == 7)
				cout << "Yellow" << endl;
			else
				cout << "Red" << endl;
		}
	}
	return 0;
} 
