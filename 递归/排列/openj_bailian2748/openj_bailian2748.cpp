#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

char str[20], cur[20];
int len, vis[20] = {0};
set<string> s;


void pl(int index) {
    if (index == len)
        s.insert(cur);
    for (int i = 0; i < len; i++)
        if (vis[i] == 0) {
            cur[index] = str[i];
            vis[i] = 1;
            pl(index + 1);
            vis[i] = 0;
        }
}


int main() {
    cin >> str;
    len = strlen(str);
    sort(str, str + len);
    pl(0);
    for (set<string> :: iterator it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    return 0;
}
