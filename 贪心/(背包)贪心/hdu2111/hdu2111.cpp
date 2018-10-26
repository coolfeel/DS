#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int p, m;
}baby[200];

bool cmp(node a, node b) {
    return a.p > b.p;
}

int v, n, val;

int main() {
    while (cin >> v >> n && v) {
        val = 0;
        for (int i = 0; i < n; i++)
           cin >> baby[i].p >> baby[i].m;
        sort(baby, baby + n, cmp);
        for (int i = 0; i < n; i++) {
            if (v >= baby[i].m) {
                val += baby[i].p * baby[i].m;
                v -= baby[i].m;
                baby[i].m = 0;
            } else {
                val += baby[i].p * v;
                baby[i]. m -= v;
                break;
            }
        }
        cout << val << endl;
    }
    return 0;
}
