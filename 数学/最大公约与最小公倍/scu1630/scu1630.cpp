#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int ary[1000000];

int main() {
    int a, b, t, res, n;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(ary, 0, sizeof(ary));
        for (int i = 0; i < n; i++)
            cin >> ary[i];
        if (n == 1) {
            cout << ary[0] << endl;
            continue;
        }
        sort(ary, ary + n);
        res = ary[0] / gcd(ary[0], ary[1]) * ary[1];
        for (int i = 2; i < n; i++)
            res = res / gcd(res, ary[i]) * ary[i];
        cout << res << endl;
    }
    return 0;
}
