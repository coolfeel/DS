#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t, n;
	char map[100][100];
	cin >> t;
	while (t--) {
		cin >> n;
		memset(map, ' ', sizeof(map));
		for (int i = 0; i < n; i++)
			map[i][i]=map[i][n - i - 1]='X';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j];
				if (j >= n - i - 1)  //坑，每行最后个X之后无空格 
					if (j >= i)
						break;
			}	
			cout << endl;
		}
		cout << endl;
	}	
	return 0;
} 
