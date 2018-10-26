#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string str1, str2;
	char str[200];
	int n, i, j, k;
	cin >> n;
	while (n--) {
		cin >> str1;
		getchar();
		cin >> str2;
		memset(str, '\0', sizeof(str));
		for (i = 0; i < str1.length() / 2; i++)
			str[i] = str1[i];
		for (j = 0; j < str2.length(); i++, j++)
			str[i] = str2[j];
		for (k = str1.length() / 2; k < str1.length(); i++, k++)
			str[i] = str1[k];
		cout << str << endl;
	}
	return 0;
}
