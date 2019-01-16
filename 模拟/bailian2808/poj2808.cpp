//
// Created by coolrp on 1/15/19.
//
//mark标记类似,时间复杂度O(mn),由O(M * high) + O(L)得到

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int L, M, road[10001], low, high, cnt;
    cnt = 0;
    scanf("%d%d", &L, &M);
    memset(road, 0, sizeof(road));
    //将移走的做标记
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &low, &high);
        for (int j = low; j <= high; j++)
            road[j] = 1;
    }
    //记数,没做标记的
    for (int i = 0; i <= L; i++) {
        if (!road[i])
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}