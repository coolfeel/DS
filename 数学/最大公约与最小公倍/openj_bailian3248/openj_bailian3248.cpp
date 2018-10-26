#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)  //0和任意1个整数a的最大公约数都是a
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int a, b;
    while (cin >> a >> b)
        cout << gcd(a, b) << endl;
    return 0;
}
