#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int a, b, t;
    while (cin >> t) {
        while (t--) {
            while (cin >> a >> b)
            cout << gcd(a, b) << ' ' << a / gcd(a, b) * b << endl;
        }
    }
    return 0;
}
