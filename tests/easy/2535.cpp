#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, vote[110];
	while (cin >> n && n) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			cin >> vote[i];
		sort(vote, vote + n);
		for (int i =0; i < n / 2 + 1; i++)
			sum += vote[i] / 2 + 1; 			
		cout << sum << endl;
	}
	return 0;
}
