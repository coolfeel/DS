#include <iostream>
#include <cstring>
#include <set>
using namespace std;

set <int> s;
int cur[20], vis[20] = {0}, num[5] = {-1}, res[1000][1000];

void pl(int index) {
    if (index == 5) {
        int sum = cur[1] * 1000 + cur[2] * 100 + cur[3] * 10 + cur[4];
        if (s.count(sum) == 0)
            s.insert(sum);
        return;
    }
    for (int i = 1; i <= 4; i++) {
        if (vis[i] == 0) {
            cur[index] = num[i];
            vis[i] = 1;
            pl(index + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    int flag = 0;
    while (cin >> num[1] >> num[2] >> num[3] >> num[4]) {
        if (!num[1] && !num[2] && !num[3] && !num[4])
            break;
        pl(1);
        if (flag)
            cout << endl;
        flag = 1;
        int a, head[10] = {0}, result[10][100] = {0};
        for (set<int> :: iterator it = s.begin(); it != s.end(); it++) {
            a = *it / 1000;
            head[a]++;
            result[a][head[a]] = *it;
        }
        for (int i = 1; i <= a; i++) {
            if (!head[i])
                continue;
            for (int j = 1; j <= head[i]; j++)
                if (j != head[i])
                    cout << result[i][j] << ' ';
                else
                    cout << result[i][j];
            cout << endl;
        }
        memset(head, 0 ,sizeof(head));
        s.clear();
    }
    return 0;
}


