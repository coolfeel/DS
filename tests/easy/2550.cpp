#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct g {
	int a, b;
}G[100];

bool cmp (struct g &x, struct g &y) {
	return x.a < y.a;
}

int main() {
	int t, n;
	char str[1000];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> G[i].a >> G[i].b;
		sort(G, G + n, cmp);
		int k = 0;
		while (n--) {
			memset(str, '\0', sizeof(str));
			str[0] = '>'; str[G[k].a + 1] = '>'; 
			str[1] = '+'; str[G[k].a] = '+';
			for (int i = 2; i < G[k].a; i++)
				str[i] = '-';
			for (int i = 0; i < G[k].b; i++)
				cout << str << endl;
			cout << endl;
			k++;
		}
	}
	return 0;
} 
