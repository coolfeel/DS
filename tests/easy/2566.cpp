#include <iostream>
using namespace std;

int main() {
	int n, m, cnt, t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cnt = 0;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				for (int k = 0; k <= n; k++)
					if ((i + 2 * j + 5 * k == m) && (i + j + k == n))
						cnt++;
		cout << cnt << endl;
	}
	return 0;
} 
