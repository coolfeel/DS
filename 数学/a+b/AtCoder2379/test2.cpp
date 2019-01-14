//
// Created by coolrp on 1/14/19.
//
//题面虽然说是长度的组合，但实际并不需要计算组合数。抽象成数学表述就是，
// 当N>1的情形，有N个整数，这N个整数均属于区间[A,B]，那么这N个数的和的最小可能是A+A+...+A+B=(N-1)A+B，
// 最大可能是A+B+B+...+B=A+(N-1)B.而除了A和B不能变
//计算的结果就是[(N-1)A+B,A+(N-1)B]之间整数的个数
//即((N-1)B+A)+1-((N-1)A+B)=(B-A)(N-2)+1
//其它情况N=1时A=B就输出1,此时只能拼成长为A+B的竹竿.其它如A>B，或N=1时A不等于B,均输出0

#include <cstdio>

typedef long long ll;

int main() {
    int A, B, N;
    scanf("%d%d%d", &N, &A, &B);
    if (N == 1) {
        if (A == B)
            printf("1\n");
        else
            printf("0\n");
    } else {
        if (A > B)
            printf("0\n");
        else
            printf("%lld\n", (ll)(B - A) * (N - 2) + 1);
    }
    return 0;
}