#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n, cnt = 0, ans[100], vis[100];

int isprime(int a) {
	int flag = 1;
	for (int i = 2; i <= sqrt(a); i++)
		if (a % i == 0) {
			flag = 0;
			break;	
		}
	return flag;
}

void dfs(int num) {
	if (num == n && isprime(ans[0] + ans[n - 1])) {  //判断首尾 
		for (int i = 0; i < n; i++) {
			if (i == n-1)
				cout << ans[i];
			else
				cout << ans[i] << ' ';
		}			
		cout << endl;
	} else {
		for (int i = 2; i <= n; i++)
			if (!vis[i] && isprime(i + ans[num - 1])) {
				ans[num] = i;
				vis[i] = 1;
				dfs(num + 1);
				vis[i] = 0;            //用完就重置，供下次用 
			}
	}
}

int main() {
	while (cin >> n) {
		cout << "Case " << ++cnt << ':' << endl;
		memset(vis, 0, sizeof(vis));
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		vis[0] = 1;
		dfs(1);
		cout << endl;
	}
	return 0;
} 
