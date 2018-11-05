#include <iostream>
using namespace std;


//欧几里德算法
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        sum += gcd(i, n);
    cout << sum << endl;
    return 0;
}
