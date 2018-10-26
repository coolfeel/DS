#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int main() {
	int t, flag = 1;
	char c;
	string str, buf;
	cin >> t;
	while (t--) {
		if (flag)
			getchar();
		flag = 0;
		getline(cin, str);
		stringstream ss(str);
		while (ss >> buf) {
			c = toupper(buf[0]);
			cout << c;
		}
		cout << endl;
	}
	return 0;
} 
