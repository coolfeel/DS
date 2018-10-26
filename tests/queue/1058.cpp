#include <bits/stdc++.h>
 
using namespace std;

typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL> > pq;
set<LL> s;
LL num[6000];

int main() {
	int n, base[4] = {2, 3, 5, 7}, tmp = 1;
	pq.push(1);
	s.insert(1);
	for (int i = 1; i <= 5842; i++) {
		LL x = pq.top();
		num[i] = x;
		pq.pop();
		for (int j = 0; j < 4; j++) {
			LL c = x * base[j];
			if (!s.count(c)) {
				s.insert(c);
				pq.push(c);
			}
		}
	}
	while (cin >> n && n) {
		if (n % 10 == 1 && n % 100 != 11)
			cout << "The " << n << "st humble number is " << num[n] << "." << endl;
		else if (n % 10 == 2 && n % 100 != 12)
			cout << "The " << n << "nd humble number is " << num[n] << "." << endl;
		else if (n % 10 == 3 && n % 100 != 13)
			cout << "The " << n << "rd humble number is " << num[n] << "." << endl;
		else
			cout << "The " << n << "th humble number is " << num[n] << "." << endl; 
	}	
	return 0;
} 
