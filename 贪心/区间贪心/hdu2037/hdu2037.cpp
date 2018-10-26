#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int st;
    int et;
}show[200];

int n, cnt, curt;

bool cmp (node a, node b) {
    return a.et < b.et;
}


int main() {
    while (cin >> n && n) {
        cnt = 0;
        curt = 0;
        for (int i = 0; i < n; i++)
            cin >> show[i].st >> show[i].et;
        sort(show, show + n, cmp);
        for (int i = 0; i < n; i++) {
            if (show[i].st >= curt) {
                curt = show[i].et;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
