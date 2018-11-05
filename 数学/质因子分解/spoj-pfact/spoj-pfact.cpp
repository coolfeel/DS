#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 100010;
int prime[maxn], pNum = 0;
int p[maxn] = {0};



//质因子及其个数
struct factor {
    int x, cnt;
}fac[10];

//判别素数
bool is_prime(int n) {
    if (n == 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}


int main() {
    for (int i = 2; i < maxn; i++) //求素数表
        if (p[i] == 0) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) //加倍数
                p[j] = 1;
        }
    for (int i = 2; i <= 100000; i++) {
        printf("%d: ", i);
        int n = i;
        int num = 0;
        int sqr = (int)sqrt(1.0 * n);
        for (int i = 0; i < pNum && prime[i] <= sqr; i++) {   //枚举根号以内的质因子
            if (n % prime[i] == 0) {
                fac[num].x = prime[i];
                while (n % prime[i] == 0)  //计算该质因子的个数
                    n /= prime[i];
                num++;
            }
            if (n == 1)
                break;
        }
        if (n != 1)
            fac[num++].x = n;
        for (int i = 0; i < num; i++)
            printf("%d ",fac[i].x);
        printf("\n");
    }
    return 0;
}
