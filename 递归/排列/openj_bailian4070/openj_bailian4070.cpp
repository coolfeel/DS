#include <iostream>
using namespace std;

int n, cur[20], vis[20] = {0};

void pl(int index) {
    if (index == n + 1) {
        for (int i = 1;i <= n ;i++)
            if (i != n)
                cout << cur[i] << 'a';
            else cout << cur[i];
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
        if (vis[i] == 0) {
            cur[index] = i;
            vis[i] = 1;
            pl(index + 1);
            vis[i] = 0;
        }
}


int main() {
    while (cin >> n && n) {
        pl(1);
    }
    return 0;
}
