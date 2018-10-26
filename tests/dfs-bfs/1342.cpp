#include <iostream>
#include <cstring>
using namespace std;

int seq[50], ans[20], vis[50], n, cnt, k;

void dfs(int n, int cnt) {
	if (cnt == 7) {
		cout << ans[1];
		for (int i = 2; i <= 6; i++)
			cout << ' ' << ans[i];
		cout << endl;
	} else {
		for ( ; n <= k; n++) {
			if (!vis[n]) {
				ans[cnt] = seq[n];
				vis[n] = 1;
				dfs(n + 1, cnt + 1);
				vis[n] = 0;
			}
		}
	}	
}

int main() {
	cnt = 0;
	while (cin >> k && k) {
		memset(vis, 0, sizeof(vis));	
		for (int i = 1; i <= k; i++)
			cin >> seq[i];
		if (cnt++)
			cout << endl;
		dfs(1, 1);
	}	
	return 0;
} 
