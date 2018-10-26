#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t, n, mark;
	char str[1001];
	cin >> t;
	while (t--) {
		memset(str, '0', sizeof(str));
		cin >> str;
		cin >> n;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == '.') {
				mark = i;
				break;
			}		
		}
		str[strlen(str)] = '0';
		cout << str[mark + n] << endl;	
	}
	return 0;
}
