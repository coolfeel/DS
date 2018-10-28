#include <iostream>
#include <math.h>
using namespace std;

//一般
bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}

//素数筛选法
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};

void Find_Prime() {
    for (int i = 2; i < maxn; i++) {  //除了开始的2需要事先确定，之后直接加倍数去值
        if (p[i] == false) {
            prime[pNum++] = i;        //找到筛选完后仍为false的值存起来，就是素数
            for (int j = i + i; j < maxn; j += i) //加倍数
                p[j] = true;
        }
    }
}





int main() {
    int x, y;
    while (cin >> x >> y && (x || y)) {
        int flag = 0;
        for (int i = x; i <= y; i++)
            if (!isPrime(i * i + i + 41))
                flag = 1;
        if (flag)
            cout << "Sorry" << endl;
        else
            cout << "OK" << endl;
    }
    return 0;
}
