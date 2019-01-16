//
// Created by coolrp on 1/16/19.
//
//
//约瑟夫环,相当于环形结构报数除掉元素


#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, m, mark[301], res[301], cnt, temp;
    while (scanf("%d%d", &n, &m) != EOF) {
        cnt = 0;
        memset(mark, 0, sizeof(mark));
        //考虑特殊情况
        if (n == 1 || m == 1)
            printf("%d\n", n);
        if (!n && !m)
            break;
        //记数,每m步踢掉一个
        temp = 0;
        for (int i = 1; ; i++) {
            if (cnt == (n - 1))
                break;
            if (!mark[i]) {
                temp++;
                if (temp == m) {
                    temp = 0;
                    mark[i] = 1;
                    //踢掉后的存起来,可判循环结束,还可以直接判最后剩下谁
                    res[cnt++] = i;
                }
            }
            //环形回来
            if (i % n == 0)
                i = 0;
        }
        for (int i = 1; i < n; i++)
            if (!mark[i])
                printf("%d\n", i);
    }
    return 0;
}