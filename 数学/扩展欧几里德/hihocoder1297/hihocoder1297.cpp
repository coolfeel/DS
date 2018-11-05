#include <iostream>
using namespace std;

typedef long long LL;


//欧几里德
//LL gcd(LL a, LL b) {
//    if (b == 0)
//        return a;
//    else
//        return gcd(b, a % b);
//}

//扩展欧几里德
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL g = exgcd(b, a % b, x, y);
    LL tmp = x;
    x = y;     //更新x的值为y
    y = tmp - a / b * y;  //更新y的值，y = x(old) - a / b * y(old)
    return g;  //gcd
}




int main() {
    LL s1, s2, v1, v2, m;
    cin >> s1 >> s2 >> v1 >> v2 >> m;
        LL a = v1 - v2;
        LL b = m;
        LL c = s2 - s1;
        if (a < 0) {
            a = -a;
            c = -c;
        }
        LL xr, yr;
        LL g = exgcd(a, b, xr, yr);
        if (c % g){
            cout << -1 << endl;
            return 0;
        }
        long long k = b / g;
        xr = xr * (c / g);
        cout << (xr % k + k) % k << endl;
    return 0;
}
