//
// Created by coolrp on 1/14/19.
//
//2个数的和为定值S,二者之差越小,则乘积越大
//此题需要反复判断数字是否为质数，如果写一个函数用以判断数字是否为质数，
// 假设有M个数字待判断，那么M次判断都要花费判断质数的函数开销。
// 在参考代码中初始用一个bool数组isPrime[]表示数字i是否为质数，
// 若是质数则isPrime[i]=1,否则isPrime[i]=0，而初始化isPrime[]数组的函数只运行了1次，
// 后续每次判断一个数字是否为质数只需要O(1)的时间，仅需要取得isPrime[]的值就可以了.

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 10009;
bool isPrime[MAXN];

void initPrime() {
    for (int i = 0; i < MAXN; i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (isPrime[i])
            //消去质数的倍数,2倍起步, 不断加i就相当于3,4,,倍
            for (int j = i * 2; j < MAXN; j += i)
                isPrime[j] = false;
    }
}


int main() {
    initPrime();
    int S, x, y;
    scanf("%d", &S);
    if (S % 2 == 0) {
        x = y = S / 2;
        //只要有1个不是质数就不行
        while (!isPrime[x] || !isPrime[y]) {
            x++;
            y--;
        }
        printf("%d\n", x * y);
    } else
        //S是奇数只可能是偶数加奇数,而质数中只有2是偶数
        printf("%d\n", 2 * (S - 2));
    return 0;
}