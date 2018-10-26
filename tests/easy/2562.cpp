#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a, char &b) {
	char c;
	c = a;
	a = b;
	b = c;
}

int main() {
	int c;
	char str[100];
	cin >> c;
	while (c--) {
		cin >> str;
		for (int i = 0; i < strlen(str); i = i + 2)
			swap(str[i], str[i + 1]);
		cout << str << endl;
	}
	return 0;
}
