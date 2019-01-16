#include <cstdio>

int main() {
    int nCases, nFeets;
    while (scanf("%d", &nCases) != EOF) {
        for (int i = 0; i < nCases; i++) {
            scanf("%d", &nFeets);
            //找最多的动物数目时，尽量把脚都看成是鸡的脚
            //能被4整除，可以全是兔，我们可以找到最大的兔的数目
            if (nFeets % 4 == 0)
                printf("%d %d\n", nFeets / 4, nFeets / 2);
            //否则的话不能全是兔，至少有1个鸡
            else if (nFeets % 2 == 0)
                printf("%d %d\n", (nFeets - 2) / 4 + 1, nFeets / 2);
            else
                printf("0 0\n");
        }
    }
    return 0;
}
