#include <iostream>
#include <cmath>
using namespace std;

struct Fraction {
    int up, down;
};

int gcd(int a, int b) {  //最大公约数
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0)
        result.down = 1;
    else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}


Fraction add(Fraction f1, Fraction f2) {  //加法
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}


Fraction minu(Fraction f1, Fraction f2) {  //减法
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}


Fraction divide(Fraction f1, Fraction f2) { //除法
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}


void showResult(Fraction r) {
    Fraction res;
    res = reduction(r);
    if (res.down == 1)
        cout << res.up << endl;
    else if (fabs(res.up) > res.down)
        cout << res.up / res.down << r.down << endl;
    else
        cout << res.up << res.down << endl;
}



int main() {
    Fraction a, b, res;
    cin >> a.up >> a.down >> b.up >> b.down;
    res = add(a, b);
    showResult(res);
    return 0;
}
